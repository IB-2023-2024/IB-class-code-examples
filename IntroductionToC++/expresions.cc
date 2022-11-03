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
  // DISCLAIMIER: Take into account that identifiers should always be meaningful
  //              The use of identifiers with a single character (i, p, etc.) is a Bad Practice
  //              Here we use such identifiers for the sake of simplicity and to relate this code
  //              with the slides used in the classes
  
  int x{9};      // Practice changing the value and trying to guess the result
  int y{0};
  int* p{&x};
  double d{0.0};

  // We print the value of different expressions
  // Remember that false/true are printed as 0/1 respectively
  std::cout << "1: "  << (x)             << '\n'; 
  std::cout << "2: "  << (y = x)         << '\n'; 
  std::cout << "3: "  << (x + 1)         << '\n'; 
  std::cout << "4: "  << (x * x + 2 * x) << '\n'; 
  std::cout << "5: "  << (y = x * x)     << '\n'; 
  std::cout << "6: "  << (x == 42)       << '\n'; 
  std::cout << "7: "  << (*p)            << '\n'; 
  std::cout << "8: "  << (p == &x)       << '\n'; 
  std::cout << "9: "  << (x > 2 * y)     << '\n'; 
  std::cout << "10: " << (std::sin(d))   << '\n'; 

  return 0;
}
