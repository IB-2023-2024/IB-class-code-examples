/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 21 2021
 * @brief Difference between pre-increment and post-increment
 *        Best practice: Strongly favor the prefix version of the increment and decrement operators, 
 *        as they are generally more performant, and you’re less likely to run into strange issues with them.
 * @see https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
 */

#include <vector>
#include <iostream>

int main() {
  int variable{5};
  int another_var = variable++; // variable is incremented to 6, copy of original variable 
                                // is evaluated to the value 5, and 5 is assigned to another_var
  std::cout << variable << ' ' << another_var << std::endl;

  variable = 10;
  another_var = ++variable;
  std::cout << variable << ' ' << another_var << std::endl;

  return 0;
}
