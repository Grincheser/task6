#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define SPEED_STEP 5000
#define MIN_SPEED 5000
#define MAX_SPEED 100000

// Прототипы функций
void initialize_field(int field[HEIGHT][WIDTH]);
void read_initial_state(int field[HEIGHT][WIDTH]);
int count_neighbors(int field[HEIGHT][WIDTH], int y, int x);
void compute_next_generation(int current[HEIGHT][WIDTH], int next[HEIGHT][WIDTH]);
void draw_field(int field[HEIGHT][WIDTH]);
void handle_input(int *speed, int *running);
void game_loop(int field[HEIGHT][WIDTH]);

int main() {
    int field[HEIGHT][WIDTH] = {0};
    
    // Инициализация ncurses
    initscr();
    cbreak();
    noecho();
    timeout(0);  // Неблокирующий ввод
    keypad(stdscr, TRUE);
    curs_set(0);  // Скрыть курсор
    
    read_initial_state(field);
    game_loop(field);
    
    endwin();
    return 0;
}

/**
 * Чтение начального состояния из stdin
 * Ожидается: строки из 80 символов, где '1' - живая клетка, '0' - мертвая
 */
void read_initial_state(int field[HEIGHT][WIDTH]) {
    char line[WIDTH + 2];  // +2 для символов новой строки и нуль-терминатора
    int y = 0;
    
    // Читаем построчно, пока есть данные и не достигли HEIGHT
    while (y < HEIGHT && fgets(line, sizeof(line), stdin)) {
        // Удаляем символ новой строки, если есть
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        
        // Заполняем строку поля
        for (int x = 0; x < WIDTH; x++) {
            if (x < (int)len) {
                field[y][x] = (line[x] == '1') ? 1 : 0;
            } else {
                field[y][x] = 0;
            }
        }
        y++;
    }
    
    // Если файл короче HEIGHT строк, остальные заполняем нулями
    while (y < HEIGHT) {
        for (int x = 0; x < WIDTH; x++) {
            field[y][x] = 0;
        }
        y++;
    }
}

/**
 * Подсчет живых соседей для клетки (y,x) на торе
 */
int count_neighbors(int field[HEIGHT][WIDTH], int y, int x) {
    int count = 0;
    
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0) continue;
            
            // Тороидальные координаты
            int ny = (y + dy + HEIGHT) % HEIGHT;
            int nx = (x + dx + WIDTH) % WIDTH;
            
            count += field[ny][nx];
        }
    }
    
    return count;
}

/**
 * Вычисление следующего поколения
 */
void compute_next_generation(int current[HEIGHT][WIDTH], int next[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = count_neighbors(current, y, x);
            
            if (current[y][x] == 1) {
                // Живая клетка
                if (neighbors < 2 || neighbors > 3) {
                    next[y][x] = 0;  // Умирает
                } else {
                    next[y][x] = 1;  // Выживает
                }
            } else {
                // Мертвая клетка
                if (neighbors == 3) {
                    next[y][x] = 1;  // Рождается
                } else {
                    next[y][x] = 0;  // Остается мертвой
                }
            }
        }
    }
}

/**
 * Отрисовка поля в терминале
 * '█' - живая клетка, ' ' - мертвая (используем блочный символ для лучшей видимости)
 */
void draw_field(int field[HEIGHT][WIDTH]) {
    clear();
    
    // Верхняя граница
    printw("┌");
    for (int x = 0; x < WIDTH; x++) printw("─");
    printw("┐\n");
    
    // Поле
    for (int y = 0; y < HEIGHT; y++) {
        printw("│");
        for (int x = 0; x < WIDTH; x++) {
            printw("%c", field[y][x] ? '█' : ' ');
        }
        printw("│\n");
    }
    
    // Нижняя граница и информация
    printw("└");
    for (int x = 0; x < WIDTH; x++) printw("─");
    printw("┘\n");
    printw("Speed: %d µs | Space: Exit | A/Z: +/- speed\n", speed);
    printw("Generation: %d | Population: %d\n", gen, population);
    
    refresh();
}

/**
 * Обработка пользовательского ввода
 */
void handle_input(int *speed, int *running) {
    int ch = getch();
    
    switch(ch) {
        case 'a':
        case 'A':
            *speed = (*speed > MIN_SPEED) ? *speed - SPEED_STEP : MIN_SPEED;
            break;
            
        case 'z':
        case 'Z':
            *speed = (*speed < MAX_SPEED) ? *speed + SPEED_STEP : MAX_SPEED;
            break;
            
        case ' ':  // Space bar
            *running = 0;
            break;
    }
}

/**
 * Подсчет популяции
 */
int count_population(int field[HEIGHT][WIDTH]) {
    int count = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            count += field[y][x];
        }
    }
    return count;
}

/**
 * Главный игровой цикл
 */
void game_loop(int field[HEIGHT][WIDTH]) {
    int running = 1;
    int speed = MIN_SPEED + (MAX_SPEED - MIN_SPEED) / 2;  // Начальная скорость
    int generation = 0;
    
    int current[HEIGHT][WIDTH];
    int next[HEIGHT][WIDTH];
    
    // Копируем начальное поле
    memcpy(current, field, sizeof(current));
    
    while (running) {
        // Отрисовка текущего состояния
        draw_field(current, speed, generation, count_population(current));
        
        // Вычисление следующего поколения
        compute_next_generation(current, next);
        
        // Копируем следующее поколение в текущее
        memcpy(current, next, sizeof(current));
        generation++;
        
        // Обработка ввода
        handle_input(&speed, &running);
        
        // Задержка для контроля скорости
        usleep(speed);
    }
}