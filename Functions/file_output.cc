/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 23 2020
 * @brief File output
 *
 * @see https://www.learncpp.com/cpp-tutorial/186-basic-file-io/
 */

#include <fstream>
#include <iostream>

int main() {
  // ofstream is used for writing files
  // We'll make a file called Manolito.txt
  std::ofstream output_file{"Manolito.txt"};

  // If we couldn't open the output file stream for writing
  if (!output_file) {
    std::cerr << "Uh oh, Manolito.txt could not be opened for writing!" << std::endl;
    return 1;
  }

  // We'll write two lines into this file
  output_file << "This is line 1" << std::endl;
  output_file << "This is line 2" << std::endl;

  return 0;
  // When output_file goes out of scope, the ofstream
  // destructor (to be studied later) will close the file
}
