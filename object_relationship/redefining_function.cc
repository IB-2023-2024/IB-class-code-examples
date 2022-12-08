/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates redefining a function in a derived class 
 *        To modify the way a function defined in a base class 
 *        works in the derived class, simply redefine the function in the derived class
 *
 * @see https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
 */

#include <iostream>

class Base {
 public:
  Base(int value) : value_(value) { }
  void Identify() { std::cout << "I am a Base\n"; }
 protected:
  int value_;
};

class Derived: public Base {
 public:
  Derived(int value) : Base(value) { }
  int value() { return value_; }
  // Here's our modified function
  void Identify() { std::cout << "I am a Derived\n"; }
};

int main() {
  Base base(5);
  base.Identify();
  Derived derived(7);
  derived.Identify();
  return 0;
}
