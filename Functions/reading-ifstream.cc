/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief I/O Reading from ifstream
 *
 * @see https://en.cppreference.com/w/cpp/io/manip
 */

#include <fstream> // For the file streams
#include <iostream>
#include <string>

using namespace std;    // Saving space

int main() {
  int my_int;
  double my_doub1, my_doub2;
  string my_string;

  // Create an input file stream
  ifstream in("test_cols.txt", ios_base::in);
  // Read data, until it is there
  while (in >> my_int >> my_doub1 >> my_string >> my_doub2) {
    cerr << my_int << ", " << my_doub1 << ", " << my_string << ", " << my_doub2 << endl;
  }
  return (0);
}


// Content of the test_cols.txt file
// 1 2.34 One 0.21
// 2 2.004 two 0.23
// 3 -2.34 string 0.22
