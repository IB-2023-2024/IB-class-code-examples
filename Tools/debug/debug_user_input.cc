/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Sample code to illustrate debugging
 *
 * @see https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
 */

#include <iostream>

int add(int x, int y) {
  return x + y;
}

void printResult(int z) {
  std::cout << "The answer is: " << z << std::endl;
}

int getUserInput() {
  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;
  return --x;
}

int main() {
  int x{ getUserInput() };
  int y{ getUserInput() };

  int z { add(x, y) };
  printResult(z);

  return 0;
}
