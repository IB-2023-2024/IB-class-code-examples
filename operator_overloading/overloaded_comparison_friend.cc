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
  Coche(const std::string& marca, const std::string& modelo) : marca_{ marca }, modelo_{ modelo } { }
  friend bool operator==(const Coche& c1, const Coche& c2);
  friend bool operator!=(const Coche& c1, const Coche& c2);
 private:
  std::string marca_;
  std::string modelo_;
};

// Dos coches son iguales si son de la misma marca y modelo
bool operator==(const Coche& c1, const Coche& c2) {
  return (c1.marca_ == c2.marca_ && c1.modelo_ == c2.modelo_);
}

// Puesto que el resultado de operator!= es el opuesto de operator==, 
// se definirá operator!= en función de operator==, esto es:
// Dos coches son distinsot si no son iguales
// Esta aproximación hace todo más simple, libre de error y reduce la cantidad de código a escribir.
bool operator!=(const Coche& c1, const Coche& c2) {
  return !(c1 == c2);
}

int main() {
  Coche ateca{"Seat", "Ateca"};
  Coche ibiza{"Seat", "Ibiza"};
  
  if (ateca == ibiza) std::cout << "Un Ateca y un Ibiza son el mismo coche.\n";
  if (ateca != ibiza) std::cout << "Un Ateca y un Ibiza no son el mismo coche.\n";
  return 0;
}
