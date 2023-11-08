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

  Date(const int year, const int month, const int day) { // normal non-default constructor
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
  Date date1;
  std::cout << "Día: " << date1.day() << " Mes: " << date1.month() << " Año: " << date1.year() << std::endl;
  Date date2{}; // calls implicit constructor
  std::cout << "Día: " << date2.day() << " Mes: " << date2.month() << " Año: " << date2.year() << std::endl;
  Date another_date{2023, 11, 10}; // Calls user provided constructor
  std::cout << "Día: " << another_date.day() << " Mes: " << another_date.month() << " Año: " << another_date.year() << std::endl;
  return 0;
}
