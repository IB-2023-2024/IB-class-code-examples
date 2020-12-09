/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 09 Dec 2020
 * @brief Implicit constructor
 *
 * @see https://www.learncpp.com/cpp-tutorial/85-constructors/
 */

#include <iostream>

class Date {
 private:
  int year_{ 2020 };
  int month_{ 12 };
  int day_{ 10 };
  // No constructor provided, so C++ creates a public default constructor for us
};

int main() {
  Date date{}; // calls implicit constructor
  return 0;
}
