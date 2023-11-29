/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief A Point 2D class declaration
 *
 * @see https://www.learncpp.com/cpp-tutorial/composition/
 */

#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D {
 public:
  // A default constructor
  Point2D() : x_coordinate_{ 0 }, y_coordinate_{ 0 } { }

  // A specific constructor
  Point2D(const int x, const int y) : x_coordinate_{ x }, y_coordinate_{ y } { }

  // An overloaded output operator
  friend std::ostream& operator<<(std::ostream& out, const Point2D &point);

  // Access functions
  void SetPoint(const int x, const int y);
 private:
  int x_coordinate_;
  int y_coordinate_;
};

#endif
