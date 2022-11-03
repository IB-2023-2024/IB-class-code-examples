/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief Variables 'live' in scopes
 * 
 * There is a single global scope
 * Local scopes start with { and ends with }
 * All variables belong to the scope where they have been declared
 * All variables die in the end of their scope
 * This is the core of C++ memory system

 * @see http://www.cplusplus.com/doc/tutorial/namespaces/
 */

int main() { // Start of main scope
  double my_variable = 13.13f; // Create variable
  { // New inner scope
    auto another_variable = my_variable; // Copy variable 
  } // another_variable dies
  return 0;
} // my_variable dies
