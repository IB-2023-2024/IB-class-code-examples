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
 * @see https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/
 */

#include <iostream>

class Cents {
 public:
  Cents(int cents) { cents_ = cents; }

  // Overload Cents + int
  Cents operator+(int value);
	// getter
  int cents() const { return cents_; }
 private:
  int cents_;
};

// note: this function is a member function!
// the cents parameter we used in the friend version is now the implicit *this parameter
Cents Cents::operator+(int value) {
  return Cents(cents_ + value);
}

// The expression cents1 + 2 becomes function call cents1.operator+(2). 
// Note that there is now only one explicit function parameter, and cents1 has become an object prefix. 
// However, we know that the compiler implicitly converts an object prefix into a hidden leftmost parameter named *this. 
// So in actuality, cents1.operator+(2) becomes operator+(&cents1, 2).
int main() {
	Cents cents1{6};
	Cents cents2 = cents1 + 2;
	std::cout << "I have " << cents2.cents() << " cents.\n";

	return 0;
}
