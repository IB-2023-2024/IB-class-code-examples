/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief A class with 4 constructors
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#default_constructor
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#copy_constructor
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#move
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 * @see https://en.cppreference.com/w/cpp/language/move_constructor
 */

#include <iostream>

class Vector {          // Two-dimensional vector class
  public:
    Vector() {          // Default constructor
      x_ = 0.0;
      y_ = 0.0;
      std::cout << "Class constructor has been called" << std::endl;
    }

    Vector(const Vector& v) { // Copy constructor
      x_ = v.x_; 
      y_ = v.y_;
      std::cout << "Copy constructor has been called" << std::endl;
    }

    Vector(Vector&& v) {           // Move constructor
      x_ = v.x_; 
      y_ = v.y_;
      std::cout << "Move constructor has been called" << std::endl;
    }

    Vector(double x, double y) {   // constructor with parameters
      x_ = x; 
      y_ = y;
      std::cout << "Parameters constructor has been called" << std::endl;
    }

    // ...

  private:
    double x_ ;         // The x component of the vector
    double y_ ;         // The y component of the vector
};

Vector Func() {          // Func returns a Vector object
  std::cout << "Previous to local_vec declaration" << std::endl;
  Vector local_vec(7.0, 4.0);
  std::cout << "After local_vec declaration" << std::endl;
  return local_vec;
}

int main() {
  Vector u;              // calls Default constructor. u set to (0,0)
  Vector v(1.0 , 2.0);   // calls Vector(double, double)
  Vector w(v);           // calls Copy constructor
  Vector z = u;          // calls Copy constructor
  Vector y = Func();     // calls Vector(Vector&&) if move not elided
  return 0;
}
