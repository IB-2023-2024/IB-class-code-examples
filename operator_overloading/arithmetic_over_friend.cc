/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 10 2020
 * @brief Overloading of arithmetic operators
 *        The Cents class hold an amount of cents (money)
 *        Overloading the plus operator (+) is as simple as: 
 *         1. Declaring a function named operator+, giving it two parameters of the type of the operands we want to add
 *         2. Picking an appropriate return type
 *         3. Writing the function
 *        If you write a friend function, it can access the class members directly
 *        
 * @see https://www.learncpp.com/cpp-tutorial/92-overloading-the-arithmetic-operators-using-friend-functions/
 */

#include <iostream>

class Cents {
 public:
  Cents(const int cents) : cents_{cents} {}

  // Add Cents + Cents using a friend function
  friend Cents operator+(const Cents& c1, const Cents& c2);

  // Subtract Cents - Cents using a friend function
  friend Cents operator-(const Cents& c1, const Cents& c2);

  int cents() const { return cents_; }
 private:
  int cents_;
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2) {
  // use the Cents constructor and operator+(int, int)
  // we can access cents_ directly because this is a friend function
  return Cents(c1.cents_ + c2.cents_);
}

// note: this function is not a member function!
Cents operator-(const Cents& c1, const Cents& c2) {
  // use the Cents constructor and operator-(int, int)
  // we can access cents_ directly because this is a friend function
  return Cents(c1.cents_ - c2.cents_);
}

int main() {
  Cents cents1{6};
  Cents cents2{2};
  Cents centsSum{cents1 + cents2};
  std::cout << "I have " << centsSum.cents() << " cents.\n";
  return 0;
}
