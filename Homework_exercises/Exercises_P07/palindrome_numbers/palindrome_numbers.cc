/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief  Function definition for palindrome_numbers
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 */

#include <iostream>
#include <string>
#include <cstdlib>    // exit
#include <vector>

#include "palindrome_numbers.h"

// Usage: the program requires two numeric parameter
void Usage(int argc, char *argv[]) {
  if ((argc != 3) && (argc != 2)) {
    std::cout << argv[0] << ": Faltan dos números naturales como parámetros" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc == 2) {  // The user has given a single parameter. Check if correct.
    std::string parameter1{argv[1]};
    if (parameter1 == "--help") {
      std::cout << kHelpText << std::endl;
      std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
      exit(EXIT_SUCCESS);
    }
    else {
      std::cout << argv[0] << ": Faltan dos números naturales como parámetros" << std::endl;
      std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
      exit(EXIT_SUCCESS);
    }

  }
}

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
void MinMaxPalindrome(const size_t lower, const size_t upper) {
  size_t min_palindrome{99999};  // Select a large number
  size_t min_factor1, min_factor2;
  size_t max_palindrome{0};      // Select a small number
  size_t max_factor1, max_factor2;

  for (size_t i = lower; i <= upper; ++i) {
    for (size_t j = i; j <= upper; ++j) {
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
  std::cout << "Min Palindrome: " << min_palindrome << " (" << min_factor1 << " x " << min_factor2 << ")" << std::endl;
  std::cout << "Max Palindrome: " << max_palindrome << " (" << max_factor1 << " x " << max_factor2 << ")" << std::endl;
}
