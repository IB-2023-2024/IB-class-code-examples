/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 01 Jul 2020
 * @brief move/copy operators and constructors
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 */

#include <iostream>

using std::cout; using std::endl;

class Hmm {
  public:
  Hmm() { cout << "Default constructor" << endl; }
  Hmm(const Hmm& other) { cout << "Copy constructor" << endl; }
  Hmm(Hmm&& other) { cout << "Move constructor" << endl; }
  Hmm& operator=(const Hmm& other) {
    cout << "Copy operator " << endl; 
    return *this;
  }
  Hmm& operator=(Hmm&& other) {
    cout << "Move operator " << endl; 
    return *this;
  }
};

int main () {
  Hmm a;
  Hmm b = a;
  a = b;
  Hmm c = std::move(a);
  c = std::move(b);
  return 0;
}
