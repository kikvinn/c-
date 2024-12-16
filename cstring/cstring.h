#pragma once
#include <cstddef>  // для size_t

// Вычисление длины строки
size_t Strlen(const char *str);

// Сравнение строк
int Strcmp(const char *first, const char *second);

// Сравнение первых count символов строк
int Strncmp(const char *first, const char *second, size_t count);

// Копирование строки
char *Strcpy(char *dest, const char *src);

// Копирование count символов
char *Strncpy(char *dest, const char *src, size_t count);

// Конкатенация строк
char *Strcat(char *dest, const char *src);

// Конкатенация первых count символов
char *Strncat(char *dest, const char *src, size_t count);

// Поиск первого вхождения символа
const char *Strchr(const char *str, char symbol);

// Поиск последнего вхождения символа
const char *Strrchr(const char *str, char symbol);

// Количество первых символов, встречающихся в src
size_t Strspn(const char *dest, const char *src);

// Количество первых символов, не встречающихся в src
size_t Strcspn(const char *dest, const char *src);

// Поиск первого символа из набора
const char *Strpbrk(const char *dest, const char *breakset);

// Поиск подстроки
const char *Strstr(const char *str, const char *pattern);