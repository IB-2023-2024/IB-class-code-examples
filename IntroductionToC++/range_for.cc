/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief C++ Range for
 * 
 * The for-loop has another syntax, which is used exclusively with ranges:
 *
 * for (declaration: range) statement;
 *
 * This kind of for loop iterates over all the elements in range, where declaration 
 * declares some variable able to take the value of an element in this range. 
 * Ranges are sequences of elements, including arrays, containers, and any other type 
 * supporting the functions begin and end.
 * Range based loops usually also make use of type deduction for the type of the elements with auto.
 *
 * @see http://www.cplusplus.com/doc/tutorial/control/
 */

# include <iostream>
# include <string>

int main () {
  const std::string kHello{"Hello!"};

  for (auto c: kHello)
    std::cout << "[" << c << "]";
  std::cout << std::endl;
  return 0;
}
