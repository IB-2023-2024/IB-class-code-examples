/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 11 Jan 2021
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

#include "utils.h"
#include "timer.h"

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
  WasteTime1(kIterations);
  std::cout << "Tiempo requerido: " << timer.elapsed() << " segundos\n";

  std::cout << "Realizando el bucle vacío anidado... " << std::endl; 
  timer.reset();
  WasteTime2(kIterations);
  std::cout << "Tiempo requerido: " << timer.elapsed() << " segundos\n";

  const int kFactor = 10;
  std::cout << "Número de iteraciones a realizar: " << kFactor * kIterations << std::endl;
  std::cout << "Realizando el bucle vacío... " << std::endl; 
  timer.reset();
  WasteTime1(kFactor * kIterations);
  std::cout << "Tiempo requerido: " << timer.elapsed() << " segundos\n";

  std::cout << "Función DelaySeconds (5 secs): " << std::endl; 
  timer.reset();
  DelaySeconds(5);
  std::cout << "Tiempo requerido: " << timer.elapsed() << " segundos\n";

  return 0;
}
