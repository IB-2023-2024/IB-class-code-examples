/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 3 2020
 * @brief User-defined namespaces
 * @see https://www.learncpp.com/cpp-tutorial/user-defined-namespaces/
 */

#include <iostream>

namespace foo {  // define a namespace named foo
  // This doSomething() belongs to namespace foo
  int DoSomething(int first, int second) {
    return first + second;
  }
}

namespace goo { // define a namespace named goo
  // This doSomething() belongs to namespace goo
  int DoSomething(int first, int second) {
    return first - second;
  }
}

int main() {
  std::cout << foo::DoSomething(4, 3) << '\n'; // use the DoSomething() that exists in namespace foo
  std::cout << goo::DoSomething(4, 3) << '\n'; // use the DoSomething() that exists in namespace goo
  return 0;
}
