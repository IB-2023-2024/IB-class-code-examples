/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 01 Jul 2020
 * @brief Illustrate operator overloading for a User defined Type: 2D Vector
 *        See the comments in the code
 *
 * @see http://www.cplusplus.com/doc/tutorial/templates/
 * @see https://en.cppreference.com/w/cpp/language/operators
 */

#include <iostream>

using std::cout; using std::endl;

class Array10 { // Ten-element real array class
 public:
  static const int kArraySize = 10;
  Array10 () {
    for (int i = 0; i < kArraySize; ++i) {  // Zero array
      data_[i] = 0;
    }
  }

  const double& operator[](int index) const {
    return data_[index];
  }

  double& operator[](int index) {
    return data_[index];
  }

 private:
  double data_[kArraySize]; // array data
};

void Func () {
  Array10 v;
  v[1] = 3.5;           // calls Array10::operator[](int)
  double c = v[1];      // calls Array10::operator[](int)
  const Array10 u;
  u[1] = 2.5;          // ERROR: u[1] is const
  double d = u[1];     // calls Array10::operator[](int) const
}

int main () {
  Func();
  return 0;
}
