/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Debugging tactic #3: Printing values
 *
 * We can also output the value of variables (including parameters) or expressions to ensure that they are correct.
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
  return x;
}
 
int main() {
  int x{ GetUserInput() };
std::cerr << "main::x = " << x << std::endl;
  int y{ GetUserInput() };
std::cerr << "main::y = " << y << std::endl;
 
  std::cout << x << " + " << y << std::endl;
 
  int z{ Add(x, 5) };
std::cerr << "main::z = " << z << std::endl;
  PrintResult(z);
 
  return 0;
}
