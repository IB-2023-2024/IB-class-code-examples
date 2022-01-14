/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief A Point 2D class definition
 *
 * @see https://www.learncpp.com/cpp-tutorial/composition/
 */

#include <iostream>

#include "point2D.h"

std::ostream& operator<<(std::ostream& out, const Point2D &point) {
  out << '(' << point.x_ << ", " << point.y_ << ')';
  return out;
}

void Point2D::SetPoint(const int x, const int y) {
  x_ = x;
  y_ = y;
}
