/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates how to hide functionality that exists in the base class.
 *
 *        In C++, it is not possible to remove or restrict functionality 
 *        from a base class other than by modifying the source code. 
 *        However, in a derived class, it is possible to hide functionality 
 *        that exists in the base class, so that it can not be accessed 
 *        through the derived class. 
 *        This can be done simply by changing the relevant access specifier.
 *        In this code we make a public member private
 *
 * @see https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
 */

#include <iostream>

class Base {
 public:
	int value_;
};

class Derived : public Base {
 public:
	// We can't initialize value_, since it's a Base member (Base must initialize it)
	// But we can assign it a value
	Derived(int value) {
		value_ = value;
	}
 private:
	using Base::value_;
};

int main() {
	Derived derived(7);

	// The following won't work because value_ has been redefined as private
	std::cout << derived.value_;

	return 0;
}
