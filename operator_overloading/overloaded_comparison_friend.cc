/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 15 Dec 2020
 * @brief Overloading comparison operators
 *        Because the comparison operators are all binary operators 
 *        that do not modify their left operands, we can make our 
 *        overloaded comparison operators friend functions
 *    
 * @see https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/
 */


#include <iostream>
#include <string>

class Coche {
 public:
  Coche(const std::string& marca, const std::string& modelo)
        : marca_{ marca }, modelo_{ modelo }
  { }
  friend bool operator==(const Coche& c1, const Coche& c2);
  friend bool operator!=(const Coche& c1, const Coche& c2);
 private:
  std::string marca_;
  std::string modelo_;
};

bool operator==(const Coche& c1, const Coche& c2) {
  return (c1.marca_ == c2.marca_ && c1.modelo_ == c2.modelo_);
}

// Because the result of operator!= is the opposite of operator==, we define operator!= in terms of operator==, 
// which helps keep things simpler, more error free, and reduces the amount of code we have to write.
bool operator!=(const Coche& c1, const Coche& c2) {
  return !(c1 == c2);
}

int main() {
  Coche arona{ "Seat", "Arona" };
  Coche ibiza{ "Seat", "Ibiza" };

  if (arona == ibiza)
    std::cout << "Un Arona y un Ibiza son el mismo coche.\n";
  if (arona != ibiza)
    std::cout << "Un Arona y un Ibiza no son el mismo coche.\n";

  return 0;
}
