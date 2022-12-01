/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Nov 11 2022
 * @brief Shows how to read several values from std::cin
 *        This is a common pattern usually required when dealing with Jutge Problems
 *
 *        Execute this program taking the input from a file containing (for example)
 *        these data:
 *        1.1 2.2 3.3 4.4 5.5
 */

#include <iostream>

int main() {
  double mi_variable;
  while (std::cin >> mi_variable) {
    std::cout << "The value entered was " << mi_variable << std::endl;
  } 
  return 0;
}
