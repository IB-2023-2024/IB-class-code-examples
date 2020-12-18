/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Date class Example
 *        This is a program (client) that uses the Date class
 *
 * @see https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 */

#include <iostream>

#include "date.h"
 
int main() {
  Date today{2020, 12, 1};  // initialize using parameterized constructor (C++11)
  today.Print();  /// use member selection operator to call a member function of the class

  const Date date1{}; // initialize using default constructor
  const Date date2(2020, 12, 18); // initialize using parameterized constructor
  const Date date3{ 2020, 12, 18 }; 

  return 0;
}
