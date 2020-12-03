/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 01 Jul 2020
 * @brief lvalues rvlues, move
 *
 * Every expression is an lvalue or an rvalue
 * lvalues can be written on the left of assignment operator (=)
 * rvalues are all the other expressions
 * Explicit rvalue defined using &&
 * Use std::move(...) to explicitly convert an lvalue to an rvalue
 *
 * @see http://www.cplusplus.com/reference/utility/move/?kw=move
 * @see https://en.cppreference.com/w/cpp/utility/move
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout; 
using std::endl; 
using std::string; 
using std::vector; 

int main () {
  string hello = "hello";
  vector<string> owner;
  owner.emplace_back(hello);          // Copy
  owner.emplace_back(move(hello));    // Move
  cout << hello << endl;              // Undefined
  return 0;
}
