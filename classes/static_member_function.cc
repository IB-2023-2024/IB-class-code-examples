/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief static member function
 *        Static member functions are not attached to any particular object
 *        They can be called directly by using the class name and the scope resolution operator
 *        Like static member variables, they can also be called through objects of the class type, though this is not recommended
 *
 * @see https://www.learncpp.com/cpp-tutorial/812-static-member-functions/
 */

#include <iostream>

class IDGenerator {
 public:
  static int getNextID(); // Declaration for a static function
 private:
  static int next_ID; // Declaration for a static member
};

// Here's the definition of the static member outside the class.  
// Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::next_ID{ 1 };

// Here's the definition of the static function outside of the class.  
// Note we don't use the static keyword here.
int IDGenerator::getNextID() { return next_ID++; }

int main() {
  for (int count{0}; count < 5; ++count) {
    std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';
  // The method is called without any object instance
	}
  return 0;
}
