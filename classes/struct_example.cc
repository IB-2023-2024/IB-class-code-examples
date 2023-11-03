/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 25 2020
 * @brief struct example
 *
 * struct is a class where everything is public
 * Use struct as a simple data container, if it needs a function it should be a class instead
 *
 * Always initialize structs using braced initialization
 *
 * @see http://www.cplusplus.com/doc/tutorial/structures/
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see https://google.github.io/styleguide/cppguide.html#Structs_vs._Classes
 */

#include <iostream>
#include <string>

// Define a structure
struct NamedInt {
  int number;
  std::string name;
};

void PrintStruct(const NamedInt& named_int) {
  std::cout << named_int.name << " " << named_int.number << std::endl;
}

int main() {
  NamedInt number{1, "hello"};
  PrintStruct(number);
  PrintStruct({10 , "world"});
  return 0;
}
