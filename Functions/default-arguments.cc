/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Default arguments example
 * 
 * @see http://www.cplusplus.com/doc/tutorial/functions/
 *      Default values in parameters
 *
 * @see https://google.github.io/styleguide/cppguide.html#Default_Arguments
 */

#include <iostream> // std::cout, std::endl

using namespace std;

string SayHello(const string& to_whom = "World ") {
 return "Hello " + to_whom + "!";
}

int main () {
  cout << SayHello() << endl;
  cout << SayHello("Students") << endl;
  return 0;
}
