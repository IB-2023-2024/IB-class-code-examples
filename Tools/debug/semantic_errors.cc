/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Sample code to illustrate semantic errors
 *
 * @see https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
 */

#include <iostream>
 
int main() {
  int a {10};
  int b {0};
  std::cout << a << " / " << b << " = " << a / b; // division by 0 is undefined
  return 0;
}
