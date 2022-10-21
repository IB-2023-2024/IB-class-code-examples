/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 21 2021
 * @brief Reference Example
 * @see https://www.learncpp.com/cpp-tutorial/references/
 *      https://mayankj08.github.io/2017/08/20/References-In-C++/
 */

#include <iostream>
#include <cassert>

int main() {
  // DISCLAIMIER: Take into account that identifiers should always be meaningful
  //              The use of identifiers with a single character (i, p, etc.) is a Bad Practice
  //              Here we use such identifiers for the sake of simplicity and to relate this code
  //              with the slides used in the classes
  
  int i{42};
  int& j = i; // In this context, & does not mean “address of”, it means “reference to”.

  // std::cout << i << '\n'; // print the value of i
  std::cout << j << '\n'; // print the value of the reference

  assert(j == 42);  // If the assertion is not true, it will halt the program

  return 0;
}
