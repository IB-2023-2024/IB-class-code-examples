/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Function overloading example
 * 
 * There are 2 Func implementations
 * The compiler decides which function to invoke in terms of the type of argument passed
 */

#include <iostream>
#include <string>

std::string Func(int num) { 
  return "int"; 
}

std::string Func(const std::string& str) { 
  return "string"; 
}

std::string Func(double number) { 
  return "It's a double"; 
}

int main() {
  std::cout << Func(1) << std::endl;
  std::cout << Func("hello") << std::endl;
  std::cout << Func(1.0) << std::endl;
  return 0;
}
