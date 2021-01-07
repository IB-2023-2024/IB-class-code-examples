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
 public:
  void SetValue1(int value) { value1_ = value; }
  int GetValue1() { return value1_; }
 private:
  int value1_{0};
  int value2_{0};
  int value3_{0};
};
 
int main() {
  Something something;
  something.SetValue1(5);
  std::cout << something.GetValue1() << '\n';
}
