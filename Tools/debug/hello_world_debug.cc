/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author MS Visual Studio
 * @brief A simple program to begin working with VSC
 * @see https://code.visualstudio.com/docs/cpp/config-linux
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

  for (const string& word : msg) {
    cout << word << " ";
  }
  cout << endl;
}
