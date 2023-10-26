/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief Wrigint Text files
 *
 * With the same syntax as cerr und cout
 * streams, with ofstream we can write directly into files
 *
 * @see https://en.cppreference.com/w/cpp/io/basic_ofstream
 */

#include <iomanip>  // For setprecision 
#include <fstream>  // For the file streams

using namespace std;

int main() {
  const string kFilename{"out.txt"};
  ofstream output_file{kFilename};

  if (!output_file.is_open()) { 
    return EXIT_FAILURE; 
  }
  double my_number = 1.123123123;
  output_file << "Just string" << endl;
  output_file << setprecision (20) << my_number << endl;
  return 0;
}
