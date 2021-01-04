/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 01 Jul 2020
 * @brief Illustrate operator overloading for a User defined Type: Complex
 *        Considerations: access to private data; whether first operand has class type
 *        See the comments in the code
 *
 * @see http://www.cplusplus.com/doc/tutorial/templates/
 * @see https://en.cppreference.com/w/cpp/language/operators
 */

#include <iostream>

using std::cout; using std::endl;

class Complex {     // Complex number type
 public:
  Complex(double re, double im) : re_(re), im_(im) {}
  double real() const { return re_; }
  double imag() const { return im_; }
  Complex operator+(const double&);
 private:
  double re_;       // The real part
  double im_;       // The imaginary part
};

// Overload as global function
Complex operator+(const Complex& a, const double& b) {
  return Complex(a.real() + b, a.imag());
}

// Overload as member function
Complex Complex::operator+(const double& b) {
  return Complex(real() + b, imag());
}

// This can only be accomplished with global function.
Complex operator+(const double& b, const Complex& a) {
  return Complex(b + a.real(), a.imag());
}

void Func() {
  Complex a{1.0, 2.0};
  Complex b{1.0, -2.0};
  double r = 2.0;
  Complex c = a + r;        // could use global or member function
                            // operator+(a, r) or a.operator+(r)
  Complex d = r + a;        // must use global function
                            // operator+(r, a)
                            // since r.operator+(a) will not work
}

int main () {
  Func();
  return 0;
}
