/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
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
  Point2D() : x_{ 0 }, y_{ 0 } { 
  }

  // A specific constructor
  Point2D(int x, int y) : x_{ x }, y_{ y } {
  }

  // An overloaded output operator
  friend std::ostream& operator<<(std::ostream& out, const Point2D &point);

  // Access functions
  void setPoint(int x, int y);
 private:
  int x_;
  int y_;
};

#endif
