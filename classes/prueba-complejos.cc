/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 25 Jun 2020
 * @brief Class Example
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 */

#include <iostream>

class Complejo {
 public:
 private:
   double real_{0};
   double imaginario_{0};
};

int main() {
  double mi_double{};
  Complejo mi_complejo1{1.0, 2.0};    // 1.0 + 2.0i
  Complejo mi_complejo2{3.0, 4.0};    // 3.0 + 4.0i
  Complejo suma{mi_complejo1 + mi_complejo2};


  std::cout << mi_complejo;
  return 0;
}
