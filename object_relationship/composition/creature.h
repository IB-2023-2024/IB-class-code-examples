/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Creature class declaration
 *
 * @see https://www.learncpp.com/cpp-tutorial/composition/
 */

#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

#include "point2D.h"

class Creature {
 public:
  Creature(const std::string& name, const Point2D& location) : name_{ name }, position_{ location } { }
  friend std::ostream& operator<<(std::ostream& out, const Creature &creature);
  void moveTo(const int x, const int y);
 private:
  std::string name_;
  Point2D position_;
};
#endif
