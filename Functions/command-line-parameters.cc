/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief The use of command line parameters
 *
 * Two-argument variant of the main function allows arbitrary number of C-style strings 
 * to be passed to program from environment in which program run
 *    argc: number of C-style strings provided to program
 *    argv: array of pointers to C-style strings
 *    argv[0] is name by which program invoked
 *    argv[argc] is guaranteed to be 0 (i.e., null pointer)
 *    argv[1] , argv[2] , . . . , argv[argc - 1] typically correspond to command line options
 *
 * Run this program: a.exe <NAME>
 *
 * @see http://www.cplusplus.com/articles/DEN36Up4/
 * 
 * The std::string constructor allow to create a std::string from a C-string:
 * @see http://www.cplusplus.com/reference/string/string/string/
 *
 */

#include <iostream>

int main(int argc, char* argv[]) {
  // Check the number of parameters
  std::cout << "No. of parameters: " << argc << std::endl;
  if (argc < 2) {
    // Tell the user how to run the program
    std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
    /* "Usage messages" are a conventional way of telling the user
    * how to run a program if they enter the command incorrectly.
    */
    return 1;
  }
  // Print the user's name:
  std::cout << argv[0] << " says hello, " << argv[1] << "!" << std::endl;

  std::string name{argv[1]};  // Create a string object from the C-style (char* string)
  std::cout << "The name is: " << name << std::endl;

  // How to convert a std::string into a number
  // https://www.geeksforgeeks.org/converting-strings-numbers-cc/

  return 0;
}
