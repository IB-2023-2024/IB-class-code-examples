/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Nov 3 2023
 * @brief Encapsulated classes are easier to change
 *        Now, let’s change the class’s implementation:
 *        
 * @see https://www.learncpp.com/cpp-tutorial/84-access-functions-and-encapsulation/
 */

#include <iostream>
#include <array>
 
class Something {
 public:
  // We have to update any member functions to reflect the new implementation
  void SetValue1(const int value) { value_[0] = value; }
  int GetValue1() { return value_[0]; }
 private:
  std::array<int, 3> value_; // note: we changed the implementation of this class!
};
 
int main() {
  // But our (client) program still works just fine!
  Something something;
  something.SetValue1(5);
  std::cout << something.GetValue1() << '\n';
}
