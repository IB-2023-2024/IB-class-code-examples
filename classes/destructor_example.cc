/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
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
 * In this example,
 * Without explicitly-provided destructor (i.e., with destructor automatically
 * provided by compiler), memory associated with bufferPtr would not be freed
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#destructor
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 */

#include <iostream>

class MyClass {
 public:
  MyClass(int bufferSize) {              // Constructor
    // allocate some memory for buffer
    bufferPtr = new char[bufferSize];
    std::cout << "The constructor has been called. Memory allocated" << std::endl;
  }

  ~MyClass () {                           // Destructor
    // free memory previously allocated
    delete [] bufferPtr;
    std::cout << "The destructor has been called. Memory de-allocated" << std::endl;
  }

  // Additional methods here
 private:
    char* bufferPtr;                       // pointer to start of buffer
};

int main() {
  const int kMb = 1024 * 1024;

  MyClass my_object(8 * kMb);
  // Some important code that Works with the object
  return 0;
}
