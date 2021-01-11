/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 11 Jan 2021
 * @brief A Timer class declaration
 *        A class designed to measure execution time for programs
 *
 * @see https://www.learncpp.com/cpp-tutorial/timing-your-code/
 */

#ifndef TIMER_H
#define TIMER_H

#include <chrono> // for std::chrono functions

class Timer {
 public:
  Timer() : start_(clock_t::now()) {
  }
 
  void reset();
  double elapsed() const;
 private:
  // Type aliases to make accessing nested type easier
  using clock_t = std::chrono::high_resolution_clock;
  using second_t = std::chrono::duration<double, std::ratio<1>>;
 
  std::chrono::time_point<clock_t> start_;  // Holds the starting instant for timing
};

#endif
