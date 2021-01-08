/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 15 Dec 2020
 * @brief Overloading unary operators
 *        This code shows an overload of both operator- and operator! for a user-defined Point class
 *    
 *        Because operator- (and operator!) does not modify the Point object, we can (and should) 
 *        make it a const function (so it can be called on const Point objects).
 *
 *        The overloaded operator! for this class returns the boolean value “true” 
 *        if the Point is set to the default value at coordinate (0.0, 0.0, 0.0). 
 *
 * @see https://www.learncpp.com/cpp-tutorial/overloading-unary-operators/
 */

#include <iostream>

class Point {
 public:
  Point(double x = 0.0, double y = 0.0, double z = 0.0): x_{x}, y_{y}, z_{z}
  { }

  Point operator-() const;
  bool operator!() const;

  double x() const { return x_; }
  double y() const { return y_; }
  double z() const { return z_; }
 private:
  double x_, y_, z_;
};

// Convert a Point into its negative equivalent
Point Point::operator-() const {
  return Point(-x_, -y_, -z_);
}

// Return true if the point is set at the origin, false otherwise
bool Point::operator!() const {
  return (x_ == 0.0 && y_ == 0.0 && z_ == 0.0);
}

int main() {
  Point point{1.0, 2.0, 3.0}; // use default constructor to set to (1.0, 2.0, 3.0)
  if (!point)
    std::cout << "point is set at the origin.\n";
  else
    std::cout << "point is not set at the origin.\n";
  
  Point point2{-point};
  if (!point2)
    std::cout << "point is set at the origin.\n";
  else
    std::cout << "point is not set at the origin.\n";

  return 0;
}
