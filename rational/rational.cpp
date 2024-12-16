#include "rational.h"

void Rational::Reduce() {
  int gcd = std::gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;

  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  }
}

// Конструктор по умолчанию
Rational::Rational() : numerator_(0), denominator_(1) {
}

// Коснструктор от целого числа
Rational::Rational(int num) : numerator_(num), denominator_(1) {
}

// Конструктор с параметрами
Rational::Rational(int num, int den) : numerator_(num), denominator_(den) {
  if (denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  Reduce();
}

Rational::Rational(const Rational &other) = default;

// Деструктор
Rational::~Rational() = default;

int Rational::GetNumerator() const {
  return numerator_;
}
int Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int num) {
  numerator_ = num;
  Reduce();
}

void Rational::SetDenominator(int den) {
  if (denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  denominator_ = den;
  Reduce();
}

Rational Rational::operator+(const Rational &other) const {
  int new_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
  int new_denominator = denominator_ * other.denominator_;
  return {new_numerator, new_denominator};
}
Rational Rational::operator-(const Rational &other) const {
  int new_numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
  int new_denominator = denominator_ * other.denominator_;
  return {new_numerator, new_denominator};
}

Rational Rational::operator*(const Rational &other) const {
  int new_numerator = numerator_ * other.numerator_;
  int new_denominator = denominator_ * other.denominator_;
  return {new_numerator, new_denominator};
}

Rational Rational::operator/(const Rational &other) const {
  if (other.numerator_ == 0) {
    throw RationalDivisionByZero{};
  }
  int new_numerator = numerator_ * other.denominator_;
  int new_denominator = denominator_ * other.numerator_;
  return {new_numerator, new_denominator};
}

Rational &Rational::operator=(const Rational &other) {
  if (&other != this) {
    this->numerator_ = other.numerator_;
    this->denominator_ = other.denominator_;
  }
  return *this;
}

Rational &Rational::operator=(const int num) {
  numerator_ = num;
  denominator_ = 1;
  return *this;
}

Rational &Rational::operator+=(const Rational &other) {
  *this = *this + other;
  return *this;
}
Rational &Rational::operator-=(const Rational &other) {
  *this = *this - other;
  return *this;
}
Rational &Rational::operator*=(const Rational &other) {
  *this = *this * other;
  return *this;
}
Rational &Rational::operator/=(const Rational &other) {
  *this = *this / other;
  return *this;
}
Rational Rational::operator+() const {
  return *this;
}
Rational Rational::operator-() const {
  return {-numerator_, denominator_};
}

Rational &Rational::operator++() {
  numerator_ += denominator_;
  return *this;
}
Rational Rational::operator++(int) {
  Rational temp = *this;
  ++(*this);
  return temp;
}

Rational &Rational::operator--() {
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator--(int) {
  Rational temp = *this;
  --(*this);
  return temp;
}

bool Rational::operator==(const Rational &other) const {
  return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}

bool Rational::operator!=(const Rational &other) const {
  return !(*this == other);
}

bool Rational::operator<(const Rational &other) const {
  return numerator_ * other.denominator_ < other.numerator_ * denominator_;
}

bool Rational::operator<=(const Rational &other) const {
  return (*this < other) || (*this == other);
}
bool Rational::operator>(const Rational &other) const {
  return !(*this <= other);
}

bool Rational::operator>=(const Rational &other) const {
  return (*this > other) || (*this == other);
}

bool Rational::operator<(int value) const {
  return numerator_ < value * denominator_;
}

bool Rational::operator<=(int value) const {
  return numerator_ <= value * denominator_;
}

bool Rational::operator>(int value) const {
  return numerator_ > value * denominator_;
}

bool Rational::operator>=(int value) const {
  return numerator_ >= value * denominator_;
}

bool Rational::operator==(int value) const {
  return numerator_ == value * denominator_;
}

bool Rational::operator!=(int value) const {
  return numerator_ != value * denominator_;
}

bool operator<(const int &num, const Rational &rat) {
  return rat.GetDenominator() * num < rat.GetNumerator();
}

bool operator>(const int &num, const Rational &rat) {
  return rat.GetNumerator() * num < rat.GetDenominator();
}

bool operator<=(const int &num, const Rational &rat) {
  return rat.GetDenominator() * num <= rat.GetNumerator();
}

bool operator>=(const int &num, const Rational &rat) {
  return rat.GetNumerator() * num >= rat.GetDenominator();
}

bool operator==(const int &num, const Rational &rat) {
  return (rat.GetDenominator() * num == rat.GetNumerator());
}

bool operator!=(const int &num, const Rational &rat) {
  return (rat.GetDenominator() * num != rat.GetNumerator());
}

std::ostream &operator<<(std::ostream &os, const Rational &rational) {
  os << rational.numerator_;
  if (rational.denominator_ != 1) {
    os << "/" << rational.denominator_;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Rational &rational) {
  int num = 0;
  int den = 1;
  char sep = 0;

  is >> num;
  if (is.peek() == '/') {
    is >> sep >> den;
  }
  rational = Rational(num, den);
  return is;
}