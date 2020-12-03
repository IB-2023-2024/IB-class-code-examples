/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Encapsulated classes are easier to change
 *        While this program works fine, what would happen if we 
 *        decided to rename m_value1, or change its type? 
 *        We’d break not only this program, but likely most of the 
 *        programs that use class Something as well!
 *        Encapsulation gives us the ability to change how classes are implemented without breaking all of the programs that use them.
 *
 * @see https://www.learncpp.com/cpp-tutorial/84-access-functions-and-encapsulation/
 */

#include <iostream>

class Something {
 public:
  int value1_;
  int value2_;
  int value3_;
};

int main() {
  Something something;
  something.value1_ = 5;
  std::cout << something.value1_ << '\n';
}
