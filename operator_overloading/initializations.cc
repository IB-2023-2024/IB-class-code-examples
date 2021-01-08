/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 15 Dec 2020
 * @brief Illustrate different initializations supported in C++
 *
 * @see https://www.learncpp.com/cpp-tutorial/the-copy-constructor/
 */

#include <iostream>

class Point {
 public:
  Point(double x = 0.0, double y = 0.0, double z = 0.0): x_{x}, y_{y}, z_{z} { 
		std::cout << "The constructor has been called..." << std::endl;
	}
  // Getters:
  double x() const { return x_; }
  double y() const { return y_; }
  double z() const { return z_; }

  friend std::ostream& operator<<(std::ostream& out, const Point& point);
 private:
  double x_, y_, z_;    // 3D Point coordinates
};

// Overloaded operator << (insertion)
std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "Point(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ')'; // actual output done here
  return out; // return std::ostream so we can chain calls to operator<<
}

int main() {
  int my_var1(1); // Direct initialize an integer
  Point my_point1(1.0, 1.0, 1.0); // Direct initialize a Point, calls Point(double, double, double) constructor
  std::cout << "my_point1 is: " << my_point1 << std::endl << std::endl;

	int my_var2 {2}; // Uniform initialization of an integer
  Point my_point2 {2.0, 2.0, 2.0}; // Uniform initialization of a Point, calls Point(double, double, double) constructor
  std::cout << "my_point2 is: " << my_point2 << std::endl << std::endl;

	int my_var3 = 3; // Copy initialize an integer
  Point my_point3 = Point(3.0); // Copy initialize a Point, will call Point(3.0, 0.0, 0.0)
  std::cout << "my_point3 is: " << my_point3 << std::endl << std::endl;

  Point my_point4 = 4; // Copy initialize a Point.  
	                     // The compiler will try to find a way to convert 4 to a Point, 
											 // which will invoke the Point(4, 0.0, 0.0) constructor.
  std::cout << "my_point4 is: " << my_point4 << std::endl << std::endl;

  Point my_point5{5.0, 6.0, 7.0}; // use default constructor to set to (1.0, 2.0, 3.0)
  std::cout << "my_point5 is: " << my_point5 <<  std::endl << std::endl;
  Point my_point6(my_point5);
  std::cout << "my_point6 is: " <<  my_point6 << std::endl << std::endl;

  return 0;
}
