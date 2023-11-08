/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 25 2020
 * @brief struct Example
 *         structs represent the traditional non-object-oriented programming world, 
 *         as they can only hold data. 
 *
 * @see https://www.learncpp.com/cpp-tutorial/82-classes-and-class-members/
 */

#include <iostream>

struct DateStruct {
  int year{};  /// Initialize to 0
  int month{};
  int day{};
};

void Print(const DateStruct& date) {
  std::cout << date.day << '/' << date.month << '/' << date.year << std::endl;
}

int main() {
  DateStruct mi_fecha{2023, 11, 2}; /// use uniform initialization
  mi_fecha.day= 18; /// use member selection operator to select a member of the struct
  Print(mi_fecha);
  return 0;
}
