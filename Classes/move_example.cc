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

using std::cout; 
using std::endl; 
using std::string; 

void Print(const string& str) {
  cout << "lvalue : " << str << endl;
}

void Print(string&& str) {
  cout << "rvalue : " << str << endl;
}

int main () {
  string hello = "hi";
  Print (hello);
  Print ("world");
  Print (std::move(hello));
  // DO NOT access "hello" after move!
  return 0;
}


