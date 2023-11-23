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
  int my_var1(1); // Direct initialize an integer
  Point my_point1(1.0, 1.0, 1.0); // Direct initialize a Point, calls Point(double, double, double) constructor
  std::cout << "my_point1 is: " << my_point1 << std::endl << std::endl;

	int my_var2{2}; // Uniform initialization of an integer
  Point my_point2 {2.0, 2.0, 2.0}; // Uniform initialization of a Point, calls Point(double, double, double) constructor
  std::cout << "my_point2 is: " << my_point2 << std::endl << std::endl;

	int my_var3 = 3; // Copy initialize an integer
  Point my_point3 = Point(3.0); // Copy initialize a Point, will call Point(3.0, 0.0, 0.0)
  std::cout << "my_point3 is: " << my_point3 << std::endl << std::endl;

  Point my_point4 = 4; // Copy initialize a Point.  
	                     // The compiler will try to find a way to convert 4 to a Point, 
											 // which will invoke the Point(4, 0.0, 0.0) constructor.
  std::cout << "my_point4 is: " << my_point4 << std::endl << std::endl;

  Point my_point5{5.0, 6.0, 7.0}; // use default constructor to set to (5.0, 6.0, 7.0)
  std::cout << "my_point5 is: " << my_point5 <<  std::endl << std::endl;
  Point my_point6{my_point5};
  std::cout << "my_point6 is: " <<  my_point6 << std::endl << std::endl;

  return 0;
}

/* Output of this program:
  
The constructor has been called...
my_point1 is: Point(1, 1, 1)

The constructor has been called...
my_point2 is: Point(2, 2, 2)

The constructor has been called...
my_point3 is: Point(3, 0, 0)

The constructor has been called...
my_point4 is: Point(4, 0, 0)

The constructor has been called...
my_point5 is: Point(5, 6, 7)

my_point6 is: Point(5, 6, 7)
*/
