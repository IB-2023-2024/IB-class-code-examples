/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief Move constructor
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#move
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 * @see https://en.cppreference.com/w/cpp/language/move_constructor
 */

#include <iostream>

class Vector {          /// Two-dimensional vector class
 public:
  Vector() {          /// Default constructor
    x_ = 0.0;
    y_ = 0.0;
    std::cout << "Class constructor has been called" << std::endl;
  }

  Vector(const Vector& v) { /// Copy constructor
    x_ = v.x_; 
    y_ = v.y_;
    std::cout << "Copy constructor has been called" << std::endl;
  }

  Vector(Vector&& v) {     /// Move constructor
    x_ = v.x_; 
    y_ = v.y_;
    std::cout << "Move constructor has been called" << std::endl;
  }

  // ...

 private:
  double x_{0.0} ;         /// The x component of the vector
  double y_{0.0} ;         /// The y component of the vector
};

Vector Func() {          // Func returns a Vector object
  std::cout << "Previous to local_vec declaration" << std::endl;
  Vector local_vec;
  std::cout << "After local_vec declaration" << std::endl;
  return local_vec;
}

int main() {
  std::cout << "Previous to Func call" << std::endl;
  Vector my_vec = Func();   // calls Vector(Vector&&) if move not elided
  std::cout << "After Func call" << std::endl;
  return 0;
}

