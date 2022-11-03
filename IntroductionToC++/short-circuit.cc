/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 22 2021
 * @brief Short Circuit evaluation
 *        Warning: Short circuit evaluation may cause Logical OR and Logical AND to 
 *        not evaluate one operand. 
 *        Avoid using expressions with side effects in conjunction with these operators.
 * @see https://www.learncpp.com/cpp-tutorial/logical-operators/
 */

#include <vector>
#include <iostream>

using namespace std;

int main() {
  int variable{0};

  // First example:
  // The second term of the expression is not executed and therefore variable is not incremented.
  bool expression = (variable == 0 || ++variable == 1);
  std::cout << "expression: " << expression << " variable: " << variable << std::endl;

  // Second example:
  int var1{0};
  int var2{1};
  if (var1 == 1 && ++var2 == 2) {
    std::cout << var1 << " " << var2;
  }
  std::cout << "var2: " << var2 << std::endl;
  return 0;
}
