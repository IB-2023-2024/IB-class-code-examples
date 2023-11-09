/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief Class constructor
 *
 * @see https://www.geeksforgeeks.org/constructors-c/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#default_constructor
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 */

#include <iostream>

class Vector {        // Two-dimensional vector class
 public:
  Vector() {          // Default constructor (without parameters)
    x_ = 0.0;
    y_ = 0.0;
    std::cout << "Class constructor has been called" << std::endl;
  }
  // ...
 private:
  double x_ ;         // x component of the vector
  double y_ ;         // y component of the vector
};

int main() {
  std::cout << "Previous to object declaration" << std::endl;
  Vector vector;   // calls Vector(); vector set to (0, 0)
  std::cout << "After object declaration" << std::endl;
  // Vector Func();     // declares function Func that returns Vector
  return 0;
}
