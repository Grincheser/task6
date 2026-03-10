#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

// Цвета для вывода
#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"

// Структура для тестового случая
typedef struct {
    const char *input;
    unsigned long long expected;
    const char *description;
} TestCase;

// Прототипы тестовых функций
void s21_strlen_test(void);

// Функция для выполнения одного теста
int run_test(const char *input, unsigned long long expected, const char *description)
{
    unsigned long long result = s21_strlen(input);
    int success = (result == expected);
    
    printf("%sTest: %s%s\n", COLOR_BLUE, description, COLOR_RESET);
    printf("  Input:    \"%s\"\n", input ? input : "NULL");
    printf("  Expected: %llu\n", expected);
    printf("  Got:      %llu\n", result);
    printf("  Result:   %s%s%s\n\n", 
           success ? COLOR_GREEN : COLOR_RED,
           success ? "SUCCESS" : "FAIL",
           COLOR_RESET);
    
    return success;
}

void s21_strlen_test(void)
{
    printf("%s========================================%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("%s       TESTING s21_strlen FUNCTION     %s\n", COLOR_YELLOW, COLOR_RESET);
    printf("%s========================================%s\n\n", COLOR_YELLOW, COLOR_RESET);
    
    // Массив тестовых случаев
    TestCase tests[] = {
        // Нормальные значения
        {"Hello", 5, "Normal string (5 chars)"},
        {"", 0, "Empty string"},
        {"Hello, World!", 13, "String with punctuation"},
        
        // Краевые значения
        {"a", 1, "Single character"},
        {"Very long string for testing purposes........................................", 60, "Long string (60 chars)"},
        {"1234567890", 10, "Numeric string"},
        
        // Ненормальные/особые значения
        {NULL, 0, "NULL pointer"},
        {"\0", 0, "String starting with null"},
        {"Hello\0World", 5, "String with embedded null"},
        
        // Дополнительные тесты
        {"   ", 3, "String with spaces only"},
        {"\t\n\r", 3, "String with escape sequences"},
        {"Привет", 12, "UTF-8 string (6 Cyrillic chars = 12 bytes)"},
    };
    
    int total_tests = sizeof(tests) / sizeof(tests[0]);
    int passed_tests = 0;
    int failed_tests = 0;
    
    // Запуск всех тестов
    for (int i = 0; i < total_tests; i++) {
        printf("%sTest Case #%d%s\n", COLOR_YELLOW, i + 1, COLOR_RESET);
        if (run_test(tests[i].input, tests[i].expected, tests[i].description)) {
            passed_tests++;
        } else {
            failed_tests++;
        }
    }
    
    // Вывод статистики
    printf("%s========================================%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("              TEST SUMMARY\n");
    printf("%s========================================%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("Total tests:  %d\n", total_tests);
    printf("%sPassed:       %d%s\n", COLOR_GREEN, passed_tests, COLOR_RESET);
    if (failed_tests > 0) {
        printf("%sFailed:       %d%s\n", COLOR_RED, failed_tests, COLOR_RESET);
    }
    printf("%s========================================%s\n", COLOR_YELLOW, COLOR_RESET);
}

int main(void)
{
    s21_strlen_test();
    return 0;
}