/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Illustrates the role of constructors in the initialization of derived classes. 
 *        What happens when Derived is instantiated:
 *        1. Memory for derived is set aside (enough for both the Base and Derived portions)
 *        2. The appropriate Derived constructor is called
 *        3. The Base object is constructed first using the appropriate Base constructor.
 *           If no base constructor is specified, the default constructor will be used
 *        4. The initialization list initializes variables
 *        5. The body of the constructor executes
 *        6. Control is returned to the caller
 *
 * @see https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
 */

#include <iostream>

class Base {
 public:
  Base(int id = 0) : id_{ id } {
    std::cout << "Constructor Base(int) llamado" << std::endl;
  }
  int id() const { return id_; }
  int id_;
};

class Derived: public Base {
 public:
  Derived(double cost = 0.0) : cost_{ cost } {
    std::cout << "Constructor Derived(double) llamado" << std::endl;
  }
  double cost() const { return cost_; }
  double cost_;
};

int main() {
  Base base{5}; // use Base(int) constructor
                
  Derived derived{1.3}; // use Derived(double) constructor
  std::cout << "Derived Id: " << derived.id() << '\n';
  std::cout << "Derived Cost: " << derived.cost() << '\n';
  return 0;
}
