/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Date class Implementation
 *        Having all the member function definitions inside the class can make the class harder to manage and work with
 *        It’s common to separate class declaration / implementation
 *        For classes used in multiple files, or intended for general reuse, 
 *        define them in a .h file that has the same name as the class
 *        Trivial member functions (trivial constructors or destructors, access functions, etc…) can be defined inside the class.
 *        Non-trivial member functions should be defined in a .cc file that has the same name as the class.
 *
 * @see https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 */

#include <iostream>
#include <sstream>
#include <string>

#include "date.h"

// Overloaded insertion operator
std::ostream& operator<< (std::ostream &out, const Date& date) {
 out << date.day() << "/" << date.month() << "/" << date.year(); // actual output done here
 return out; // return std::ostream so we can chain calls to operator<<
}


// Convierte una Fecha en string
std::string ToString(const Date date) {
	std::string resultado{""};
  std::stringstream os;

	// resultado = resultado + date.day() + "/" + date.month() + "/" + date.year();
	os << date.day() << "/" << date.month() << "/" << date.year();
  os >> resultado;

	return resultado;
}

bool operator== (const Date &d1, const Date &d2) {
  return (d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year());
}

bool operator> (const Date &d1, const Date &d2) {
	if (d1.year() > d2.year()) {
		return true;
	}
	if ((d1.year() == d2.year()) && (d1.month() > d2.month())) {
		return true;
	}
	if ((d1.year() == d2.year()) && (d1.month() == d2.month()) && (d1.day() > d2.day())) {
		return true;
	}
	return false;
}


