/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 11 2021
 *       Dec 21 2021
 * @brief A Timer class declaration
 *        A class designed to measure execution time for programs
 *
 * @see https://www.learncpp.com/cpp-tutorial/timing-your-code/
 * @See ExecutionTimer class https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
 */

#ifndef TIMER_H
#define TIMER_H

#include <chrono> // for std::chrono functions

class Timer {
 public:
  // Type aliases to make accessing nested type easier
  using Clock = std::chrono::high_resolution_clock;
  // Timer() = default;
  Timer() : start_{Clock::now()} { }

  inline int Elapsed() {
    const std::chrono::time_point<Clock> end = Clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start_).count();
  }

  inline void Reset() {
    start_ = Clock::now();
  }

 private:
  std::chrono::time_point<Clock> start_ = Clock::now();  // Holds the starting instant for timing
}; 

#endif
