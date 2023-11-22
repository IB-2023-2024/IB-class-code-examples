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
  fstream input_file{"test_cols.txt", ios_base::in};     // Create an input file stream
  int my_var1;
  double my_var2, my_var3;
  string my_string;
  // Read data, until it is there
  while (input_file >> my_var1 >> my_var2 >> my_string >> my_var3) {
    cout << my_var1 << ", " << my_var2 << ", " << my_string << ", " << my_var3 << endl;
  }

  input_file.close();
  return 0;
}


// Content of the test_cols.txt file
// 1 2.34 One 0.21
// 2 2.004 two 0.23
// 3 -2.34 string 0.22
