/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Sample code to illustrate the debugger options
 *
 * @see https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-running-and-breakpoints/
 */

#include <iostream>

void printValue(int value) {
  std::cout << value << std::endl;
}

int main() {
  printValue(5);
  printValue(6);
  printValue(7);
  return 0;
}
