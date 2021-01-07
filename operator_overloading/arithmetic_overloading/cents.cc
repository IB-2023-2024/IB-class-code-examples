/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief Overloading of arithmetic operators. Client code
 * @see https://www.learncpp.com/cpp-tutorial/9-2a-overloading-operators-using-normal-functions/
 */

#include "cents.h"
 
// note: this function is not a member function nor a friend function!
Cents operator+(const Cents &c1, const Cents &c2) {
  // use the Cents constructor and operator+(int, int)
  // we don't need direct access to private members here
  return {c1.cents() + c2.cents()};
}
