/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates adding functionality to an ancestor class 
 *        
 *
 * @see https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
 */

#include <iostream>

class Base {
 public:
  Base(int value) : value_(value) {
  }

  void identify() { std::cout << "I am a Base\n"; }
 protected:
  int value_;
};

class Derived: public Base {
 public:
  Derived(int value) : Base(value) {
  }

  int value() { return value_; }

  void identify() { 
		Base::identify(); // call Base::identify() first
    std::cout << "I am a Derived\n"; // then identify ourselves
	}
};

int main() {
  Base base(5);
  base.identify();

  Derived derived(7);
  derived.identify();

  return 0;
}
