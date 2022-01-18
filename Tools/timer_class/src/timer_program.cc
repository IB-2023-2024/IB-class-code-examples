/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 11 2021
 *       Jan 27 2022
 * @brief Example to illustrate the use of the Timer class to measure execution time
 *        The code uses different time-consuming functions and uses the Timer (user defined) class
 *        to measure the execution time for these functions.
 *
 * @see https://www.learncpp.com/cpp-tutorial/timing-your-code/
 */

#include <chrono>   // std::chrono::seconds
#include <cstddef>  // for std::size_t
#include <thread>   // std::this_thread::sleep_for
#include <iostream>
#include <cmath>   // sqrt()

#include "utils.h"
#include "timer.h"

/**
 * @brief Determines if a number is prime or not
 *        Using a brute force (naive) algorithm
 * @param[in] candidate_number Number to check
 * @return true if the candidate number is prie
 */
bool IsPrimeBruteForce(const long candidate_number) {
  for(long divisor{2}; divisor < candidate_number; ++divisor) {
    if (candidate_number % divisor == 0) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Determines if a number is prime or not
 *        exploring divisors up to sqrt(candidate_number)
 * @param[in] candidate_number Number to check
 * @return true if the candidate number is prie
 */
bool IsPrime(const long candidate_number) {
  const long kLimit = sqrt(candidate_number);
  for(long divisor{2}; divisor <= kLimit; ++divisor) {
    if (candidate_number % divisor == 0) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Prints the number of prime numbers in the range [2, limit]
 *        It makes calls to two different prime number evaluation functions
 * @param[in] limit: limit to explore
 */
void NumberOfPrimes(const int limit) {
  Timer timer;
  long prime_counter{0};

  std::cout << "Exploring prime numbers up to " << limit << std::endl;

  timer.Reset();
  for(int number{2}; number <= limit; ++number) {
    if (IsPrime(number)) {
      ++prime_counter;
    }
  }
  std::cout << "Elapsed time: " << timer.Elapsed() << "ms" << std::endl;
  std::cout << "Number of primes: " << prime_counter << std::endl;

  prime_counter = 0;
  timer.Reset();
  for(int number{2}; number <= limit; ++number) {
    if (IsPrimeBruteForce(number)) {
      ++prime_counter;
    }
  }
  std::cout << "Elapsed time: " << timer.Elapsed() << "ms" << std::endl;
  std::cout << "Number of primes: " << prime_counter << std::endl;
}

/** Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::string iterations = argv[1];
  const int kIterations = stoi(iterations);

  std::cout << "Número de iteraciones a realizar: " << kIterations << std::endl;
  std::cout << "Realizando el bucle vacío... " << std::endl; 
  Timer timer;
  timer.Reset();
  WasteTime1(kIterations);
  std::cout << "Tiempo requerido: " << timer.Elapsed() << " segundos\n";

  std::cout << "Realizando el bucle vacío anidado... " << std::endl; 
  timer.Reset();
  WasteTime2(kIterations);
  std::cout << "Tiempo requerido: " << timer.Elapsed() << " segundos\n";

  const int kFactor = 10;
  std::cout << "Número de iteraciones a realizar: " << kFactor * kIterations << std::endl;
  std::cout << "Realizando el bucle vacío... " << std::endl; 
  timer.Reset();
  WasteTime1(kFactor * kIterations);
  std::cout << "Tiempo requerido: " << timer.Elapsed() << " segundos\n";

  std::cout << "Función DelaySeconds (5 secs): " << std::endl; 
  timer.Reset();
  DelaySeconds(5);
  std::cout << "Tiempo requerido: " << timer.Elapsed() << " segundos\n";

  NumberOfPrimes(100000);

  std::cout << "Función WaitMilliSeconds (1 sec): " << std::endl; 
  timer.Reset();
  WaitMilliSeconds(1000); // Waits 1 second
  std::cout << "Elapsed time: " << timer.Elapsed() << "ms" << std::endl;

  return 0;
}
