/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Nov 9 2023
 * @brief A class with defined destructor
 *
 * When object reaches end of lifetime, typically some cleanup required before object passes out of existence
 * Destructor is member function that is automatically called when object reaches end of lifetime in order to perform any necessary cleanup
 * Often object may have allocated resources associated with it (e.g., memory, files, devices, network connections, processes/threads)
 * When object destroyed, must ensure that any resources associated with object are released
 * Destructors often serve to release resources associated with object
 * Destructor for class T always has name T:: ̃T
 * Destructor has no return type (not even void)
 * Destructor cannot be overloaded
 * Destructor always takes no parameters
 * If no destructor is specified, destructor automatically provided that calls destructor for each data member of class type
 * Sometimes, automatically provided destructor will not have correct behavior
 *
 * In this example, two Simple objects are instantiated and they are destroyed when they finish their lifetime 
 * 
 * @see https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#destructor
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 */

#include <iostream>

class Simple {
 public:
  Simple(const int id) : identifier_{id} {
    std::cout << "Constructing Simple " << identifier_ << '\n';
  }

  ~Simple() { // Destructor
    std::cout << "Destructing Simple " << identifier_ << '\n';
  }
  
  int getID() { return identifier_; }
 private:
  int identifier_{};
};

int main() {
    // Allocate a Simple
    Simple simple1{1}; 
    {
      Simple simple2{2};
    } // simple2 dies here

    return 0;
} // simple1 dies here
