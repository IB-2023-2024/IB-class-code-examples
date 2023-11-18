/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito Izquierdo
 * @date November 2023
 * @brief Develop a program that takes a text string as a command line and stores it in a std::string with
 *        identifier “input_string”. Next, the program has to print on the screen two other strings “one_more”
 *        and “one_less” which will be strings obtained from the first one by replacing each character of the
 *        original string with the next character in the ASCII table and with the previous one, respectively. 
 *        The program must also print each of the “input_string” characters separated by a hyphen of the ASCII 
 *        (decimal) code corresponding to the character.
 * */

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: " << argv[0] << " <cadena_de_texto>" << std::endl;
    return 1;
  }
  std::string input_string = argv[1];
  std::string one_more = input_string;
  std::string one_less = input_string;
  for (char& character : one_more) {
    character = character + 1;
  }
  for (char& character : one_less) {
    character = character - 1;
  }
  std::cout << "input_string: " << input_string << std::endl;
  std::cout << "one_more: " << one_more << std::endl;
  std::cout << "one_less: " << one_less << std::endl;
  std::cout << "Caracteres y sus códigos ASCII:" << std::endl;
  for (char character : input_string) {
    std::cout << character << "-" << (int)character << " ";
  }
  std::cout << std::endl;
  return 0;
}
