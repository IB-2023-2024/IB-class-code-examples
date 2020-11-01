/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief vector Example
 *
 * Use std::vector when number of items is unknown before-wise
 * Consider it to be a default container to store collections of items of any same type
 * Vector is implemented as a dynamic table
 * Access stored items just like in std::array
 * Remove all elements: vec.clear()
 * Add a new item in one of two ways:
 *   vec.emplace_back(value)  [preferred, c++11]
 *   vec.push_back(value)       [historically better known]
 *
 * @see http://www.cplusplus.com/reference/vector/vector/
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main () {
  vector<int> numbers = {1, 2, 3};
  vector<string> names = {"Albert", " Alan"};
  names.push_back ("another_string ");
  cout << "First name: " << names.front () << endl;
  cout << "Last number: " << numbers.back () << endl;
  return 0;
}
