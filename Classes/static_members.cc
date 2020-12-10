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
 *        In this program, Because s_value is a static member variable, s_value is shared between all objects of the class. 
 *        Consequently, first.s_value is the same variable as second.s_value. 
 *        The program shows that the value we set using first can be accessed using second!
 *
 *        static members exist even if no objects of the class have been instantiated!
 *        Much like global variables, they are created when the program starts, and destroyed when the program ends.
 *        Consequently, it is better to think of static members as belonging to the class itself, 
 *        not to the objects of the class
 *
 * @see https://www.learncpp.com/cpp-tutorial/811-static-member-variables/
 */

#include <iostream>

class Something {
 public:
  static int s_value;        // A data member should not be public!
};

int Something::s_value{ 1 };

int main() {
  Something first;
  Something second;

  first.s_value = 2;

  std::cout << first.s_value << '\n';
  std::cout << second.s_value << '\n';
  return 0;
}
