/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Dec 9 2020
 * @brief A Default constructor with optional parameters
 *
 *        With objects you can also use direct initialization (using parenthesis)
 *        and list initialization (also called brace/uniform initialization)
 *
 * @see https://www.learncpp.com/cpp-tutorial/85-constructors/
 */

#include <iostream>

class Something {
 public:
  /// Default constructor (can be called with no parameters)
  /// allows us to construct a Something(int, double), Something(int), or Something()
  Something(int first = 0, double second = 1.2) { 
  }
};

int main() {
  Something something1{1, 2.4};  /// Uniform initialization, calls Something(int, double)
  Something something2(7, 4.8);  /// Direct initialization, also calls Something(int, double)
  Something something3{1};       /// calls Something(int)
  Something something4{};        /// calls Something()

  Something something5 = Something{2, 4.8}; /// Copy initialize a Something, will call Something(2, 4.8)
  Something something6 = something5;

  // Something something7{2.4}; /// will not compile, as there's no constructor to handle Something(double)
  return 0;
}
