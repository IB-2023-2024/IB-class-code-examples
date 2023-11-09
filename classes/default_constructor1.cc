/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Dec 9 2020
 * @brief Implicit constructor
 *
 * @see https://www.learncpp.com/cpp-tutorial/85-constructors/
 * @see Does the default constructor initialize built-in types?
 *      https://stackoverflow.com/a/2418195/12791643 
 * @see https://www.learncpp.com/cpp-tutorial/default-member-initialization/
 */

#include <iostream>

/// No constructor provided, so C++ creates a public default constructor for us
class Date {
 public:
  /// getters 
  /// Google Style:  accessors and mutators may be named like variables.
  int year() { return year_; }
  int month() { return month_; }
  int day() { return day_; }
 private:
  int year_;
  int month_;
  int day_;
};

int main() {
  Date date1;   /// Compiler-provided default constructor is used
                /// Here date1.? contains garbage
  std::cout << "Día: " << date1.day() << " Mes: " << date1.month() << " Año: " << date1.year() << std::endl;

  Date date2{}; /// Value initialization. Calls implicit (default) constructor
                /// Best practice: Favor value-initialization over default-initialization for class objects.
  std::cout << "Día: " << date2.day() << " Mes: " << date2.month() << " Año: " << date2.year() << std::endl;
  return 0;
}
