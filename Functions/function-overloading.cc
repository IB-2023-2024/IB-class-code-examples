/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Function overloading example
 * 
 * There are 2 Func implementations
 * The compiler decides which function to invoke in terms of the type of argument passed
 */

#include <iostream>
#include <string>

using namespace std;

string Func(int num) { 
  return "int"; 
}

string Func(const string& str) { 
  return "string"; 
}

string Func(double number) { 
  return "It's a double"; 
}

int main () {
  cout << Func(1) << endl;
  cout << Func("hello") << endl;
  cout << Func(1.0) << endl;
  return 0;
}
