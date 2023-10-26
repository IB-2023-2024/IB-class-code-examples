/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief I/O Manipulators. setprecision.
 * If fixed or scientific notation is used, precision determines how many decimal places in the fraction is displayed. 
 * Note that if the precision is less than the number of significant digits, the number will be rounded.
 *
 * @see http://www.cplusplus.com/reference/library/manipulators/
 * @see https://www.learncpp.com/cpp-tutorial/183-output-with-ostream-and-ios/
 */

#include <iostream>
#include <iomanip>

const double kValue{123.456};
const int kAscii_a{static_cast<int>('a')};
const int kSegundosEnHora{60 * 60};

int main() {
  std::cout << std::fixed << std::endl;
  std::cout << std::setprecision(3) << kValue << std::endl;
  std::cout << std::setprecision(4) << kValue << std::endl;
  std::cout << std::setprecision(5) << kValue << std::endl;
  std::cout << std::setprecision(6) << kValue << std::endl;
  std::cout << std::setprecision(7) << kValue << std::endl;

  std::cout << std::scientific << std::endl;
  std::cout << std::setprecision(3) << kValue << std::endl;
  std::cout << std::setprecision(4) << kValue << std::endl;
  std::cout << std::setprecision(5) << kValue << std::endl;
  std::cout << std::setprecision(6) << kValue << std::endl;
  std::cout << std::setprecision(7) << kValue << std::endl;
  return 0;
}
