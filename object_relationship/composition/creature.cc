/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Creature class definition
 *
 * @see https://www.learncpp.com/cpp-tutorial/composition/
 */

#include <iostream>
#include <string>

#include "creature.h"

std::ostream& operator<<(std::ostream& out, const Creature &creature) {
  out << creature.name_ << " is at " << creature.location_;
  return out;
}

void Creature::moveTo(int x, int y) {
  location_.setPoint(x, y);
}
