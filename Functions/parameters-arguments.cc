/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 2023 Oct 12
 * @brief Function Parameters, Arguments, and Return Values
 *
 */

#include <iostream>

int Square(int parameter) { 		// parameter takes its value from argument
  return parameter * parameter; // return value is parameter * parameter
}

void Compute() {
  int local_var{3};
  int result = Square(local_var);		// local_var is argument (actual param)
}


int main() {
  Compute();
  std::cout << "Resultado: " << result << std::endl;  // Here result is out of scope
  return 0;
}
