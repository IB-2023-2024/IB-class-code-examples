/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Sample code to illustrate debugging with VSC
 *
 * @see https://code.visualstudio.com/docs/cpp/config-linux#_debug-helloworldcpp
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

  for (const std::string& word : msg) {
    cout << word << " ";
  }
  cout << endl;
}
