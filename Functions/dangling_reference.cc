/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 2020
 * @brief Dangling reference Example
 *        It is illegal to access a reference to an object that has gone out of scope or been otherwise destroyed. 
 *        Such a reference is said to be dangling ("colgada") since it no longer refers to a valid object.
 *
 *        In this example, the local variable x goes out of scope when getX returns. 
 *        Therefore r is a dangling reference. 
 *        This program has undefined behavior, although it may appear to work and print 42 in some cases.
 *
 *        The compiler generates a warning message:
 *        dangling_reference.cc: In function ‘int& GetX()’:
 *        dangling_reference.cc:29:10: warning: reference to local variable ‘x’ returned [-Wreturn-local-addr]
 *           30 |   return x;
 *              |          ^
 *
 * @see https://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/
 */

#include <iostream>

int& GetX() {
  int x = 42;
  return x;
}

int main() {
  int& r = GetX();
  std::cout << r << "\n";
}
