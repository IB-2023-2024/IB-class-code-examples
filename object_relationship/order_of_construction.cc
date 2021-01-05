/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
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

class A {
 public:
  A() {
    std::cout << "A\n";
  }
};

class B: public A {
 public:
  B() {
    std::cout << "B\n";
  }
};

class C: public B {
 public:
  C() {
    std::cout << "C\n";
  }
};

class D: public C {
 public:
  D() {
    std::cout << "D\n";
  }
};

int main() {
  std::cout << "Constructing A: \n";
  A cA;

  std::cout << "Constructing B: \n";
  B cB;

  std::cout << "Constructing C: \n";
  C cC;

  std::cout << "Constructing D: \n";
  D cD;
}
