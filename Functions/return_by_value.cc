/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 2020
 * @brief Return by value
 *        It’s the simplest and safest return type to use
 *        When a value is returned by value, a copy of that value is returned to the caller
 *        You can return variables (or expressions) that involve local variables declared 
 *        within the function without having to worry about scoping issues
 *        Because the variables are evaluated before the function returns, and a copy of 
 *        the value is returned to the caller, there are no problems when the function’s 
 *        variable goes out of scope at the end of the function
 *
 * @see https://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/
 */

#include <iostream>

int DoubleValue(int number) {
  int value{number * 2};
  return value;  // A copy of value will be returned here
} // value goes out of scope here

int main() {
  int local{8};
  std::cout << "Double value: " << DoubleValue(local) << std::endl;
}
