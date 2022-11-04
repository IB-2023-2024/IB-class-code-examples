/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Default arguments example
 * 
 * @see http://www.cplusplus.com/doc/tutorial/functions/
 *      Default values in parameters
 *
 * @see https://google.github.io/styleguide/cppguide.html#Default_Arguments
 */

#include <iostream> // std::cout, std::endl


double MyFunc(int x = 7) {
  return 4.5;
}

std::string SayHello(const std::string& to_whom = "World ") {
 return "Hello " + to_whom + "!";
}

int main() {
  std::cout << SayHello() << std::endl;
  std::cout << SayHello("Students") << std::endl;
  return 0;
}


