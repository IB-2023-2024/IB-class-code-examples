/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates the role of constructors in the initialization of derived classes. 
 * @see https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
 */

#include <iostream>

class Base {
 public:
  int id_;

  Base(int id = 0) : id_{ id } {
		std::cout << "Constructor Base(int) llamado" << std::endl;
  }

  int getId() const { return id_; }
};

class Derived: public Base {
 public:
  double cost_;

  Derived(double cost = 0.0) : cost_{ cost } {
		std::cout << "Constructor Derived(double) llamado" << std::endl;
  }

  double getCost() const { return cost_; }
};

int main() {
  Base base{5}; // use Base(int) constructor

  Derived derived{1.3}; // use Derived(double) constructor
	std::cout << "Derived Id: " << derived.getId() << '\n';
  std::cout << "Derived Cost: " << derived.getCost() << '\n';

  return 0;
}
