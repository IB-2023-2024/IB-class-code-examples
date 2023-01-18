/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Example of a bad function
 *
 * In this function:
 *   Name of the function means nothing
 *   Names of local variables mean nothing
 *   Function does not have a single purpose
 *
 * @see https://en.cppreference.com/w/cpp/language/functions
 * @see http://www.cplusplus.com/doc/tutorial/functions/
 */

#include <vector>

using namespace std;

vector<int> Func(int a, bool b) {
  if (b) { 
    return vector<int>(10, a); 
  }
  vector<int> vec(a);
  for (int i{0}; i < a; ++i) { 
    vec[i] = a * i; 
  }
  if (vec.size() > a * 2) { 
    vec[a] /= 2.0f; 
  }
  return vec;
}

int main() {
  auto my_vector = Func(5, false);
  return 0;
}
