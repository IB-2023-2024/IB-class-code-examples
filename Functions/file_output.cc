/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief File output
 *
 * @see https://www.learncpp.com/cpp-tutorial/186-basic-file-io/
 */

#include <fstream>
#include <iostream>

int main() {
  // ofstream is used for writing files
  // We'll make a file called Sample.txt
  std::ofstream outf{"Sample.txt"};

  // If we couldn't open the output file stream for writing
  if (!outf) {
    std::cerr << "Uh oh, Sample.txt could not be opened for writing!" << std::endl;
    return 1;
  }

  // We'll write two lines into this file
  outf << "This is line 1" << std::endl;
  outf << "This is line 2" << std::endl;

  return 0;
  // When outf goes out of scope, the ofstream
  // destructor will close the file
}

