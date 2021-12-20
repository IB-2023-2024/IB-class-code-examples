/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 15 Dec 2020
 * @brief Overloading comparison operators
 *        Implementation using normal functions
 *        The funcion needs a getter to access the Coche data members
 *    
 * @see https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/
 */

#include <iostream>
#include <string>

class Coche {
 public:
  Coche(const std::string& marca, const std::string& modelo) : marca_{ marca }, modelo_{ modelo } { }
  // Getters
  std::string marca() const { return marca_; } 
  std::string modelo() const { return modelo_; } 
 private:
  std::string marca_;
  std::string modelo_;
};

bool operator==(const Coche& c1, const Coche& c2) {
  return (c1.marca() == c2.marca() && c1.modelo() == c2.modelo());
}


// Puesto que el resultado de operator!= es el opuesto de operator==, 
// se definirá operator!= en función de operator==, esto es:
// Dos coches son distinsot si no son iguales
// Esta aproximación hace todo más simple, libre de error y reduce la cantidad de código a escribir.
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
