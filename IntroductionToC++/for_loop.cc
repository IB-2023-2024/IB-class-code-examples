/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief for loop
 *
 * Countdown using for
 *
 * @see http://www.cplusplus.com/doc/tutorial/control/
 */

#include <iostream>

int main () {
  const int kNumberOfIterations{10};  // Play modifying this value

  for (int i = kNumberOfIterations; i > 0; i--) {
    std::cout << i << ", ";
  }
  std::cout << "liftoff!" << std::endl;
}
