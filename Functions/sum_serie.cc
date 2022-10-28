/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Nov 3 2021
 * @brief A first Function example
 *        The program defines the SumSerie() function that computes the
 *        sum of 1+2+3+...+N for a given N
 * @see https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 */

#include <iostream>

// Computes the sum 1+2+3+...+num_terms
int SumSerie(int num_terms) {
  const int result{num_terms * (num_terms + 1) / 2};
  return result;
}

int main() {
  std::cout << "Este programa calcula la suma de los N primeros números naturales" << std::endl << std::endl;
  std::cout << "Introduzca el número de términos a sumar: ";
  int num_terms;
  std::cin >> num_terms;
  std::cout << "La suma de los " << num_terms << " primeros términos es: " << SumSerie(num_terms) << std::endl;

  for(int i{1}; i < num_terms; ++i) {
    std::cout << i << " + ";
  }
  std::cout << num_terms << " = " << SumSerie(num_terms) << std::endl;
  return 0;
}

