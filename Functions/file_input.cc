/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @txte 23 Jun 2020
 * @brief File input. Read lines from file
 *        The extraction operator breaks on whitespace. 
 *        If you use:
 *         inf >> strInput;
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
  // We'll read from a file called Sample.txt
  std::ifstream inf{ "Sample.txt" };
 
  // If we couldn't open the input file stream for reading
  if (!inf) {
    std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    return 1;
  }
 
  // While there's still stuff left to read
  while (inf) {
    // read stuff from the file into a string and print it
    std::string strInput;
    std::getline(inf, strInput);  // Try using  inf >> strInput;
    std::cout << strInput << '\n';
  }
  
  return 0;
  // When inf goes out of scope, the ifstream
  // destructor will close the file
}
