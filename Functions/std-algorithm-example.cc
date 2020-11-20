/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 17 Jun 2020
 * @brief Example of the use of an std algorithm
 * 
 * @see https://en.cppreference.com/w/cpp/algorithm/accumulate
 */

#include <iostream>          // std::cout, std::endl
#include <vector>
#include <algorithm>         // sort 
#include <numeric>           // accumulate 

using namespace std;

int main () {
  std::vector<float>my_vector{8.0, 4.0, 6.0, 8.0, 19.0, 21.0, 35.0, 74.0, 88.0};
  //std::vector<float>my_vector{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

  std::sort(my_vector.begin(), my_vector.end());       // Sort ascending
  float sum = std::accumulate(my_vector.begin(), my_vector.end(), 0.0f);
  float product = std::accumulate(my_vector.begin(), my_vector.end(), 1.0f, std::multiplies<float>());
  cout << "sum: " << sum << " << product: " << product << endl;
  return 0;
}
