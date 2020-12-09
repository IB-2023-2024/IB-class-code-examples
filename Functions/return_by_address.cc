/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 2020
 * @brief Return by address
 *        Returning by address involves returning the address of a variable to the caller
 *        Return by address can only return the address of a variable, not a literal or an expression (which don’t have addresses)
 *        Because return by address just copies an address from the function to the caller, return by address is fast
 *        Return by address was often used to return dynamically allocated memory to the caller
 *
 * @see https://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/
 */

int* AllocateArray(int size) {
  return new int[size];
}

int main() {
  int *array{ allocateArray(25) };
    // do stuff with array

  delete[] array;
  return 0;
}
