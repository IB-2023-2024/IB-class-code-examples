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
 * SwapVal and SwapRef are intended to swap their parameters
 * SwapVal uses passing by value
 * SwapRef uses passing by reference
 * Study the effect
 */

# include <iostream>

// Pass by value
void SwapVal(int _val1, int _val2) {
  int temp;
  temp = _val1;
  _val1 = _val2;
  _val2 = temp;
}

// Pass by reference
void SwapRef(int& _val1, int& _val2) {
  int temp;
  temp = _val1;
  _val1 = _val2;
  _val2 = temp;
}


int main() {
  int val1{10};
  int val2{20};

  SwapVal(val1, val2);   // No effect
  std::cout << "val1: " << val1 << " val2: " << val2 << std::endl;

  SwapRef(val1, val2);   // No effect
  std::cout << "val1: " << val1 << " val2: " << val2 << std::endl;

  return 0;
}
