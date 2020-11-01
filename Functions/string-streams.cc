/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief string streams
 *
 * Combine int, double, string, etc. into a single string
 * Break up strings into int, double, string etc.
 *
 * The for loop print the names of kLimit files with .txt extension
 * and the name built from the loop index with a format
 *
 * Afterwards, the last filename is decomposed in Number + extension (rest)
 *
 * @see https://en.cppreference.com/w/cpp/io/basic_stringstream
 */

#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  stringstream s_out;
  const string kExt = ".txt";  // Filename extension
  string file_name = "";
  const int kLimit = 500;

  for (int i = 0; i < kLimit; ++i) {
  // Combine variables into a stringstream 
    s_out << setw (5) << setfill ('0') << i << kExt;
    file_name = s_out.str(); // Get a string 
    s_out.str(""); // Empty stream for next iteration 
    cerr << file_name << endl;
  }
  stringstream s_in(file_name);
  int i; 
  string rest;
  s_in >> i >> rest;
  cerr << "Number :" << i << " rest is: " << rest << endl;
  return 0;
}
