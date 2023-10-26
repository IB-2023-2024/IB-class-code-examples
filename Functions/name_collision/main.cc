/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Nov 7 2020
 * @brief Name collision
 * @see https://www.learncpp.com/cpp-tutorial/2-9-naming-collisions-and-an-introduction-to-namespaces/
 */

#include <iostream>

void MyFunction(int param) {
  std::cout << 2 * param;
}

int main() {
  return 0;
}
