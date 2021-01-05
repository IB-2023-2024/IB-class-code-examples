/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates the role of constructors in the initialization of derived classes. 
 *        There is no way to initialize id_ when we create a Derived object
          What if we want to set both cost_ and id_ when we create a Derived object?
 *        Second attempt:  
 *          - Inherited variables can still have their values changed in the body 
 *            of the constructor using an assignment
 *
 *        While this actually works in this case, it wouldn’t work if id_ were a 
 *        const or a reference (because const values and references have to be 
 *        initialized in the initialization list of the constructor). 
 *        It’s also inefficient because id_ gets assigned a value twice: 
 *        once in the initialization list of the Base class constructor, and then 
 *        again in the body of the Derived class constructor. 
 *        And finally, what if the Base class needed access to this value during construction? 
 *        It has no way to access it, since it’s not set until the Derived constructor is executed (which pretty much happens last).
 *
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
  
	Derived(double cost=0.0, int id=0) : cost_{ cost } {
    id_ = id;
		std::cout << "Constructor Derived (int) llamado" << std::endl;
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
