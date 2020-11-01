/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief while loop
 *
 * Countdown using while
 *
 * @see http://www.cplusplus.com/doc/tutorial/control/
 */

#include <iostream>

int main () {
  int number_of_iterations{10};  // Play modifying this value

  while (number_of_iterations > 0) {
    std::cout << number_of_iterations << ", ";
    --number_of_iterations;
  }
  std::cout << "liftoff!" << std::endl;
}
