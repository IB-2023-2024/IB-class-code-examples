/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author F. de Sande
 * @date Oct 25 2021
 * @brief Test program to use as input in the Regular Expressions lab assignment
 */

#include <iostream>
#include <string>
#include "empty.h"

class Image {
 public:
  Image(const std::string& file_name);
  void Draw();      /// Function Member
 private:
  int rows_{0};    /// Data members
  int cols_{0};
};

int main () {
  const std::string kHello{"Hello!"};

  for (auto character: kHello) {  // character will be a copy of the current string element (char)
    std::cout << "[" << character << "]";
  }
  std::cout << std::endl;
	std::string array[]{ "En", "un", "lugar", "de", "la", "Mancha", "de", "cuyo","nombre", "no","quiero", "..." };
  for (const auto &element: array) { // element is a const reference to the currently iterated array element
    std::cout << element << ' ';
  }
  while(false) {
    int my_var;
    ;
  }
  std::cout << std::endl;
  return 0;
}
