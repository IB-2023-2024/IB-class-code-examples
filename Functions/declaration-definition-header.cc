/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Example of a good function
 *
 * The function returns a vector with perfect squares in range [0, size^2]
 * 
 * The function:
 *   Is small enough to see all the code at once
 *   Name clearly states what the function does
 *   Function does a single thing
 *
 * @see https://en.cppreference.com/w/cpp/language/functions
 * @see http://www.cplusplus.com/doc/tutorial/functions/
 */

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> CreateVectorOfFullSquares(int size);     // Declaration

int main() {
  double experiment = sin(0);

  std::cout << experiment;
  auto squares = CreateVectorOfFullSquares(20);
  for (auto number: squares) {
    std::cout << number << ", ";
  }
  std::cout << std::endl;
  return 0;
}


std::vector<int> CreateVectorOfFullSquares(int size) {
	std::vector<int> result(size);     // Vector of size `size `

  for (int i{0}; i < size; ++i) {
    result[i] = i * i;
  }
  return result;
}
