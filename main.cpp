#include "./rational/rational.h"
#include <iostream>

int main() {
  Rational x = 5;
  std::cout << "x: " << x << std::endl;
  x.SetDenominator(15);
  std::cout << "x: " << x << std::endl;
  std::cin >> x;
  std::cout << "x: " << x << std::endl;

  return 0;
}