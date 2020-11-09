/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 4 Jun 2020
 * @brief C++ Strings
 *
 * #include <string> to use std::string
 * Concatenate strings with +
 * Check if str is empty with str.empty()
 * Works out of the box with I/O streams
 *
 * @see https://www.w3schools.com/cpp/cpp_strings.asp
 */

#include <iostream>
#include <string>

int main () {
  const std::string kHello{"Hello"};

  std::cout << "Type your name:" << std :: endl;
  std::string name = "";   // Init empty 
  std::cin >> name;
  // Read name
  std::cout << kHello + ", " + name + "!" << std :: endl;
  return 0;
}
