/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief If statement
 *
 * Modify the code to study different versions of the Conditional Statement
 *
 * @see http://www.cplusplus.com/doc/tutorial/control/
 */

#include <iostream>

int main () {
  const int kNumber{100};  // Play modifying this value

  // Version 1
  if (kNumber > 0)
    std::cout << "V1 The number is positive" << std::endl;

  // Version 2: if-else
  if (kNumber > 0)
    std::cout << "V2 The number is positive" << std::endl;
  else if (kNumber < 0)
    std::cout << "V2 The number is negative" << std::endl;

  // Version 3: if-else-if
  if (kNumber > 0)
    std::cout << "V3 The number is positive" << std::endl;
  else if (kNumber < 0)
    std::cout << "V3 The number is negative" << std::endl;
  else
    std::cout << "V3 The number is 0";
}
