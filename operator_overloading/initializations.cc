/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 15 2020
 * @brief Illustrate different initializations supported in C++
 *
 * @see https://www.learncpp.com/cpp-tutorial/the-copy-constructor/
 */

#include <iostream>

class Point {
 public:
  // Default constructor
  // A default constructor is a constructor that either has no parameters, 
  // or if it has parameters, all of them have default values. 
  Point(double x = 0.0, double y = 0.0, double z = 0.0): x_{x}, y_{y}, z_{z} { 
		std::cout << "The default constructor has been called..." << std::endl;
	}
  // Getters:
  double x() const { return x_; }
  double y() const { return y_; }
  double z() const { return z_; }
 private:
  double x_, y_, z_;    // 3D Point coordinates
};

/**
 * operator << (insertion) overload as a normal function
 *
 * @param out: A reference (will be modified) to std::ostream
 * @param point: A const reference to the point object to be printed
 * @return out. A reference to std::ostream so we can chain calls to operator<<
 */
std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "Point(" << point.x() << ", " << point.y() << ", " << point.z() << ')'; // actual output done here
  return out; 
}

int main() {
  int number1(1);  // Direct initialize an integer
  Point point1(1.0, 1.0, 1.0);  // Direct initialize a Point, calls Point(double, double, double) constructor
  std::cout << "point1 is: " << point1 << std::endl << std::endl;

	int number2{2};  // Uniform initialization of an integer
  Point point2{2.0, 2.0, 2.0};  // Uniform initialization of a Point, calls Point(double, double, double) constructor
  std::cout << "point2 is: " << point2 << std::endl << std::endl;

	int number3 = 3;  // Copy initialize an integer
  Point point3 = Point(3.0);  // Copy initialize a Point, will call Point(3.0, 0.0, 0.0)
  std::cout << "point3 is: " << point3 << std::endl << std::endl;

  Point point4 = 4;  // Copy initialize a Point.  
	                      // The compiler will try to find a way to convert 4 to a Point, 
											  // which will invoke the Point(4, 0.0, 0.0) constructor.
  std::cout << "point4 is: " << point4 << std::endl << std::endl;

  Point point5{5.0, 6.0, 7.0};  // use default constructor to set to (5.0, 6.0, 7.0)
  std::cout << "point5 is: " << point5 <<  std::endl << std::endl;
  Point point6{point5};
  std::cout << "point6 is: " <<  point6 << std::endl << std::endl;

  return 0;
}

/* Output of this program:
  
The constructor has been called...
point1 is: Point(1, 1, 1)

The constructor has been called...
point2 is: Point(2, 2, 2)

The constructor has been called...
point3 is: Point(3, 0, 0)

The constructor has been called...
point4 is: Point(4, 0, 0)

The constructor has been called...
point5 is: Point(5, 6, 7)

point6 is: Point(5, 6, 7)
*/
