/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief Overloading operator>>
 *        It is also possible to overload the input operator
 *        This is done in a manner analogous to overloading the output operator
 *        The key thing you need to know is that std::cin is an object of type std::istream
 *
 * @see https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
 * @see https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
 *
 */

#include <iostream>

class Point {
 public:
  Point(double x = 0.0, double y = 0.0, double z = 0.0) : x_coordinate_{x}, y_coordinate_{y}, z_coordinate_{z} { }
  friend std::ostream& operator<<(std::ostream& out, const Point& point);
  friend std::istream& operator>>(std::istream& in, Point& point);
 private:
  double x_coordinate_{};
  double y_coordinate_{};
  double z_coordinate_{};
};

// Since operator<< is a friend of the Point class, we can access Point's members directly.
std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "Point(" << point.x_coordinate_ << ", " << point.y_coordinate_ << ", " << point.z_coordinate_ << ')';
  return out;
}

// Again, since operator>> is a friend of the Point class, we can access Point's members directly.
// note that parameter point must be non-const so we can modify the class members with the input values
std::istream& operator>>(std::istream& in, Point& point) {
  in >> point.x_coordinate_;
  in >> point.y_coordinate_;
  in >> point.z_coordinate_;
  return in;
}

int main() {
  std::cout << "Enter a point: \n";
  Point point{};
  std::cin >> point;
  std::cout << "You entered: " << point << '\n';
  return 0;
}
