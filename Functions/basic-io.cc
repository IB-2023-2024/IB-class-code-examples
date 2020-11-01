/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief Basic Input/Output Example
 * stream can be used as bool expression; 
 * converts to true if stream has not encountered any errors and false otherwise 
 * (e.g., if invalid data read or I/O error occurred)
 *
 * @see http://www.cplusplus.com/doc/tutorial/basic_io/
 */

#include <iostream> // std ::cout , std :: endl


int main() {
  std::cout << "Enter an integer: ";
  int x;
  std::cin >> x;
  if (std::cin) {
    std::cout << "The integer entered was " << x << std::endl;
  } else {
    std::cerr << "End-of-file reached or I/O error " << std::endl;
  }
}

