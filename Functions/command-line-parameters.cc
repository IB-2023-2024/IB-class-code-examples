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
  std::cout << "No. of parameters passed: " << argc << std::endl;
  std::cout << "Parameters: " << std::endl;
  for(int i = 0; i < argc; ++i) {
    std::cout << i << " - " << argv[i]  << std::endl;
  }

  std::string program_name{argv[0]};  // Create a string object from the C-style (char* string)
  std::cout << "The program name is: " << program_name << std::endl;
  std::string parametro1{argv[1]};
  std::cout << "VALOR: " << parametro1 << std::endl;


  // How to convert a std::string into a number
  // https://www.geeksforgeeks.org/converting-strings-numbers-cc/

  return 0;
}
