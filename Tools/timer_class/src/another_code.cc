/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 21 2021
 * @brief Time measurement using directly the C++ time functions
 * @See https://en.cppreference.com/w/cpp/thread/sleep_for
 */

#include <iostream>
#include <chrono>
#include <thread>

int main() {
  std::cout << "Hello waiter\n" << std::flush;
  auto start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end - start;
  std::cout << "Waited " << elapsed.count() << " ms\n";
}
