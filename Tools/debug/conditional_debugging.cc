/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Debugging tactic #3: Printing values
 * When you’re done with the debugging statement, you’ll either need to remove them, or comment them out. 
 * Then if you want them again later, you’ll have to add them back, or uncomment them.
 * One way to make it easier to disable and enable debugging throughout your program is to make 
 * your debugging statements conditional using preprocessor directives:
 *
 * @see https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
 */

#include <iostream>

//#define ENABLE_DEBUG // comment out to disable debugging

int getUserInput() {
#ifdef ENABLE_DEBUG
std::cerr << "getUserInput() called" << std::endl;
#endif
  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;
  return x;
}

int main() {
#ifdef ENABLE_DEBUG
std::cerr << "main() called" << std::endl;
#endif
  int x{ getUserInput() };
  std::cout << "You entered: " << x << std::endl;

  return 0;
}
