/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates calling a base function from a derived class
 *        When derived.Identify() is called, the compiler looks to 
 *        see if function Identify() has been defined in the Derived class. 
 *        It hasn’t. 
 *        Then it starts looking in the inherited classes (which in this case is Base). 
 *        Base has defined an Identify() function, so it uses that one. 
 *        In other words, Base::Identify() was used because Derived::Identify() doesn’t exist.
 *        This means that if the behavior provided by a base class is sufficient, 
 *        we can simply use the base class behavior.
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
};

int main() {
  Base base(5);
  base.Identify();
  Derived derived(7);
  derived.Identify();
  return 0;
}
