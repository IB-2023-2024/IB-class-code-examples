/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief A Point 2D class definition
 *
 * @see https://www.learncpp.com/cpp-tutorial/composition/
 */

#include <iostream>

#include "point2D.h"

std::ostream& operator<<(std::ostream& out, const Point2D &point) {
  out << '(' << point.x_coordinate_ << ", " << point.y_coordinate_ << ')';
  return out;
}

void Point2D::SetPoint(const int x, const int y) {
  x_coordinate_ = x;
  y_coordinate_ = y;
}
