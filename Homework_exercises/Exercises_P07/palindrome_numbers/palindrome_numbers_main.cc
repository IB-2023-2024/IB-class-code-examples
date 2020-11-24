/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief  Driver (main) program
 *         Ejercicios propuestos en las prácticas de Informática Básica
 *         Ejercicio 5. Práctica 7:
 *          Un número palíndromo es aquél que permanece igual cuando se invierten sus dígitos. 
 *          Por ejemplo 121 es un número palíndromo mientras que 112 no lo es. 
 *          Escriba un programa en C++ que solicite al usuario los límites inferior y 
 *          superior de un intervalo ([N, M]) y encuentre el número palíndromo más grande y 
 *          el más pequeño que sean productos de números dentro de ese rango.
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 */

#include <iostream>
#include <string>
#include <vector>

#include "palindrome_numbers.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string str_lower = argv[1];
  const std::string str_upper = argv[2];
  const size_t kLower = stoi(str_lower);
  const size_t kUpper = stoi(str_upper);
	MinMaxPalindrome(kLower, kUpper);
  return 0;
}
