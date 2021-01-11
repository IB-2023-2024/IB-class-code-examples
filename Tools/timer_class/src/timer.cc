/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 11 Jan 2021
 * @brief A Timer class definition
 *        A class designed to measure execution time for programs
 *
 * @see https://www.learncpp.com/cpp-tutorial/timing-your-code/
 */

#include "timer.h"

void Timer::reset() {
  start_ = clock_t::now();
}
 
double Timer::elapsed() const {
  return std::chrono::duration_cast<second_t>(clock_t::now() - start_).count();
}
