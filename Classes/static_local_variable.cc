/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief static local variables
 *        Local variables have automatic duration by default, which means they are 
 *        created at the point of definition, and destroyed when the block is exited.
 *        Using the static keyword on a local variable changes its duration from automatic 
 *        duration to static duration.
 *        This means the variable is now created at the start of the program, and destroyed 
 *        at the end of the program (just like a global variable.
 *        As a result, the static variable will retain its value even after it goes out of scope!.
 *
 *        Change the local deleting the static keyword
 *
 * @see https://www.learncpp.com/cpp-tutorial/static-local-variables/
 */

#include <iostream>


void IncrementAndPrint() {
  static int value{1};  // static duration via static keyword.  This initializer is only executed once.
  ++value;
  std::cout << value << '\n';
} // value is destroyed here

int main() {
  IncrementAndPrint();
  IncrementAndPrint();
  IncrementAndPrint();

  return 0;
}
