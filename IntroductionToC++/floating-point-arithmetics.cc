/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Nov 7, 2022
 * @brief Shows floating point arithmetics
 *
 * @see https://www.tutorialspoint.com/floating-point-comparison-in-cplusplus
 * @see https://stackoverflow.com/a/17341/12791643
 */

#include <iostream>

int main() {
  const double kOneThird{0.3333333333};
  if (1.0 / 3 == kOneThird) {
    std::cout << "Equals" << std::endl;
  }
  else {
    std::cout << "Different" << std::endl;
  }
  return 0;
}
