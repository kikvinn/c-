#pragma once

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <stdint.h>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("Деление на 0 дурень") {
  }
};

// Класс для работы с рациональными числами
class Rational {
 private:
  int32_t numerator_;    // Числитель
  int32_t denominator_;  // Дробитель

  // Метод для упрощения ненулевого дроби
  void Reduce();

 public:
  // Конструкторы
  Rational();  // Пустой конструктор, по умолчанию numerator и denominator равно 0
  Rational(int32_t value);  // Конструктор с одним аргументом, создает объект Rational с числом value и дробью 1
  Rational(int32_t numerator, int32_t denominator);  // Конструктор с двумя аргументами, создает объект Rational с
                                                     // заданными числителем и знаменателем

  // Деструктор для освобождения ресурсов
  ~Rational();

  // Получение числа в виде целого числа (результат целочисленной деления)
  int32_t GetNumerator() const;

  // Получение знаменателя рационального числа
  int32_t GetDenominator() const;

  // Установка числа в виде целого числа
  void SetNumerator(int32_t num);

  // Установка знаменаталя для числа
  void SetDenominator(int32_t den);

  // Сумма двух рациональных чисел
  Rational operator+(const Rational &other) const;

  // Разность двух рациональных чисел
  Rational operator-(const Rational &other) const;

  // Произведение двух рациональных чисел
  Rational operator*(const Rational &other) const;

  // Целочисленное деление (сокращённое)
  Rational operator/(const Rational &other) const;

  // Добавление текущего объекта с другим объектом
  Rational &operator+=(const Rational &other);

  // Вычитание текущего объекта от другого объекта
  Rational &operator-=(const Rational &other);

  // Умножение текущего объекта на другого объекта
  Rational &operator*=(const Rational &other);

  // Деление текущего объекта на другого объекта с целочисленным делением
  Rational &operator/=(const Rational &other);

  // Инверсия числа (умножение на -1)
  Rational operator+() const;

  // Инверсия числа (умножение на -1)
  Rational operator-() const;

  // Инкремент
  Rational &operator++();
  Rational operator++(int32_t);
  // Декремент
  Rational &operator--();
  Rational operator--(int32_t);
  // Операторы сравнения для равенства, неравенства, меньшей и большей, и равности или больших
  bool operator==(const Rational &other) const;
  bool operator!=(const Rational &other) const;
  bool operator<(const Rational &other) const;
  bool operator>(const Rational &other) const;
  bool operator<=(const Rational &other) const;
  bool operator>=(const Rational &other) const;

  // Функция вывода в поток
  friend std::ostream &operator<<(std::ostream &os, const Rational &rational);

  // Функция ввода из потока
  friend std::istream &operator>>(std::istream &is, Rational &rational);
};