/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief I/O Manipulators
 *
 * Manipulators provide way to control formatting of data values written 
 * to streams as well as parsing of data values read from streams.
 * Declarations related information for manipulators can be found 
 * in header files: ios, iomanip, istream, and ostream.
 * Most manipulators used to control output formatting
 * Focus here on manipulators as they pertain to output
 * Manipulator may have 
 *   immediate effect (e.g., endl), 
 *   only affect next data value output (e.g., setw), 
 *   or affect all subsequent data values output (e.g., setprecision)
 *
 * @see https://en.cppreference.com/w/cpp/io/manip
 * @see http://www.cplusplus.com/reference/library/manipulators/
 */

#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
  const double kPi{3.1415926535};
  const double kBig{123456789.0};
  const char kRet{'\n'};
  const char kSpace{' '};

  // default notation
  std::cout << kPi << kSpace << kBig << kRet;
  // fixed-point notation
  std::cout << std::fixed << kPi << kSpace << kBig << kRet;
  // scientific notation
  std::cout << std::scientific << kPi << kSpace << kBig << kRet;
  // fixed-point notation with 7 digits after decimal point
  std::cout << std::fixed << std::setprecision (7) << kPi << kSpace << kBig << kRet;
  // fixed-point notation with precision and width specified
  std::cout << std::setw(8) << std::fixed << std::setprecision(2) << kPi << kSpace << std::setw(20) << kBig << kRet;
  // fixed-point notation with precision, width, and fill specified
  std::cout << std::setw(8) << std::setfill('x') << std::fixed << std::setprecision(2) << kPi << kSpace << std::setw(20) << kBig << kRet;
  return 0;
}
