/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 18.nov.2020
 * @brief Desarrolle en C++ un programa que imprima en pantalla el valor del factorial de los N primeros números.
 * @see https://en.wikipedia.org/wiki/Factorial
 */

#include <iostream>
#include <cassert>   // assert
#include <cstdlib>   // stoi

const std::string kHelpText = "Este programa imprime el factorial de los N primeros \
números para un N introducido por el usuario";

/// Usage: the program requires a single numeric parameter
void Usage(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << ": Falta un número natural como parámetro" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/// Returns the factorial of the argument
size_t Factorial(size_t number) {
  switch (number) {
    case 0:
    case 1:
      return 1;
    default:
      size_t factorial{1};
      for (size_t i = 1; i <= number; ++i) {
        factorial *= i;
      }
      return factorial;
  }
}

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::string limit{argv[1]};
  const size_t kLimit = stoi(limit);
  for (size_t i = 1; i <= kLimit; ++i) {
    std::cout << i << "! = " << Factorial(i) << std::endl; 
  }
  return 0;
}
