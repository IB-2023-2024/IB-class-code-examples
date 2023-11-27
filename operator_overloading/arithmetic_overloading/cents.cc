/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 10 2020
 * @brief Overloading of arithmetic operators. 
 * @see https://www.learncpp.com/cpp-tutorial/9-2a-overloading-operators-using-normal-functions/
 */

#include "cents.h"

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents& cents1, const Cents& cents2) {
  // we don't need direct access to private members here
  return Cents{cents1.cents() + cents2.cents()};
}
