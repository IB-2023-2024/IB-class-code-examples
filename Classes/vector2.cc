/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief A simple class for 2D vectors
 *
 * The Vector2 class has member function Initialize
 * To refer to member of class outside of class body must use scope-resolution operator (i.e., :: )
 * for example, in case of initialize function, we use Vector2::Initialize
 * Member function always has object of class as implicit parameter
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 */

#include <iostream>
#include <string>

using namespace std;

class Vector2 {      // Two-dimensional vector class
  public:
    double x;        // The x component of the vector
    double y;        // The y component of the vector
    void Initialize (double x_, double y_);
};

void Vector2::initialize (double x_, double y_){
  x = x_;
  y = y_;
}

void Func() {
  Vector2 v;                 // Create an instance of Vector2 called v
  v.initialize(1.0, 2.0);    // Initialize v to (1.0, 2.0)
}

int main() {
  Func();
  return 0;
}
