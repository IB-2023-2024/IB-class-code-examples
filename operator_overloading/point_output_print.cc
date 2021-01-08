/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief Overloading operator<<
 *        Se puede escribir un método Print() encargado de escribir el objeto
 *
 * @see https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
 */

#include <iostream>

class Point {
 public:
  Point(double x = 0.0, double y = 0.0, double z = 0.0) : x_{x}, y_{y}, z_{z} { }
  double getX() const { return x_; }
  double getY() const { return y_; }
  double getZ() const { return z_; }
  void Print() const {
    std::cout << "Point(" << x_ << ", " << y_ << ", " << z_ << ')';
  }
 private:
  double x_;
  double y_;
  double z_;
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
