/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 09 Dec 2020
 * @brief A Default constructor with optional parameters
 *
 * @see https://www.learncpp.com/cpp-tutorial/85-constructors/
 */

#include <iostream>

class Something {
public:
	// Default constructor
	Something(int n = 0, double d = 1.2) { // allows us to construct a Something(int, double), Something(int), or Something()
	}
};

int main() {
	Something s1 { 1, 2.4 }; // calls Something(int, double)
	Something s2 { 1 }; // calls Something(int, double)
	Something s3 {}; // calls Something(int, double)

	Something s4 = Something {2, 4.8}; // Copy initialize a Something, will call Something(2, 4.8)
	Something s5 = s4;

	Something sX { 2.4 }; // will not compile, as there's no constructor to handle Something(double)

	return 0;
}
