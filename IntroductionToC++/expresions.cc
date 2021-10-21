/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 21 2021
 * @brief The value of expressions
 *        Any C++ expression has a type and, if the type is not void, it has a value
 *        Play with the code changing the values assigned to x and y and understand the output
 * @see https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/
 */

#include <iostream>
#include <cmath>

int main() {
  int x{0};
  int y{0};
  int* p{&x};
  double d{0.0};

  // We print the value of different expressions
  // Remember that false/true are printed as 0/1 respectively
  std::cout << (x)             << '\n'; 
  std::cout << (y = x)         << '\n'; 
  std::cout << (x + 1)         << '\n'; 
  std::cout << (x * x + 2 * x) << '\n'; 
  std::cout << (y = x * x)     << '\n'; 
  std::cout << (x == 42)       << '\n'; 
  std::cout << (*p)            << '\n'; 
  std::cout << (p == &x)       << '\n'; 
  std::cout << (x > 2 * y)     << '\n'; 
  std::cout << (std::sin(d))   << '\n'; 

  return 0;
}
