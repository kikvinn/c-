#include <gtest/gtest.h>
#include "rational.h"

// Тест оператора присваивания
TEST(RationalTest, OperatorAssignment) {
  Rational r(4, 5);
  Rational s(2, 3);
  r = s;
  EXPECT_EQ(r.GetNumerator(), 2);
  EXPECT_EQ(r.GetDenominator(), 3);

  Rational t(-1, 6);
  Rational u(1, -7);
  t = u;
  EXPECT_EQ(t.GetNumerator(), 1);
  EXPECT_EQ(t.GetDenominator(), 42);
}

// Тест оператора присваивания целого числа
TEST(RationalTest, OperatorAssignInt) {
  Rational r(3, 4);
  r = 5;
  EXPECT_EQ(r.GetNumerator(), 5);
  EXPECT_EQ(r.GetDenominator(), 1);

  Rational t(-2, 7);
  t = -6;
  EXPECT_EQ(t.GetNumerator(), -6);
  EXPECT_EQ(t.GetDenominator(), 1);
}

// Тест операторов +=, -=, *= и /= 
TEST(RationalTest, OperatorsPlusEquals) {
  Rational r(2, 3);
  Rational s(1, 4);
  r += s;
  EXPECT_EQ(r.GetNumerator(), 11);
  EXPECT_EQ(r.GetDenominator(), 12);

  Rational t(-5, 6);
  Rational u(2, -7);
  t -= u;
  EXPECT_EQ(t.GetNumerator(), 34);
  EXPECT_EQ(t.GetDenominator(), 42);
}

TEST(RationalTest, OperatorsMinusEquals) {
  Rational r(4, 5);
  Rational s(1, 6);
  r -= s;
  EXPECT_EQ(r.GetNumerator(), 23);
  EXPECT_EQ(r.GetDenominator(), 30);

  Rational t(-7, 8);
  Rational u(2, -9);
  t += u;
  EXPECT_EQ(t.GetNumerator(), -14);
  EXPECT_EQ(t.GetDenominator(), 56);
}

TEST(RationalTest, OperatorsMultiplyEquals) {
  Rational r(3, 4);
  Rational s(2, 3);
  r *= s;
  EXPECT_EQ(r.GetNumerator(), 1);
  EXPECT_EQ(r.GetDenominator(), 4);

  Rational t(-1, 5);
  Rational u(4, -6);
  t *= u;
  EXPECT_EQ(t.GetNumerator(), 2);
  EXPECT_EQ(t.GetDenominator(), 30);
}

TEST(RationalTest, OperatorsDivideEquals) {
  Rational r(5, 6);
  Rational s(1, 2);
  r /= s;
  EXPECT_EQ(r.GetNumerator(), 5);
  EXPECT_EQ(r.GetDenominator(), 3);

  Rational t(-7, 8);
  Rational u(2, -9);
  t /= u;
  EXPECT_EQ(t.GetNumerator(), 63);
  EXPECT_EQ(t.GetDenominator(), 16);
}

// Тест операторов ++ и --
TEST(RationalTest, OperatorsIncrement) {
  Rational r(3, 4);
  ++r;
  EXPECT_EQ(r.GetNumerator(), 7);
  EXPECT_EQ(r.GetDenominator(), 4);

  Rational t(-2, 3);
  --t;
  EXPECT_EQ(t.GetNumerator(), -5);
  EXPECT_EQ(t.GetDenominator(), 3);
}

TEST(RationalTest, OperatorsDecrement) {
  Rational r(5, 6);
  r--;
  EXPECT_EQ(r.GetNumerator(), 1);
  EXPECT_EQ(r.GetDenominator(), 6);

  Rational t(-4, 7);
  t++;
  EXPECT_EQ(t.GetNumerator(), -1);
  EXPECT_EQ(t.GetDenominator(), 7);
}

// Тест операторов ==, !=, <, <=, >, >=
TEST(RationalTest, OperatorsCompare) {
  Rational r(2, 3);
  Rational s(1, 2);
  EXPECT_TRUE(r == s);

  Rational t(-5, 6);
  Rational u(4, -7);
  EXPECT_FALSE(t != u);

  EXPECT_TRUE(r < s);
  EXPECT_TRUE(t <= u);
  EXPECT_TRUE(s > t);
  EXPECT_TRUE(u >= s);

  Rational v(10, 9);
  Rational w(11, 9);
  EXPECT_TRUE(v == w);
}

// Тест операторов == и != с целыми числами
TEST(RationalTest, OperatorsCompareInt) {
  Rational r(3, 4);
  int n = 2;
  EXPECT_FALSE(r < n);
  EXPECT_FALSE(r <= n);
  EXPECT_FALSE(n > r);
  EXPECT_FALSE(n >= r);

  Rational t(-7, 8);
  int m = -6;
  EXPECT_TRUE(t != m);
}

// Тесты ввода-вывода
TEST(RationalTest, OperatorInputOutput) {
  Rational r(3, 4);
  std::stringstream ss("3/4");
  ss >> r;
  EXPECT_EQ(r.GetNumerator(), 3);
  EXPECT_EQ(r.GetDenominator(), 4);

  std::stringstream sss("-2/7");
  sss >> r;
  EXPECT_EQ(r.GetNumerator(), -2);
  EXPECT_EQ(r.GetDenominator(), 7);

  Rational s(5, -6);
  std::stringstream ss2("5/-6");
  ss2 >> s;
  EXPECT_EQ(s.GetNumerator(), -5);
  EXPECT_EQ(s.GetDenominator(), 6);

  Rational t(-9, 10);
  std::stringstream ss3("-9/10");
  ss3 >> t;
  EXPECT_EQ(t.GetNumerator(), -9);
  EXPECT_EQ(t.GetDenominator(), 10);

  std::string s4 = "2";
  Rational u(2, 1);
  std::stringstream ss4(s4);
  ss4 >> u;
  EXPECT_EQ(u.GetNumerator(), 2);
  EXPECT_EQ(u.GetDenominator(), 1);

  Rational v(-3, 2);
  std::stringstream ss5("-3/2");
  ss5 >> v;
  EXPECT_EQ(v.GetNumerator(), -3);
  EXPECT_EQ(v.GetDenominator(), 2);

  std::string s6 = "0";
  Rational w(0, 1);
  std::stringstream ss6(s6);
  ss6 >> w;
  EXPECT_EQ(w.GetNumerator(), 0);
  EXPECT_EQ(w.GetDenominator(), 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}