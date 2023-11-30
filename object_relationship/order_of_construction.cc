/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Example to illustrate the order of constructions of derived classes
 *        C++ constructs derived classes in phases, starting with the most-base 
 *        class (at the top of the inheritance tree) and finishing with the 
 *        most-child class (at the bottom of the inheritance tree)
 *        As each class is constructed, the appropriate constructor from 
 *        that class is called to initialize that part of the class

 * @see https://www.learncpp.com/cpp-tutorial/order-of-construction-of-derived-classes/
 */

#include <iostream>
#include <string>

class classA {
 public:
  classA() {
    std::cout << "classA constructor\n";
  }
};

class classB: public classA {
 public:
  classB() {
    std::cout << "classB constructor\n";
  }
};

class classC: public classB {
 public:
  classC() {
    std::cout << "classC constructor\n";
  }
};

class classD: public classC {
 public:
  classD() {
    std::cout << "classD constructor\n";
  }
};

int main() {
  std::cout << "Constructing classA: \n";
  classA object_A;

  std::cout << "Constructing classB: \n";
  classB object_B;

  std::cout << "Constructing classC: \n";
  classC object_C;

  std::cout << "Constructing classD: \n";
  classD object_D;
}
