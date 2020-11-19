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
	return x;
}
 
int main() {
	int x{ getUserInput() };
std::cerr << "main::x = " << x << std::endl;
	int y{ getUserInput() };
std::cerr << "main::y = " << y << std::endl;
 
	std::cout << x << " + " << y << std::endl;
 
	int z{ add(x, 5) };
std::cerr << "main::z = " << z << std::endl;
	printResult(z);
 
	return 0;
}

