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
  int numero_de_terminos;
  std::cin >> numero_de_terminos;
  std::cout << "La suma de los " << numero_de_terminos << " primeros términos es: " << SumSerie(numero_de_terminos) << std::endl;

  for(int i{1}; i < numero_de_terminos; ++i) {
    std::cout << i << " + ";
  }
  std::cout << numero_de_terminos << " = " << SumSerie(numero_de_terminos) << std::endl;
  return 0;
}

