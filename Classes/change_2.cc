/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Encapsulated classes are easier to change
 *        This is an encapsulated version of this class that uses functions to access valueX_
 *
 * @see https://www.learncpp.com/cpp-tutorial/84-access-functions-and-encapsulation/
 */

#include <iostream>
 
class Something {
 private:
  int value1_;
  int value2_;
  int value3_;
 
 public:
  void setValue1(int value) { value1_ = value; }
  int getValue1() { return value1_; }
};
 
int main() {
  Something something;
  something.setValue1(5);
  std::cout << something.getValue1() << '\n';
}
