/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief  Ejercicios propuestos en las prácticas de Informática Básica
 *         Ejercicio 5. Práctica 7:
 *          Un número palíndromo es aquél que permanece igual cuando se invierten sus dígitos. 
 *          Por ejemplo 121 es un número palíndromo mientras que 112 no lo es. 
 *          Escriba un programa en C++ que solicite al usuario los límites inferior y 
 *          superior de un intervalo ([N, M]) y encuentre el número palíndromo más grande y 
 *          el más pequeño que sean productos de números dentro de ese rango.
 *
 *         Versión 1: Función que devuelva si un número es palíndromo o no.
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 */

#include <iostream>
#include <string>
#include <vector>


bool IsPalindrome(int numero) {
  int numero_inverso{0};
  int numero_original{numero};

//  8976 -> 6
//   897 -> 7
//    89 -> 9
//     8 -> 8
//     0

  while (numero > 0) {
    numero_inverso = numero_inverso * 10 + (numero % 10);
    numero = numero / 10;
    std::cout << "Numero: " << numero << " Numero inverso: " << numero_inverso << std::endl;
  }
  return (numero_original == numero_inverso);
}

int main () {
  const size_t kNumero{8976};
  std::cout << IsPalindrome(kNumero); 
  return 0;
}

