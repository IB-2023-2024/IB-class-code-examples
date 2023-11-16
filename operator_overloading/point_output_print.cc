/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 10 2020
 * @brief Overloading operator<<
 *        In this approach we write a Print() method (member function) that prints the object
 *
 * @see https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
 */

#include <iostream>

class Point {
 public:
  Point(double x = 0.0, double y = 0.0, double z = 0.0) : x_coordinate_{x}, y_coordinate_{y}, z_coordinate_{z} { }
  double getX() const { return x_coordinate_; }
  double getY() const { return y_coordinate_; }
  double getZ() const { return z_coordinate_; }
  void Print() const {
    std::cout << "Point(" << x_coordinate_ << ", " << y_coordinate_ << ", " << z_coordinate_ << ')';
  }
 private:
  double x_coordinate_;
  double y_coordinate_;
  double z_coordinate_;
};

int main() {
  const Point point{2.0, 3.0, 4.0};
  std::cout << "Mi punto es: ";
  point.Print();
  std::cout << " en el espacio 3D" << std::endl;
  // Sería deseable escribir:
	//
  // std::cout << "Mi punto es: " << point.Print() << " en el espacio 3D" << std::endl;
	//
  // Ello no es posible porque Print devuelve void
  return 0;
}
