/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief static member variables
 *        Why use static variables inside classes? 
 *        One great example is to assign a unique ID to every instance of the class. Here’s an example
 *
 *        Because s_idGenerator_ is shared by all Something objects, when a new Something object is created, 
 *        the constructor grabs the current value out of s_idGenerator and then increments the value for the next object. 
 *        This guarantees that each instantiated Something object receives a unique id (incremented in the order of creation). 
 *        This can really help when debugging multiple items in an array, as it provides a way to tell multiple objects 
 *        of the same class type apart!
 * 
 *        Static member variables can also be useful when the class needs to utilize an internal lookup table 
 *        (e.g. an array used to store a set of pre-calculated values). 
 *        By making the lookup table static, only one copy exists for all objects, rather than making a copy for each object instantiated. 
 *        This can save substantial amounts of memory.
 *
 * @see https://www.learncpp.com/cpp-tutorial/811-static-member-variables/
 */

#include <iostream>

class Something {
 public:
  Something() { id_ = id_Generator_++; } // grab the next value from the id generator
  int GetID() const { return id_; }
 private:
  static int id_Generator_;
  int id_;
};

// Note that we're defining and initializing s_idGenerator even though it is declared as private above.
// This is okay since the definition isn't subject to access controls.
int Something::id_Generator_ = 1; // start our ID generator with value 1

int main() {
  Something first;
  Something second;
  Something third;

  std::cout << first.GetID() << '\n';
  std::cout << second.GetID() << '\n';
  std::cout << third.GetID() << '\n';
  return 0;
}
