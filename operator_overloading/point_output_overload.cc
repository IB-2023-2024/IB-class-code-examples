/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief Overloading operator<<
 *        Overloading operator<< is similar to overloading operator+ 
 *        (they are both binary operators), except that the parameter types are different.
 *        Consider the expression 
 *
 *            std::cout << point 
 *
 *        If the operator is <<, what are the operands? 
 *        The left operand is the std::cout object, and the right operand is your Point class object.
 *        std::cout is actually an object of type std::ostream 
 *
 *        We return the left hand parameter as a reference. 
 *        This not only prevents a copy of std::ostream from being made, it also allows us to “chain” 
 *        output commands together, such as std::cout << point << std::endl;
 *
 *        You might have initially thought that since operator<< doesn’t return a value to the caller, 
 *        we should define the function as returning void. 
 *        But consider what would happen if our operator<< returned void. 
 *        When the compiler evaluates std::cout << point << std::endl;, due to the precedence/associativity 
 *        rules, it evaluates this expression as (std::cout << point) << std::endl;. 
 *        std::cout << point would call our void-returning overloaded operator<< function, which returns void. 
 *        Then the partially evaluated expression becomes: void << std::endl;, which makes no sense!
 * 
 *        By returning the out parameter as the return type instead, (std::cout << point) returns std::cout. 
 *        Then our partially evaluated expression becomes: std::cout << std::endl;, which then 
 *        gets evaluated itself!
 *
 *        Any time we want our overloaded binary operators to be chainable in such a manner, the left operand 
 *        should be returned (by reference). 
 *        Returning the left-hand parameter by reference is okay in this case --since the left-hand parameter 
 *        was passed in by the calling function, it must still exist when the called function returns. 
 *        Therefore, we don’t have to worry about referencing something that will go out of scope and 
 *        get destroyed when the operator returns.
 *
 * @see https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
 */

#include <iostream>

class Point {
 public:
  Point(double x = 0.0, double y = 0.0, double z = 0.0) : x_{x}, y_{y}, z_{z} {
    std::cout << "Point constructor has been called" << std::endl;
  }

  friend std::ostream& operator<<(std::ostream &out, const Point &point);
 private:
  double x_{};
  double y_{};
  double z_{};
};

/// because C++ already knows how to output doubles using operator<<, and our members are 
/// all doubles, we can simply use operator<< to output the member variables of our Point.
std::ostream& operator<< (std::ostream& out, const Point& point) {
  // Since operator<< is a friend of the Point class, we can access Point's members directly.
  out << "Point(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ')'; // actual output done here
  return out; // return std::ostream so we can chain calls to operator<<
}

int main() {
  const Point point1{2.0, 3.0, 4.0};
  const Point point2{5.0, 9.0, .0};
  std::cout << point1 << " " << point2 << '\n';
  return 0;
}
