/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief static member variables
 *        Member variables of a class can be made static by using the static keyword
 *        Unlike normal member variables, static member variables are shared by all objects of the class
 *
 *        In this program, Because s_value_ is a static member variable, s_value_ is shared between all objects of the class. 
 *        Consequently, first.s_value_ is the same variable as second.s_value_. 
 *        The program shows that the value we set using first can be accessed using second!
 *
 *        static members exist even if no objects of the class have been instantiated!
 *        Much like global variables, they are created when the program starts, and destroyed when the program ends.
 *        Consequently, it is better to think of static members as belonging to the class itself, 
 *        not to the objects of the class.
 *
 *        When we declare a static member variable inside a class, we’re telling 
 *        the compiler about the existence of a static member variable, but not 
 *        actually defining it (much like a forward declaration). 
 *        Because static member variables are not part of the individual class 
 *        objects (they are treated similarly to global variables, and get initialized 
 *        when the program starts), you must explicitly define the static member outside 
 *        of the class, in the global scope.
 *
 *        In this code the static member is defined in the line: i
 *            int Something::s_value_{ 1 };
 *
 * @see https://www.learncpp.com/cpp-tutorial/811-static-member-variables/
 */

#include <iostream>

class Something {
 public:
  static int s_value_;        // A data member should not be public!
};

int Something::s_value_{ 1 };

int main() {
  Something first;
  Something second;

  first.s_value_ = 1000;

  std::cout << first.s_value_ << '\n';
  std::cout << second.s_value_ << '\n';
  return 0;
}
