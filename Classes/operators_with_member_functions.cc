/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 15 Dec 2020
 * @brief Overloading operators using member functions
 *        Converting a function overloaded operator to a member overloaded operator is easy:
 *        The overloaded operator is defined as a member
 *        The left parameter of the function is removed, because that parameter now becomes the implicit *this object
 *        Inside the function body, all references to the left parameter can be removed 
 *
 * @see https://www.learncpp.com/cpp-tutorial/94-overloading-operators-using-member-functions/
 */

#include <iostream>

class Cents {
 private:
  int cents_;

 public:
  Cents(int cents) { cents_ = cents; }

  // Overload Cents + int
  Cents operator+(int value);
	// getter
  int cents() const { return cents_; }
};

// note: this function is a member function!
// the cents parameter in the friend version is now the implicit *this parameter
Cents Cents::operator+(int value) {
  return Cents(cents_ + value);
}

int main() {
	Cents cents1{6};
	Cents cents2 = cents1 + 2;
	std::cout << "I have " << cents2.cents() << " cents.\n";

	return 0;
}
