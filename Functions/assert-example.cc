/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief assert macro example
 * assert macro allows testing of boolean condition at run time
 * Typically used to test sanity of code (e.g., test preconditions, postconditions, or other invariants) or test validity of assumptions made by code
 * Defined in header file cassert
 * Macro takes single argument: boolean expression
 * If assertion fails, program is terminated by calling std::abort
 * If NDEBUG preprocessor symbol is defined at time cassert header file included, all assertions are disabled (i.e., not checked)
 *
 * The assert macro checks for the validity of the assertions or assumptions. 
 * If the assertion results to be FALSE then the macro writes information about the call that 
 * failed on stderr and then calls abort(). 
 * abort() raises the SIGABRT signal and this results in an abnormal termination of the process.
 *
 * @see https://en.cppreference.com/w/cpp/error/assert
 */

#include <iostream> // std::cout, std::endl

// uncomment next line to disable assert()
// #define NDEBUG 
//
#include <cassert>

double Mysqrt(const double number) {
  assert(number >= 0);
  std::cout << "Execution in Mysqrt function" << std::endl;
  return number;
}

int main() {
  double param = -9.0;
  const double result{Mysqrt(param)};

  std::cout << "param: " << param << " result: " << result << std::endl;
}
