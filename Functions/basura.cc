/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 28 2022
 * @brief Check the correct number of parameters for a program
 *
 */

#include <iostream>

void PrintProgramPurpose() {
  std::cout << "Any program should start its execution with an informative message" << std::endl;
  std::cout << "(like this) that informs the user about the purpose of the program." << std::endl;
  std::cout << "After printing that message, the program should check that the user" << std::endl;
  std::cout << "has provided the correct number of parameters to the program." << std::endl << std::endl;
}

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber) {
  if (argc != kCorrectNumber) {
    std::cout << "This program has been executed with a wrong number of parameters" << std::endl << std::endl;
    std::cout << "This program should be called" << argv[0] << " param1 param2" << std::endl;
    std::cout << "param1: " << " An integer number meaning bla, bla, bla" << std::endl;
    std::cout << "param2: " << " A string representing la, bla, bla" << std::endl;
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  PrintProgramPurpose();
  if (!CheckCorrectParameters(argc, argv, 3)) {
    return 345;
  }
  std::cout << "Everything is fine!. Lets continue with the normal execution..." << argc << std::endl;
  return 0;
}
