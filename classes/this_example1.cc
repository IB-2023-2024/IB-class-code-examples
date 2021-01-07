/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief implicit parameter this
 *
 *        Member functions always has object of class as implicit parameter
 *        Implicit parameter passed in form of pointer using special variable called this
 *        Normally, we do not explicitly write “this”, however
 *
 *        Although the call to function setID() looks like it only has one argument, it actually has two! 
 *        When compiled, the compiler converts 
 *
 *            simple.setID(2); 
 *
 *            into the following:
 *
 *            setID(&simple, 2); // note that simple has been changed from an object prefix to a function argument!
 *
 *        Note that this is now just a standard function call, and the object simple 
 *        (which was formerly an object prefix) is now passed by address as an argument to the function.
 *
 *        But that’s only half of the answer. 
 *        Since the function call now has an added argument, the member function definition needs to be modified to 
 *        accept (and use) this argument as a parameter. Consequently, the following member function:
 *
 *           void setID(int id) { m_id = id; }
 *
 *           is converted by the compiler into:
 *
 *           void setID(Simple* const this, int id) { this->m_id = id; }
 *
 *        When the compiler compiles a normal member function, it implicitly adds a new parameter to the function named “this”. 
 *        The this pointer is a hidden const pointer that holds the address of the object the member function was called on.
 *
 *        There’s just one more detail to take care of. 
 *        Inside the member function, any class members (functions and variables) also need to be updated so they refer to the 
 *        object the member function was called on. 
 *        This is easily done by adding a “this->” prefix to each of them. 
 *        Thus, in the body of function setID(), id_ (which is a class member variable) has been converted to this->id_. 
 *        Thus, when “this” points to the address of simple, this->id_ will resolve to simple.id_
 *
 * @see learncpp.com/cpp-tutorial/8-8-the-hidden-this-pointer/
 */

#include <iostream>

class Simple {
 public:
  Simple(int id) : id_{ id } { }

  void setID(int id) { id_ = id; }
  int getID() { return id_; }
 private:
  int id_;
};

int main() {
  Simple simple{1};
  simple.setID(2);
  std::cout << simple.getID() << std::endl;

  Simple a{1}; // this = &a inside the Simple constructor
  Simple b{2}; // this = &b inside the Simple constructor
  a.setID(3); // this = &a inside member function setID
  b.setID(4); // this = &b inside member function setID

  return 0;
}
