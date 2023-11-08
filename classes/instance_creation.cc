/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief Many ways to create instances
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#default_constructor
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#destructor
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 */

#include <iostream>

class SomeClass {
 public:
  SomeClass() {                /// Default constructor
    member_a_ = 0.0;
    member_b_ = 0.0;
    std::cout << "Default constructor has been called" << std::endl;
  }

  SomeClass(const int value) {           /// Custom constructor
    member_a_ = value;
    member_b_ = 0.0;
    std::cout << "Custom constructor 1 has been called" << std::endl;
  }

  SomeClass(const int value1, const double value2) { /// Custom constructor
    member_a_ = value1;
    member_b_ = value2;
    std::cout << "Custom constructor 2 has been called" << std::endl;
  }

  ~SomeClass() {               /// Destructor
    std::cout << "Destructor has been called" << std::endl;
    return;
  }
 private:
  double member_a_{0.0};       /// Because of in-place initialization
  double member_b_{0.0};       /// Default constructor is not needed
};

// How to use them?
int main() {
  SomeClass some1;               /// Default constructor
  SomeClass some2(10);           /// Custom constructor
  // Type is checked when using {} braces. Use them!
  SomeClass some3{10};          /// Custom constructor
  SomeClass some4 = {10};        /// Same as some3
  SomeClass some5{10, 10.0};     /// Custom constructor
  SomeClass some6 = {10, 10.0};  /// Same as some5
  return 0;
}
