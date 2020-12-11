/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 7.nov.2020
 * @brief Cada nuevo término de la serie de Fibonacci se genera sumando los dos anteriores. 
 *        Comenzando con 0 y 1, los primeros 10 términos serán: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
 *        Desarrolle en C++ un programa que calcule la suma de todos los términos de valor par 
 *        de la serie que sean menores que 1000.
 * @see https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 * @see stoi http://www.cplusplus.com/reference/string/stoi/
 * An Object Oriented Version of the program:
 * @see https://stackoverflow.com/questions/21360694/sum-of-even-fibonacci-numbers-under-1000
 *
 */

#include <iostream>

#include "fibonacci_sum.h"    


/** Devuelve el valor de la suma de todos los términos de valor par de la serie de
 *  Fibonacci menores que kLimit
 *
 *  @param[in] kLimit. Se suman los términos pares menores que kLimit
 *  @return La suma de los términos pares menores que kLimit
 */
size_t fibonacci_sum(const size_t kLimit) {
  size_t second_to_last{0},  // Second to last term
           last{1},          // Last term generated
           new_term{0};      // New term of the serie
  size_t sum{0};        // Accumulated sum of the terms

	while (new_term < kLimit) {
    new_term = last + second_to_last;
    if ((new_term % 2 == 0) && (new_term < kLimit)) {
      sum += new_term;
    }
    // Uncomment for debug: print each new term
    // std::cout << "Term: " << new_term << std::endl;
    second_to_last = last;
    last = new_term;
	}

  return sum;
}
