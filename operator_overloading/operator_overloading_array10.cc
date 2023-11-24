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
#include <array>

class Array10 { // Ten-element real array class
 public:
  Array10() {
    for (auto element : data_) {  // Constructs a "Zero array"
      element = 0;
    }
  }
  const double& operator[](int index) const { return data_[index]; }
  double& operator[](int index) { return data_[index]; }
 private:
  static const int kArraySize = 10;
  std::array<double, kArraySize> data_;  // array data
};

void Func() {
  Array10 array;
  array[1] = 3.5;          // calls Array10::operator[](int)
  double value = array[1]; // calls Array10::operator[](int)
  const Array10 other;
  // other[1] = 2.5;           // ERROR: u[1] is const
  double third = other[1];  // calls Array10::operator[](int) const
}

int main() {
  Func();
  return 0;
}
