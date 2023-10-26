/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 25 2020
 * @brief namespace example
 *        Avoid using namespace <name>
 *
 * @see http://www.cplusplus.com/doc/tutorial/namespaces/
 */

#include <iostream>
#include <cmath>

using namespace std; // std namespace is used

// Self - defined function power shadows std::pow
double pow(double base, int exponent) {
  double result = 1.0;
  for (int i{0}; i < exponent; ++i) { 
    result *= base; 
  }
  cout << "Executing our cool power function \n";
  return result;
}

int main() {
  double base{2.0};
  int exponent{10};
  double result = pow(base, exponent);
  cout << base << " ^ " << exponent << " = " << result << endl;
  return 0;
}
