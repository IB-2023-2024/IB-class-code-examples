/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief I/O Manipulators
 *
 * @see http://www.cplusplus.com/reference/library/manipulators/
 * @see https://www.learncpp.com/cpp-tutorial/182-input-with-istream/
 */

#include <iostream>
#include <iomanip>

int main() {
  std::string input_string;
  std::cout << "Introduzca una cadena de texto (solo leerá 5 caracteres): ";
  std::cin >> std::setw(5) >> input_string;
  std::cout << "Cadena introducida: " << input_string << std::endl;
  return 0;
}
