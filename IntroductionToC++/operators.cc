/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 16 2022
 * @brief Operations with with simple types
 * @see https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
 */

#include <iostream>

int main() {
  int variable{7};     // Declaration of 2 variables
  int another_var{5};

  // Operations with int:
  std::cout << "Integers (in):" << std::endl;
  std::cout << "sizeof(int): " << sizeof(int) << std::endl;

  std::cout << variable << " + " << another_var << " = " << variable + another_var << std::endl;
  std::cout << variable << " - " << another_var << " = " << variable - another_var << std::endl;
  std::cout << variable << " * " << another_var << " = " << variable * another_var << std::endl;
  std::cout << variable << " / " << another_var << " = " << variable / another_var << std::endl;
  std::cout << variable << " % " << another_var << " = " << variable % another_var << std::endl;

  double variable1{7.0};
  double variable2{5.0};
  // Operations with double:
  std::cout << "Real numbers (double):" << std::endl;
  std::cout << "sizeof(double): " << sizeof(double) << std::endl;
  std::cout << variable1 << " + " << variable2 << " = " << variable1 + variable2 << std::endl;
  std::cout << variable1 << " - " << variable2 << " = " << variable1 - variable2 << std::endl;
  std::cout << variable1 << " * " << variable2 << " = " << variable1 * variable2 << std::endl;
  std::cout << variable1 << " / " << variable2 << " = " << variable1 / variable2 << std::endl;

  return 0;
}
