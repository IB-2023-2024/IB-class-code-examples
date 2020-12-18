/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 18 Dec 2020
 * @brief Tests Unitarios con la plataforma gtest
 *        Definición de la función SquareRoot que calcula la raíz cuadrada de su argumento
 *
 * @see   Nan check: https://stackoverflow.com/questions/570669/checking-if-a-double-or-float-is-nan-in-c
 */

#include <cmath>

double SquareRoot(const double a) {
  double sqrta = sqrt(a);
  if(sqrta != sqrta) { // nan check
    return -1.0;
  } else {
    return sqrta;
  }
}
