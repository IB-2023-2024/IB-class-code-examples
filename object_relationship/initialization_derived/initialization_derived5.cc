/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates the role of constructors in the initialization of derived classes. 
 *        As we know how to initialize base class members, there’s no need to keep 
 *        our member variables public (they should be private!)
 *        We make our member variables private again, as they should be
 *        Remember:
 *         - Public members can be accessed by anybody
 *         - Private members can only be accessed by member functions of the same class
 *        Derived classes can not access private members of the base class directly! 
 *        Derived classes will need to use access functions to access private members of the base class
 *
 * @see https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
 */

#include <iostream>

class Base {
 public:
  Base(int id = 0) : id_{id} {
		std::cout << "Constructor Base(int) llamado" << std::endl;
  }

  int getId() const { return id_; }
 private:
  int id_;
};

class Derived: public Base {
 public:
 Derived(double cost = 0.0, int id = 0) : Base{ id }, cost_{ cost } {
		std::cout << "Constructor Derived (double, int) llamado" << std::endl;
 }

  double getCost() const { return cost_; }
 private:
  double cost_;
};

int main() {
  Base base{5}; // use Base(int) constructor

  Derived derived{1.3, 99}; // use Derived(double) constructor
	std::cout << "Derived Id: " << derived.getId() << '\n';
  std::cout << "Derived Cost: " << derived.getCost() << '\n';

  return 0;
}
