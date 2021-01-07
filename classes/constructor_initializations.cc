/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 09 Dec 2020
 * @brief A Default constructor with optional parameters
 *        With objects you can also use direct initialization and list initialization
 *
 * @see https://www.learncpp.com/cpp-tutorial/85-constructors/
 */

#include <iostream>

class Something {
 public:
  /// Default constructor
  Something(int n = 0, double d = 1.2) { // allows us to construct a Something(int, double), Something(int), or Something()
  }
};

int main() {
  Something s1{1, 2.4 };  /// Uniform initialization, calls Something(int, double)
  Something s2(7, 4.8);   /// Direct initialization, also calls Something(int, double)
  Something s3{1}; /// calls Something(int)
  Something s4{}; /// calls Something()

  Something s5 = Something{2, 4.8}; /// Copy initialize a Something, will call Something(2, 4.8)
  Something s6 = s5;

  // Something sX{ 2.4 }; /// will not compile, as there's no constructor to handle Something(double)

  return 0;
}
