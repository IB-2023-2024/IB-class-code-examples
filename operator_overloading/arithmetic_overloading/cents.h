/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief Declaration of the Cent class
 */

#ifndef CENTS_H
#define CENTS_H

#include <iostream>

class Cents {
 public:
  Cents(int cents) : cents_{ cents } {
    std::cout << "Cents constructor has been called" << std::endl;
  }

  int cents() const { return cents_; }
 private:
  int cents_{};
};

// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know this overload exists
Cents operator+(const Cents &c1, const Cents &c2);

#endif
