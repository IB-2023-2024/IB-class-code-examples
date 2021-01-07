/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 09 Dec 2020
 * @brief Default constructor
 *
 * @see https://www.learncpp.com/cpp-tutorial/85-constructors/
 */

#include <iostream>

class Date {
 public:
  /// Tell the compiler to create a default constructor, even if
  /// there are other user-provided constructors.
  Date() = default;

  Date(int year, int month, int day) { // normal non-default constructor
    year_ = year;
    month_ = month;
    day_ = day;
    std::cout << "Non-default constructor called" << std::endl;
  }
  /// getters 
  int year() { return year_; }
  int month() { return month_; }
  int day() { return day_; }
 private:
  int year_;
  int month_;
  int day_;
};

int main() {
  Date date{}; // calls implicit constructor
  std::cout << "Día: " << date.day() << " Mes: " << date.month() << " Año: " << date.year() << std::endl;
  Date another_date{ 2020, 12, 10 };
  std::cout << "Día: " << another_date.day() << " Mes: " << another_date.month() << " Año: " << another_date.year() << std::endl;
  return 0;
}
