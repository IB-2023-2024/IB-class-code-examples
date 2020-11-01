/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief namespace example
 *
 * @see http://www.cplusplus.com/doc/tutorial/namespaces/
 */

#include <iostream>

using std::cout;

namespace mike {
  int someValue;
  void Initialize() {
    cout << "mike::Initialize called\n";
    someValue = 0;
  }
}

namespace fred {
  double someValue ;
  void Initialize() {
    cout << "fred::Initialize called\n";
    someValue = 1.0;
  }
}

int main() {
  mike::Initialize();    // call Initialize in namespace mike
  fred::Initialize();    // call Initialize in namespace fred

  using mike::Initialize;
  Initialize();          // call Initialize in mike namespace
}
