/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 01 Jul 2020
 * @brief Illustrate operator overloading for a User defined Type: 2D Vector
 *
 * @see http://www.cplusplus.com/doc/tutorial/templates/
 * @see https://en.cppreference.com/w/cpp/language/operators
 */

#include <iostream>

using std::cout; using std::endl;

class Vector { // 2D vector class
  public:
    Vector() : x_ (0.0), y_ (0.0) {}        // Initializer list
    Vector(double x, double y) : x_ (x), y_ (y) {}
    double x() const { return x_; }
    double y() const { return y_; }
  private:
    double x_; // The x component
    double y_; // The y component
};

// Vector addition
Vector operator+(const Vector& u, const Vector& v) {
  return Vector (u.x() + v.x(), u.y() + v.y());
}

// Dot product
double operator*(const Vector& u, const Vector& v) {
  return u.x() * v.x() + u.y() * v.y();
}

void Func () {
  Vector u(1.0, 2.0);
  Vector v(u);
  Vector w;
  w = u + v;             // w.operator=(operator+(u, v))
  double c = u * v;      // calls operator*(u, v)
                         // since c is built-in type, assignment operator
                         // does not require function call
}

int main () {
  Func();
  return 0;
}
