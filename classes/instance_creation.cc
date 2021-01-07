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
    a_ = 0.0;
    b_ = 0.0;
    std::cout << "Default constructor has been called" << std::endl;
  }

  SomeClass(int a) {           /// Custom constructor
    a_ = a;
    b_ = 0.0;
    std::cout << "Custom constructor 1 has been called" << std::endl;
  }

  SomeClass(int a, float b) { /// Custom constructor
    a_ = a;
    b_ = b;
    std::cout << "Custom constructor 2 has been called" << std::endl;
  }

  ~SomeClass() {               /// Destructor
    std::cout << "Destructor has been called" << std::endl;
    return;
  }
 private:
  float a_{0.0};               /// Because of in-place initialization
  float b_{0.0};               /// Default constructor is not needed
};

// How to use them?
int main () {
  SomeClass var_1;               /// Default constructor
  SomeClass var_2(10);           /// Custom constructor
  // Type is checked when using {} braces. Use them!
  SomeClass var_3{10};          /// Custom constructor
  SomeClass var_4 = {10};        /// Same as var_3
  SomeClass var_5{10, 10.0};     /// Custom constructor
  SomeClass var_6 = {10, 10.0};  /// Same as var_5
  return 0;
}
