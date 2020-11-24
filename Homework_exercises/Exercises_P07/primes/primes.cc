/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito
 * @date 23.nov.2020
 * @brief Definición de las funciones que intervienen en el programa
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 */

#include <iostream>
#include <string>

#include "primes.h"

void Usage(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << ": Falta un número natural positivo como parámetro" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc == 2) {
    std::string parameter1{argv[1]};
    if (parameter1 == "--help") {
      std::cout << kHelpText << std::endl;
      std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}

bool IsPrime(int numberToCheck) {
  int i = 2;
  while (i < numberToCheck) {
    if ((numberToCheck % i) == 0) {
      return false; 
    }
    i++;
  }
  return true;
}

