/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 21 2021
 * @brief Example of range for (also called for-each)
 *        Best Practice: In for-each loops element declarations, if your elements 
 *        are non-fundamental types, use references or const references for 
 *        performance reasons.
 * @see http://www.cplusplus.com/reference/vector/vector/
 */

#include <vector>
#include <iostream>

int main() {
  std::vector<int> fibonacci = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

  for (int number: fibonacci) { // iterate over array fibonacci
    std::cout << number << ' ';
  }
  std::cout << '\n';

  for (auto number: fibonacci) { // type is auto, so number has its type deduced from the array data
    std::cout << number << ' ';
  }
  std::cout << '\n';

  for (const auto& element: fibonacci) {  // element is a const reference to the currently iterated array element
    std::cout << element << ' ';          // therefore you can't modify element
  }
  std::cout << '\n';

  return 0;
}
