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
 *        Third attempt:  
 *          - To explicitly choose which Base class constructor will be called, 
 *            simply add a call to the base class Constructor in the initialization 
 *            list of the derived class
 *        The code uses the base class constructor Base(int) to initialize id_ to 5, 
 *        and the derived class constructor will be used to initialize cost_ to 1.3!
 *        The details of the process are:
 *          1. Memory for derived is allocated.
 *          2. The Derived(double, int) constructor is called, where cost = 1.3, and id = 5
 *          3. The compiler looks to see if we’ve asked for a particular Base class constructor. We have! So it calls Base(int) with id = 5.
 *          4. The base class constructor initialization list sets id_ to 5
 *          5. The base class constructor body executes, which does nothing
 *          6. The base class constructor returns
 *          7. The derived class constructor initialization list sets cost_ to 1.3
 *          8. The derived class constructor body executes, which does nothing
 *          9. The derived class constructor returns
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
  
 // Call Base(int) constructor with value id!
 Derived(double cost = 0.0, int id = 0) : Base{ id }, cost_{ cost } {
		std::cout << "Constructor Derived (double, int) llamado" << std::endl;
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
