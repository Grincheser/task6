#ifndef S21_STRING_H
#define S21_STRING_H

/**
 * @brief Вычисляет длину строки (без учёта завершающего нулевого символа)
 * @param str Указатель на строку
 * @return Количество символов до первого нулевого символа
 */
unsigned long long s21_strlen(const char *str);

#endif