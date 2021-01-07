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
 *        You can also mark member functions as deleted in the derived class, 
 *        which ensures they can’t be called at all through a derived object
 *
 * @see https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
 */

#include <iostream>

class Base {
 public:
	Base(int value) : value_(value) {
	}
	int value() { return value_; }
 private:
	int value_;
};

class Derived : public Base {
 public:
	Derived(int value) : Base(value) {
	}

	int value() = delete; // mark this function as inaccessible
};

int main() {
	Derived derived(7);

	// The following won't work because value() has been deleted!
	std::cout << derived.value();

	return 0;
}
