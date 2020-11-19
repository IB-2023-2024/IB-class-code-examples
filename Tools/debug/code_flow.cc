/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Debugging tactic #2: Validating your code flow
 * Another problem common in more complex programs is that the program is calling 
 * a function too many or too few times (including not at all).
 * In such cases, it can be helpful to place statements at the top of your functions to print the function’s name. 
 * That way, when the program runs, you can see which functions are getting called.
 *
 * @see https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
 */

#include <iostream>
 
int getValue() {
std::cerr << "getValue() called" << std::endl;
  return 4;
}
 
int main() {
std::cerr << "main() called" << std::endl;
  std::cout << getValue;
  return 0;
}
