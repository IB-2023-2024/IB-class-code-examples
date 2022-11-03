/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 11 Oct 2020
 * @brief Simple I/O streams usage
 *
 */

#include <iostream>

int main() {
  int some_number;

  std::cout << "Input a number: ";
  std::cin >> some_number;
  std::cout << "number = " << some_number << std::endl;
  std::cerr << "boring error message " << std::endl;
  return 0;
}
