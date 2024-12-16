#pragma once

#include <iostream>
#include <numeric>
#include <stdexcept>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("Деление на 0 дурень") {
  }
};

// Класс для работы с рациональными числами
class Rational {
 private:
  int numerator_;    // Числитель
  int denominator_;  // Дробитель

  // Метод для упрощения ненулевого дроби
  void Reduce();

 public:
  // Конструкторы
  Rational();                                // NOLINT
  Rational(int num);                         // NOLINT
  Rational(int numerator, int denominator);  // NOLINT

  // Деструктор для освобождения ресурсов
  ~Rational();

  // Получение числа в виде целого числа (результат целочисленной деления)
  int GetNumerator() const;

  // Получение знаменателя рационального числа
  int GetDenominator() const;

  // Установка числа в виде целого числа
  void SetNumerator(int num);

  // Установка знаменаталя для числа
  void SetDenominator(int den);

  // Копирующий конструктор
  Rational(const Rational &other);

  Rational &operator=(const Rational &other);

  Rational &operator=(const int num);

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
  Rational operator++(int);
  // Декремент
  Rational &operator--();
  Rational operator--(int);
  // Операторы сравнения для равенства, неравенства, меньшей и большей, и равности или больших
  bool operator==(const Rational &other) const;
  bool operator!=(const Rational &other) const;
  bool operator<(const Rational &other) const;
  bool operator>(const Rational &other) const;
  bool operator<=(const Rational &other) const;
  bool operator>=(const Rational &other) const;

  bool operator==(int value) const;
  bool operator!=(int value) const;
  bool operator<(int value) const;
  bool operator>(int value) const;
  bool operator<=(int value) const;
  bool operator>=(int value) const;

  friend bool operator<(const int &num, const Rational &rat);
  friend bool operator>(const int &num, const Rational &rat);
  friend bool operator<=(const int &num, const Rational &rat);
  friend bool operator>=(const int &num, const Rational &rat);
  friend bool operator==(const int &num, const Rational &rat);
  friend bool operator!=(const int &num, const Rational &rat);

  // Функция вывода в поток
  friend std::ostream &operator<<(std::ostream &os, const Rational &rational);

  // Функция ввода из потока
  friend std::istream &operator>>(std::istream &is, Rational &rational);
};