# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
# На Windows уберите -DCOLOR_OUTPUT если цвета не работают
DEFINES = -DCOLOR_OUTPUT

# Директории
SRC_DIR = .
BUILD_DIR = ../../build

# Исходные файлы
SRCS = $(SRC_DIR)/s21_string.c \
       $(SRC_DIR)/s21_string_test.c

# Объектные файлы
OBJS = $(SRCS:.c=.o)

# Заголовочные файлы
INCLUDES = -I$(SRC_DIR)

# Исполняемый файл
TARGET = $(BUILD_DIR)/Quest_6

# Основная цель
all: $(BUILD_DIR) $(TARGET)

# Цель для тестов
strlen_tests: $(BUILD_DIR) $(TARGET)
	@echo "Running strlen tests..."
	@$(TARGET)

# Создание директории build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Линковка
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Компиляция
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(BUILD_DIR)

# Пересборка
rebuild: clean all

# Запуск тестов
test: strlen_tests

# Псевдо-цели
.PHONY: all clean rebuild test strlen_tests

# Для Windows (если нет mkdir)
ifeq ($(OS),Windows_NT)
    RM = del /Q
    RMDIR = rmdir /S /Q
    MKDIR = mkdir
else
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p
endif