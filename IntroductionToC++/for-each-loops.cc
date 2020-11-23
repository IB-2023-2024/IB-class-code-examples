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
 * @see https://www.learncpp.com/cpp-tutorial/6-12a-for-each-loops/
 */

#include <iostream>
#include <string>

int main () {
  const std::string kHello{"Hello!"};

  for (auto character: kHello)  // character will be a copy of the current string element (char)
    std::cout << "[" << character << "]";
  std::cout << std::endl;


	// In the previous example each string element iterated over will be copied into variable c. 
	// Copying (string, array, vector, ...)  elements can be expensive, and most of the time we 
	// really just want to refer to the original element. 
	// Fortunately, we can use references for this
	// And, of course, it’s a good idea to make your reference const if you’re 
	// intending to use it in a read-only fashion:
  const int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
  for (const auto& number : fibonacci) { // type is auto, so number has its type deduced from the fibonacci array
    std::cout << number << ' ';
  }
  return 0;
}
