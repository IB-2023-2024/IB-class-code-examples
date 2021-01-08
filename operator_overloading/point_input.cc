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
  Point(double x = 0.0, double y = 0.0, double z = 0.0) : x_{x}, y_{y}, z_{z} {
  }

  friend std::ostream& operator<< (std::ostream& out, const Point& point);
  friend std::istream& operator>> (std::istream& in, Point& point);
 private:
  double x_{};
  double y_{};
  double z_{};
};

// Since operator<< is a friend of the Point class, we can access Point's members directly.
std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "Point(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ')';
  return out;
}

// Again, since operator>> is a friend of the Point class, we can access Point's members directly.
// note that parameter point must be non-const so we can modify the class members with the input values
std::istream& operator>>(std::istream& in, Point& point) {
  in >> point.x_;
  in >> point.y_;
  in >> point.z_;
  return in;
}

int main() {
  std::cout << "Enter a point: \n";
  Point point{};
  std::cin >> point;
  std::cout << "You entered: " << point << '\n';

  return 0;
}
