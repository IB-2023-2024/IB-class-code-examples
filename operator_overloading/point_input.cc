/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 10 2020
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

/**
 * operator << overload
 *
 * @param out: A reference (will be modified) to std::ostream
 * @param point: A const reference to the point object to be printed
 * @return out. A reference to std::ostream so we can chain calls to operator<<
 *           Since operator<< is a friend of the Point class, we can access Point's members directly.
 *           because C++ already knows how to output doubles using operator<<, and our members are
 *           all doubles, we can simply use operator<< to output the member variables of our Point.
 */
std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "Point(" << point.x_coordinate_ << ", " << point.y_coordinate_ << ", " << point.z_coordinate_ << ')';
  return out;
}

/**
 * operator >> overload
 *
 * @param in: A reference (will be modified) to std::istream
 * @param point: A reference to the point object to be read
 * @return in. A reference to std::istream 
 *             Again, since operator>> is a friend of the Point class, we can access Point's members directly.
 *             note that parameter point must be non-const so we can modify the class members with the input values
 */
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
