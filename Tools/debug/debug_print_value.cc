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

void PrintValue(int value) {
  std::cout << value << std::endl;
}

int main() {
  PrintValue(5);
  PrintValue(6);
  PrintValue(7);
  return 0;
}
