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
 *        that do not modify their left operands, we will make our 
 *        overloaded comparison operators friend functions
 *    
 * @see https://www.learncpp.com/cpp-tutorial/96-overloading-the-comparison-operators/
 */


#include <iostream>
#include <string>

class Coche {
 private:
  std::string marca_;
  std::string modelo_;

 public:
  Coche(const std::string& make, const std::string& model)
        : marca_{ make }, modelo_{ model }
  { }

  friend bool operator== (const Coche &c1, const Coche &c2);
  friend bool operator!= (const Coche &c1, const Coche &c2);
};

bool operator== (const Coche &c1, const Coche &c2) {
  return (c1.marca_ == c2.marca_ && c1.modelo_ == c2.modelo_);
}

bool operator!= (const Coche &c1, const Coche &c2) {
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
