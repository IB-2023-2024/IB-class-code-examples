/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief namespace example
 *
 * @see http://www.cplusplus.com/doc/tutorial/namespaces/
 */

#include <iostream>

namespace fun {
  int GetMeaningOfLife() { return 42; }
} // namespace fun

namespace boring {
  int GetMeaningOfLife() { return 0; }
} // namespace boring

int main() {
  std::cout << "The answer to everything is not " << boring::GetMeaningOfLife() << " but " << fun::GetMeaningOfLife() << std::endl;
  return 0;
}
