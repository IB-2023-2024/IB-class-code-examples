/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Employee class Example
 *        In addition to holding data, classes can also contain functions! 
 *        Functions defined inside of a class are called member functions (or sometimes methods). 
 *        Member functions can be defined inside or outside of the class definition. 
 *        Here we define them inside the class for simplicity.
 *
 * @see https://www.learncpp.com/cpp-tutorial/82-classes-and-class-members/
 */

#include <iostream>
#include <string>
 
class Employee {
 public:
  std::string name_{};
  int id_{};
  double wage_{};
 
  /// Print employee information to the screen
  void Print() {
    std::cout << "Name: " << name_ <<
        "  Id: " << id_ << 
        "  Wage: " << wage_ << "€" << std::endl; 
  }
};
 
int main() {
  /// Declare two employees
  Employee alex { "Alex", 1, 2500.0};
  Employee joe { "Joe", 2, 2225.0 };
  /// Print out the employee information
  alex.Print();
  joe.Print();
  return 0;
} 
