/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 23 2020
 * @brief File input. Read lines from file
 *        The extraction operator breaks on whitespace. 
 *        If you use:
 *         input_file >> strInput;
 *        for reading, instead of using getline(), you'll read words.
 *        Try it.
 *
 * @see https://www.learncpp.com/cpp-tutorial/186-basic-file-io/
 */

#include <fstream>
#include <iostream>
#include <string>

int main() {
  // ifstream is used for reading files
  // We'll read from a file called Manolito.txt
  std::ifstream input_file{"Manolito.txt"};
 
  // If we couldn't open the input file stream for reading
  if (!input_file) {
    std::cerr << "Uh oh, Manolito.txt could not be opened for reading!\n";
    return 1;
  }
 
  // While there's still stuff left to read
  while (input_file) {
    // read stuff from the file into a string and print it
    std::string strInput;
    std::getline(input_file, strInput);  // Try using  input_file >> strInput;
    std::cout << strInput << '\n';
  }
  
  return 0;
  // When input_file goes out of scope, the ifstream
  // destructor will close the file
}
