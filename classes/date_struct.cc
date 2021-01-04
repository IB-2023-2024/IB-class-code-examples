/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
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

void Print(const DateStruct &date) {
  std::cout << date.day << '/' << date.month << '/' << date.year << std::endl;
}

int main() {
  DateStruct today { 2020, 12, 4 }; /// use uniform initialization
  today.day = 11; /// use member selection operator to select a member of the struct
  Print(today);
  return 0;
}
