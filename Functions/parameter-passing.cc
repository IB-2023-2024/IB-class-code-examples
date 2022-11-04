/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Example to illustrate parameter passing in C++
 * 
 * See the comments and study the effect
 * 
 * Visualize the execution at:
 * @see http://pythontutor.com/cpp.html#code=%23%20include%20%3Ciostream%3E%0A%0Avoid%20Increment0%28int%20x%29%20%7B%0A%20%20%2B%2Bx%3B%20%20%20%20%0A%7D%0Avoid%20Increment%28int%26%20x%29%20%7B%0A%20%20%2B%2Bx%3B%20%20%20%20%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20local_var%3D%200%3B%0A%20%20Increment0%28local_var%29%3B%20%20%20%20//%20local_var%20is%20passed%20by%20value%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//%20local_var%20still%20equals%200%20%28local_var%20was%20not%20incremented%29%0A%20%20std%3A%3Acout%20%3C%3C%20%22local_var%3A%20%22%20%3C%3C%20local_var%20%3C%3C%20std%3A%3Aendl%3B%0A%20%20Increment%28local_var%29%3B%20%20%20%20%20//%20local_var%20is%20passed%20by%20reference%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//%20local_var%20equals%201%20%28local_var%20was%20incremented%29%0A%20%20std%3A%3Acout%20%3C%3C%20%22local_var%3A%20%22%20%3C%3C%20local_var%20%3C%3C%20std%3A%3Aendl%3B%0A%7D%0A&mode=edit&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D
 *
 */

#include <iostream>

void Increment0(int x) {
  ++x;        
}

void Increment1(int& x) {
  int local_to_increment{99};  // Lifetime of this var finishes with Increment1()
  ++x;
  --local_to_increment;
}

int main() {
  int local_var{0};

  Increment0(local_var);    // local_var is passed by value
                            // local_var still equals 0 (local_var was not incremented)
  std::cout << "local_var: " << local_var << std::endl;

  Increment1(local_var);     // local_var is passed by reference
                            // local_var equals 1 (local_var was incremented)
  std::cout << "local_var: " << local_var << std::endl;
}
