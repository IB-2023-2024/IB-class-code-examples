/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates how an inheritance chain works regarding initializations
 *        class C is derived from class B, which is derived from class A. 
 *        So what happens when we instantiate an object of class C?
 *        1. First, main() calls C(int, double, char). 
 *        2. The C constructor calls B(int, double). 
 *        3. The B constructor calls A(int). 
 *        4. Because A does not inherit from anybody, this is the first class we’ll construct. 
 *        5. A is constructed, prints the value 5, and returns control to B. 
 *        6. B is constructed, prints the value 4.3, and returns control to C. 
 *        7. C is constructed, prints the value ‘R’, and returns control to main(). 
 *        8. And we’re done!
 *
 *        It is worth mentioning that constructors can only call constructors from 
 *        their immediate parent/base class. 
 *        Consequently, the C constructor could not call or pass parameters to the A 
 *        constructor directly. 
 *        The C constructor can only call the B constructor (which has the responsibility of calling the A constructor).
 *
 * @see https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
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
