/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 27 2021
 * @brief Inputs 3 natural numbers and prints their squares
 *        The program takes directly the input and prints the output
 */

#include <iostream>

int main() {
  int number1{0};
  int number2{0};
  int number3{0};

  std::cin >> number1 >> number2 >> number3;
  std::cout << number1 * number1 << " " << number2 * number2 << " " << number3 * number3 << std::endl;
  return 0;
}
