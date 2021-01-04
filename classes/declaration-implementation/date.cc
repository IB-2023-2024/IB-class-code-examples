/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Date class Implementation
 *        Having all the member function definitions inside the class can make the class harder to manage and work with
 *        It’s common to separate class declaration / implementation
 *        For classes used in multiple files, or intended for general reuse, 
 *        define them in a .h file that has the same name as the class
 *        Trivial member functions (trivial constructors or destructors, access functions, etc…) can be defined inside the class.
 *        Non-trivial member functions should be defined in a .cc file that has the same name as the class.
 *
 * @see https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 */

#include <iostream>

#include "date.h"

/// Date constructor
Date::Date(int year, int month, int day) {
  SetDate(year, month, day);
}

/// Date member function
void Date::SetDate(int year, int month, int day) {
  month_ = month;
  day_ = day;
  year_ = year;
}

/// Date member function 
void Date::Print() {
  std::cout << day_ << '/' << month_ << '/' << year_ << std::endl;
}
