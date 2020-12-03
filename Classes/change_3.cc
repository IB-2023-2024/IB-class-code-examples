/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Encapsulated classes are easier to change
 *        Now, let’s change the class’s implementation:
 *        
 * @see https://www.learncpp.com/cpp-tutorial/84-access-functions-and-encapsulation/
 */

#include <iostream>
 
class Something {
private:
  int value_[3]; // note: we changed the implementation of this class!
 
public:
  // We have to update any member functions to reflect the new implementation
  void setValue1(int value) { value_[0] = value; }
  int getValue1() { return value_[0]; }
};
 
int main() {
  // But our program still works just fine!
  Something something;
  something.setValue1(5);
  std::cout << something.getValue1() << '\n';
}
