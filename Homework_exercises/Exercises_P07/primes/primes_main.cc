/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito
 * @date 23.nov.2020
 * @brief Ejercicio de la práctica 7 de la asignatura
 *        Este programa solicita al usuario un número e imprime en pantalla 
 *        todos los números primos menores que el introducido
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 */

#include <iostream>
#include <string>

#include "primes.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  int number = std::stoi(argv[1]);
  for (int i = 2; i < number; i++) {
    if (IsPrime(i)) {
      std::cout << "Number " << i << " is prime!" << std::endl;
    } else {
      std::cout << "Number " << i << " is not prime!" << std::endl;
    }
  }
}
