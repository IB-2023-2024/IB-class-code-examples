/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Nov 8 2023
 * @brief Members in a class can be initialized in different ways
 *        * If a member is listed in the member initializer list, that initialization value is used
 *        * Otherwise, if the member has a default member initializer, that initialization value is used
 *        * Otherwise, the member is default initialized.
 *        This means that if a member has both a default member initializer and is listed in the member 
 *        initializer list for the constructor, the member initializer list value takes precedence.
 *
 * @see https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
 */

#include <iostream>

class Foo {
 public:
  Foo(int value) : memberx_{value} { // member initializer list
    std::cout << "Foo constructed\n";
  }

  void Print() const {
    std::cout << "Foo(" << memberx_ << ", " << membery_ << ", " << memberz_ << ")\n";
  }
 private:
  int memberx_{};  // default member initializer (will be ignored)
  int membery_{2}; // default member initializer (will be used)
  int memberz_;    // no initializer (Avoid this!!!)
};

int main() {
  Foo foo{6};
  foo.Print();
  return 0;
}
