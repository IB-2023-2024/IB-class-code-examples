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
 *         Versión 2: Hallar todos los productos en el rango 
 *         Versión 3: a) Print only the palindrome numbers in the range
 *                    b) select minimum
 *                    c) select maximum
 *         Versión 4: Hold the factors of min/max palindrome
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 */

#include <iostream>
#include <string>
#include <vector>


// Return true if numero is palindrome
bool IsPalindrome(int numero) {
  const int kBase = 10;
  int numero_inverso{0};
  int numero_original{numero};

  while (numero > 0) {
    numero_inverso = numero_inverso * kBase + (numero % kBase);
    numero = numero / kBase;
  }
  return (numero_original == numero_inverso);
}

// Finds Min and Max palindrome in range [lower, upper]
// Finds also the factors for the palindrome
void MinMaxPalindrome(const int lower, const int upper) {
  int min_palindrome{99999};  // Select a large number
  int min_factor1, min_factor2;
  int max_palindrome{0};      // Select a small number
  int max_factor1, max_factor2;

  for (int i = lower; i <= upper; ++i) {
    for (int j = i; j <= upper; ++j) {
      if (IsPalindrome(i * j)) {
        if (i * j < min_palindrome) {
          min_palindrome = i * j;
          min_factor1 = i;
          min_factor2 = j;
        }
        if (i * j > max_palindrome) {
          max_palindrome = i * j;
          max_factor1 = i;
          max_factor2 = j;
        }
      }
    }
  }
  std::cout << "Min Palindrome: " << min_palindrome << " Factor1: " << min_factor1 << " Factor2: "  << min_factor2 << std::endl;
  std::cout << "Max Palindrome: " << max_palindrome << " Factor1: " << max_factor1 << " Factor2: " << max_factor2 << std::endl;
}

int main () {
  int const kLower{10};
  int kUpper{99};

  MinMaxPalindrome(kLower, kUpper);
  return 0;
}
