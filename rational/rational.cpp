#include "rational.h"

void Rational::Reduce() {
  int32_t gcd = std::gcd(numerator_, denominator_);
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
Rational::Rational(int32_t num) : numerator_(num), denominator_(1) {
}

// Конструктор с параметрами
Rational::Rational(int32_t num, int32_t den) : numerator_(num), denominator_(den) {
  if (denominator_ == 0) {
    throw RationalDivisionByZero{};
    Reduce();
  }
}
// Деструктор
Rational::~Rational() {
}

int32_t Rational::GetNumerator() const {
  return numerator_;
}
int32_t Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int32_t num) {
  numerator_ = num;
  Reduce();
}

void Rational::SetDenominator(int32_t den) {
  if (denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  denominator_ = den;
  Reduce();
}

Rational Rational::operator+(const Rational &other) const {
  int32_t new_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
  int32_t new_denominator = denominator_ * other.denominator_;
  return Rational(new_numerator, new_denominator);
}
Rational Rational::operator-(const Rational &other) const {
  int32_t new_numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
  int32_t new_denominator = denominator_ * other.denominator_;
  return Rational(new_numerator, new_denominator);
}

Rational Rational::operator*(const Rational &other) const {
  int32_t new_numerator = numerator_ * other.numerator_;
  int32_t new_denominator = denominator_ * other.denominator_;
  return Rational(new_numerator, new_denominator);
}

Rational Rational::operator/(const Rational &other) const {
  if (other.numerator_ == 0) {
    throw RationalDivisionByZero{};
  }
  int32_t new_numerator = numerator_ * other.denominator_;
  int32_t new_denominator = denominator_ * other.numerator_;
  return Rational(new_numerator, new_denominator);
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

Rational Rational::operator+() const {
  return *this;
}
Rational Rational::operator-() const {
  return Rational(-numerator_, denominator_);
}

Rational &Rational::operator++() {
  numerator_ += denominator_;
  return *this;
}
Rational Rational::operator++(int32_t) {
  Rational temp = *this;
  ++(*this);
  return temp;
}

Rational &Rational::operator--() {
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator--(int32_t) {
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

std::ostream &operator<<(std::ostream &os, const Rational &rational) {
  os << rational.numerator_;
  if (rational.denominator_ != 1) {
    os << "/" << rational.denominator_;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Rational &rational) {
  int32_t num, den = 1;
  char sep;

  is >> num;
  if (is.peek() == '/') {
    is >> sep >> den;
  }
  rational = Rational(num, den);
  return is;
}