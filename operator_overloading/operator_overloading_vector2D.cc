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
  friend std::ostream& operator<< (std::ostream &out, const Vector &vector);
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

/// Insertion overload
std::ostream& operator<< (std::ostream &out, const Vector &vector) {
  out << "(" << vector.x_ << ", " << vector.y_ << ")"; // actual output done here
  return out;
}

void Func () {
  Vector vector1(1.0, 2.0);
	std::cout << vector1 << std::endl;
  Vector vector2{vector1};
  Vector vector3;
  vector3 = vector1 + vector2;             // vector3.operator=(operator+(vector1, vector2))
	std::cout << vector3 << std::endl;
  double c = vector1 * vector2;      // calls operator*(vector1, vector2)
                         // since c is built-in type, assignment operator
                         // does not require function call
}

int main () {
  Func();
  return 0;
}
