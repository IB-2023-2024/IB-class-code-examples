/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 25 2020
 * @brief Classes. Type member Example
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
 */

class Point2 {    // Two-dimensional point class
 public:
  using Coordinate = double;  // Coordinate type
  // typedef double Coordinate ; // Coordinate type
  Coordinate x_; // The x coordinate of the point
  Coordinate y_; // The y coordinate of the point
};

void MyFunc() {
  Point2 point;
  // ...
  Point2::Coordinate x = point.x_;
  // Point2::Coordinate same as double
}

int main() {
  MyFunc();
  return 0;
}
