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
 *        NOTE: This works because dynamically allocated memory does not go out of scope at the end 
 *        of the block in which it is declared, so that memory will still exist when the address is 
 *        returned back to the caller. 
 *        Keeping track of manual allocations can be difficult. 
 *        Separating the allocation and deletion into different functions makes it even harder to 
 *        understand who’s responsible for deleting the resource or if the resource needs to be deleted at all. 
 *        Smart pointers and types that clean up after themselves should be used instead of manual allocations.
 *
 * @see https://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/
 */

int* AllocateArray(int size) {
  return new int[size];
}

int main() {
  int *array{AllocateArray(25)};
    // do stuff with array

  delete[] array;
  return 0;
}
