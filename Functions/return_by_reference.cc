/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 2020
 * @brief Return by reference
 *        Values returned by reference must be variables (you should not return a reference 
 *        to a literal or an expression that resolves to a temporary value, as those will go 
 *        out of scope at the end of the function and you’ll end up returning a dangling reference).
 *        When a variable is returned by reference, a reference to the variable is passed back to the caller.
 *        The caller can then use this reference to continue modifying the variable, which can be useful at times.
 *        Return by reference is also fast, which can be useful when returning structs and classes.
 *        However, just like return by address, you should not return local variables by reference
 *
 *        Return by reference is typically used to return arguments passed by reference to the function back to the caller. 
 *        In this example, we return (by reference) an element of an array that was passed to our function by reference:
 *        
 * @see https://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/
 */

#include <array>
#include <iostream>
 
// Returns a reference to the index element of array.
// We know that array[index] will not be destroyed when we return 
// to the caller (since the caller passed in the array in the first place!)
// so it's okay to return it by reference
int& GetElement(std::array<int, 25>& array, int index) {
  return array[index];
}
 
int main() {
  std::array<int, 25> array;

  array[10] = 7;
  std::cout << array[10] << '\n';

  // Set the element of array with index 10 to the value 5
  GetElement(array, 10) = 5;
  std::cout << array[10] << '\n';
 
  return 0;
}
