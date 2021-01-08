/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 04 Jan 2021
 * @brief Copy assignment operator
 *
 * @see https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
 */

#include <cassert>
#include <iostream>

class Fraction {
 public:
  // Default constructor
  Fraction(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {
    assert(denominator != 0);
  }

  // Copy constructor
  Fraction(const Fraction &other) : numerator_(other.numerator_), denominator_(other.denominator_) {
    // no need to check for a denominator of 0 here since other must already be a valid Fraction
    std::cout << "Copy constructor called\n"; // just to prove it works
  }

  // Overloaded assignment
  Fraction& operator= (const Fraction &other_fraction);

  friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
 private:
  int numerator_{0};
  int denominator_{1};  // Should not be 0
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
  out << f1.numerator_ << "/" << f1.denominator_;
  return out;
}

// C++ allows self-assignment
// So we need to deal (take care) with it
Fraction& Fraction::operator=(const Fraction& other_fraction) {
  // self-assignment guard
  if (this == &other_fraction)
    return *this;

  // do the copy
  numerator_ = other_fraction.numerator_; // can handle self-assignment
  denominator_ = other_fraction.denominator_; // can handle self-assignment

  // return the existing object so we can chain this operator
  return *this;
}

int main() {
  Fraction fiveThirds(5, 3);
  Fraction my_fraction;
  my_fraction = fiveThirds; // calls overloaded assignment
  std::cout << my_fraction << std::endl;

  return 0;
}
