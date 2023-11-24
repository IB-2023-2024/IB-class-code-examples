/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jul 1 2020
 * @brief Illustrate operator overloading for a User defined Type: Complex
 *        Considerations: access to private data; whether first operand has class type
 *        See the comments in the code
 *
 * @see http://www.cplusplus.com/doc/tutorial/templates/
 * @see https://en.cppreference.com/w/cpp/language/operators
 */

#include <iostream>

/**
 * @brief Comple number type
 */
class Complex {
 public:
  Complex(double real, double imaginary) : real_(real), imag_(imaginary) {}
  double real() const { return real_; }
  double imag() const { return imag_; }
  Complex operator+(const double real_number);
 private:
  double real_;       /// The real part
  double imag_;       /// The imaginary part
};

// Overload as normal (global) function
Complex operator+(const Complex& complex, const double real_number) {
  return Complex(complex.real() + real_number, complex.imag());
}

// Overload as member function (method)
Complex Complex::operator+(const double real_number) {
  return Complex(real() + real_number, imag());
}

// This can only be accomplished with global function
Complex operator+(const double real_number, const Complex& complex) {
  return Complex(real_number + complex.real(), complex.imag());
}

void Func() {
  Complex complex_a{1.0, 2.0};
  Complex complex_b{1.0, -2.0};
  double real_number = 2.0;
  Complex complex_c = complex_a + real_number;  // could use global or member function
                                                // operator+(a, r) or a.operator+(r)
  Complex complex_d = real_number + complex_a;  // must use global function
                                                // operator+(r, a)
                                                // since r.operator+(a) will not work
}

int main () {
  Func();
  return 0;
}
