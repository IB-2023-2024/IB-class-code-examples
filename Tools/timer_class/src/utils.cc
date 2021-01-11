/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 11 Jan 2021
 * @brief Definition of different utility functions (user defined)
 *
 * @see sleep_for http://www.cplusplus.com/reference/thread/this_thread/sleep_for/
 */

#include <chrono>   // std::chrono::seconds
#include <thread>   // std::this_thread::sleep_for
#include <iostream>

#include "utils.h"


/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa un único número natural para su ejecución.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << ": Falta el número de iteraciones a usar (un número natural) como parámetro" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    const std::string kHelpText = "El programa mide el tiempo de ejecución de un bucle, cuyo número de iteraciones se requiere como parámetro";
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * Performs some time making a dummy loop
 * @param number_of_iterations to perform
 */
void WasteTime1(const int number_of_iterations) {
  int dummy_variable{0};

  for (int i = 0; i < number_of_iterations; ++i) {
    dummy_variable *= i;
  }
}

/**
 * Performs some time making a two-nested dummy loop
 * @param number_of_iterations to perform
 */
void WasteTime2(const int number_of_iterations) {
  int dummy_variable{0};

  for (int i = 0; i < number_of_iterations; ++i) {
    for (int j = 0; j < number_of_iterations; ++j) {
      dummy_variable *= j;
    }
  }
}

/**
 * Delays execution waiting for delay_seconds 
 * @param delay_seconds Time to delay
 */
void DelaySeconds(const int delay_seconds) {
  std::this_thread::sleep_for (std::chrono::seconds(delay_seconds));
}


