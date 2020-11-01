/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 4 Jun 2020
 * @brief C++ Optimize vector resizing
 *
 * Many push_back/emplace_back operations force vector to change its size many times
 * reserve(n) ensures that the vector has enough memory to store n items
 * The parameter n can even be approximate
 * This is a very important optimizatioN
 *
 * @see http://www.cplusplus.com/reference/vector/vector/reserve/
 */

#include <iostream>
#include <vector> 
#include <string> 

int main () {
  std::vector<std::string> my_vector;

  const int kVecSize{100};
  // Always call reserve when you know the size
  my_vector.reserve (kVecSize);
  for (int i = 0; i < kVecSize; ++i) {
    my_vector.emplace_back("hello");
  }
}
