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
  int year{};  // Initialize to 0
  int month{};
  int day{};
};

void print(const DateStruct &date) {
  std::cout << date.year << '/' << date.month << '/' << date.day;
}

int main() {
  DateStruct today { 2020, 12, 4 }; // use uniform initialization
  today.day = 5; // use member selection operator to select a member of the struct
  print(today);
  return 0;
}
