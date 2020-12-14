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
 *        In this example, the local variable x goes out of scope when GetX returns. 
 *        GetX is returning a reference to a value that will be destroyed when the function returns.
 *        Therefore r is a dangling reference. 
 *        This would mean the caller receives a reference to garbage. 
 *        Fortunately, your compiler will probably give you a warning or error if you try to do this.
 *        This program has undefined behavior, although it may appear to work and print 42 in some cases.
 *
 *        The compiler generates a warning message:
 *        dangling_reference.cc: In function ‘int& GetX()’:
 *        dangling_reference.cc::10: warning: reference to local variable ‘x’ returned [-Wreturn-local-addr]
 *              |   return x;
 *              |          ^
 *
 * @see https://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/
 * @see https://stackoverflow.com/questions/46011510/what-is-a-dangling-reference
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
