/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief Copy constructor
 *
 * @see https://www.learncpp.com/cpp-tutorial/the-copy-constructor/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#copy_constructor
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 */

#include <iostream>

class Vector {   /// Two-dimensional vector class
 public:
  Vector() {     /// Default constructor
    x_ = 0.0;
    y_ = 0.0;
    std::cout << "Class constructor has been called" << std::endl;
  }

  Vector(const Vector& other) { /// Copy constructor
    x_ = other.x_; 
    y_ = other.y_;
    std::cout << "Copy constructor has been called" << std::endl;
  }

  // ...

 private:
  double x_ ;   /// The x component of the vector
  double y_ ;   /// The y component of the vector
};

int main() {
  std::cout << "Previous to object my_vec declaration" << std::endl;
  Vector my_vec;
  std::cout << "After object my_vec declaration" << std::endl;
  Vector second(my_vec);    /// calls Vector(const Vector&)
  Vector third = my_vec;   /// calls Vector(const Vector&)
  return 0;
}
