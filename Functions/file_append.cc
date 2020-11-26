/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief Append text to a text file
 *
 * @see https://www.learncpp.com/cpp-tutorial/186-basic-file-io/
 */

#include <iostream>
#include <fstream>

int main() {
  // We'll pass the ios:app flag to tell the ofstream to append
  // rather than rewrite the file.  We do not need to pass in std::ios::out
  // because ofstream defaults to std::ios::out
  std::ofstream outf{ "Sample.txt", std::ios::app };
  if (!outf) { // If we couldn't open the output file stream for writing
    std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
    return 1;
  }

  outf << "This is line 3" << '\n';
  outf << "This is line 4" << '\n';

  return 0;
  // When outf goes out of scope, the ofstream
  // destructor will close the file
}
