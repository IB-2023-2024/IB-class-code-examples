/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 13 Nov 2020
 * @brief Show the use of the ternary operator
 *
 * @see https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
 * 
 */
#include <iostream>

int Min(int x, int y) {
  // if (x < y)
  //   return x;
  // else
  //   return y; 
  return x < y ? x : y;
}

int main() {
  std::cout << Min(3, 4) << std::endl;
}
