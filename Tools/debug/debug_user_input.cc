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

int Add(int x, int y) {
  return x + y;
}

void PrintResult(int z) {
  std::cout << "The answer is: " << z << std::endl;
}

int GetUserInput() {
  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;
  return --x;
}

int main() {
  int x{GetUserInput()};
  int y{GetUserInput()};

  int z{Add(x, y)};
  PrintResult(z);

  return 0;
}
