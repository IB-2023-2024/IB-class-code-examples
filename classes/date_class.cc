/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Date class Example
 *        In addition to holding data, classes can also contain functions! 
 *        Functions defined inside of a class are called member functions (or sometimes methods). 
 *        Member functions can be defined inside or outside of the class definition. 
 *        Here we define them inside the class for simplicity.
 *
 * @see https://www.learncpp.com/cpp-tutorial/82-classes-and-class-members/
 */
#include <iostream>
 
class DateClass {
 public:
  int year_{};  // Initialize to 0
  int month_{};
  int day_{};
 
  void Print() {
    std::cout << day_ << '/' << month_ << '/' << year_ << std::endl;
  }
};
 
int main() {
  DateClass today { 2020, 12, 1 };
  today.day_ = 11;  /// use member selection operator to select a member variable of the class
  today.Print();  /// use member selection operator to call a member function of the class
  return 0;
}
