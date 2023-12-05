/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Illustrates adding functionality to an ancestor class 
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
  int value() const { return value_; }
  void Identify() { 
    Base::Identify(); // call Base::Identify() first
    std::cout << "I am a Derived\n"; // then Identify ourselves
  }
};

int main() {
  Base base(5);
  base.Identify();
  Derived derived(7);
  derived.Identify();
  return 0;
}
