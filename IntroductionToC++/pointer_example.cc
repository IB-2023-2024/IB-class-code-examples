/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 21 2021
 * @brief Pointer Example
 * @see https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
 */

#include <iostream>
#include <cassert>

int main() {
  // DISCLAIMIER: Take into account that identifiers should always be meaningful
  //              The use of identifiers with a single character (i, p, etc.) is a Bad Practice
  //              Here we use such identifiers for the sake of simplicity and to relate this code
  //              with the slides used in the classes
  
  int i{42};
  std::cout << i << '\n'; // print the value of variable i
  std::cout << &i << '\n'; // print the memory address of variable i

  int* p = &i;  // pointer p points to variable i
  std::cout << *p << '\n'; /// print the value at the memory address of variable i (pointed by p)

  assert(*p == 42);  // If the assertion is not true, it will halt the program

  return 0;
}
