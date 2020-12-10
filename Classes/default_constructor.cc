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
 private:
  int year_{ 2020 };
  int month_{ 12 };
  int day_{ 10 };

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
};

int main() {
  Date date{}; // calls implicit constructor
  Date another_date{ 2020, 12, 10 };
  return 0;
}
