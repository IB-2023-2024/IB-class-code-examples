/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Illustrates Changing an inherited member’s access level
 *        C++ gives us the ability to change an inherited member’s 
 *        access specifier in the derived class.
 *        This is done by using a using declaration to identify the (scoped) 
 *        base class member that is having its access changed in the derived 
 *        class, under the new access specifier.
 *
 *        You can only change the access specifiers of base members the derived 
 *        class would normally be able to access. 
 *        Therefore, you can never change the access specifier of a base member 
 *        from private to protected or public, because derived classes do not have 
 *        access to private members of the base class.
 *
 * @see https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
 */

#include <iostream>

class Base {
 public:
  Base(int value) : value_(value) { }
 protected:
  void PrintValue() { std::cout << value_ << std::endl; }
 private:
  int value_;
};

/**
 * Because Base::PrintValue() has been declared as protected, 
 * it can only be called by Base or its derived classes. 
 * The public can not access it.
 * Let’s define a Derived class that changes the access specifier of PrintValue() to public:
 */
class Derived: public Base {
 public:
  Derived(int value) : Base(value) {}

  // Base::PrintValue was inherited as protected, so the public has no access
  // But we're changing it to public via a using declaration
  using Base::PrintValue;  // note: no parenthesis here
};

int main() {
  Derived derived(7);
  // PrintValue is public in Derived, so this is okay
  derived.PrintValue();  // prints 7
  return 0;
}
