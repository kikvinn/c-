#include "cstring.h"

// Вычисление длины строки
size_t Strlen(const char *str) {
  const char *p = str;
  while (*p != '\0') {
    p++;
  }
  return p - str;
}

// Сравнение строк
int Strcmp(const char *first, const char *second) {
  while (*first && (*first == *second)) {
    ++first;
    ++second;
  }
  return static_cast<unsigned char>(*first) - static_cast<unsigned char>(*second);
}

// Сравнение первых count символов строк
int Strncmp(const char *first, const char *second, size_t count) {
  if (!first || !second || count == 0) {
    return 0;
  }

  while (count > 0 && *first && *second) {
    if (*first != *second) {
      return static_cast<unsigned char>(*first) - static_cast<unsigned char>(*second);
    }
    ++first;
    ++second;
    --count;
  }

  // Если count исчерпан или одна из строк закончилась
  if (count == 0) {
    return 0;
  }
  return static_cast<unsigned char>(*first) - static_cast<unsigned char>(*second);
}

// Копирование строки
char *Strcpy(char *dest, const char *src) {
  if (!dest || !src) {
    return dest;
  }

  char *original_dest = dest;
  while (*src) {
    *dest++ = *src++;
  }
  *dest = '\0';
  return original_dest;
}

// Копирование count символов
char *Strncpy(char *dest, const char *src, size_t count) {
  if (!dest || !src || count == 0) {
    return dest;
  }

  char *original_dest = dest;

  // Копируем count символов или до конца src
  while (count > 0 && *src) {
    *dest++ = *src++;
    --count;
  }

  // Если count больше длины src, заполняем оставшиеся нулями
  while (count > 0) {
    *dest++ = '\0';
    --count;
  }

  return original_dest;
}

// Конкатенация строк
char *Strcat(char *dest, const char *src) {
  if (!dest || !src) {
    return dest;
  }

  // Находим конец dest
  char *end = dest;
  while (*end) {
    ++end;
  }

  // Копируем src в конец dest
  while (*src) {
    *end++ = *src++;
  }
  *end = '\0';

  return dest;
}

// Конкатенация первых count символов
char *Strncat(char *dest, const char *src, size_t count) {
  char *original_dest = dest;
  while (*dest) {
    ++dest;
  }
  while (count && (*dest++ = *src++)) {
    --count;
  }
  if (count == 0) {
    *dest = '\0';
  }
  return original_dest;
}

// Поиск первого вхождения символа
const char *Strchr(const char *str, char symbol) {
  if (!str) {
    return nullptr;
  }

  while (*str) {
    if (*str == symbol) {
      return str;
    }
    ++str;
  }

  return (symbol == '\0') ? str : nullptr;
}

// Поиск последнего вхождения символа
const char *Strrchr(const char *str, char symbol) {
  if (!str) {
    return nullptr;
  }

  const char *last_found = nullptr;

  while (*str) {
    if (*str == symbol) {
      last_found = str;
    }
    ++str;
  }

  // Проверка нулевого символа
  if (symbol == '\0') {
    last_found = str;
  }

  return last_found;
}

// Количество первых символов, встречающихся в src
size_t Strspn(const char *dest, const char *src) {
  if (!dest || !src) {
    return 0;
  }

  size_t count = 0;

  while (*dest) {
    const char *check = src;
    bool found = false;

    while (*check) {
      if (*dest == *check) {
        found = true;
        break;
      }
      ++check;
    }

    if (!found) {
      break;
    }
    ++dest;
    ++count;
  }

  return count;
}

// Количество первых символов, не встречающихся в src
size_t Strcspn(const char *dest, const char *src) {
  if (!dest || !src) {
    return 0;
  }

  size_t count = 0;

  while (*dest) {
    const char *check = src;
    bool found = false;

    while (*check) {
      if (*dest == *check) {
        found = true;
        break;
      }
      ++check;
    }

    if (found) {
      break;
    }
    ++dest;
    ++count;
  }

  return count;
}

// Поиск первого символа из набора
const char *Strpbrk(const char *dest, const char *breakset) {
  if (!dest || !breakset) {
    return nullptr;
  }

  while (*dest) {
    const char *check = breakset;

    while (*check) {
      if (*dest == *check) {
        return dest;
      }
      ++check;
    }

    ++dest;
  }

  return nullptr;
}

// Поиск подстроки
const char *Strstr(const char *str, const char *pattern) {
  if (!str || !pattern) {
    return nullptr;
  }

  // Пустой паттерн всегда находится в начале строки
  if (*pattern == '\0') {
    return str;
  }

  while (*str) {
    const char *current_str = str;
    const char *current_pattern = pattern;

    // Проверяем совпадение
    while (*current_pattern && *current_str == *current_pattern) {
      ++current_str;
      ++current_pattern;
    }

    // Если паттерн полностью найден
    if (*current_pattern == '\0') {
      return str;
    }

    ++str;
  }

  return nullptr;
}