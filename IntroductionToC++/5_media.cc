#include <iostream>

double Media (double number1, double number2, double number3, double number4) {
  double suma = number1 + number2 + number3 + number4;
  double media = suma / 4.0;
  std::cout << "Media: " << media << std::endl;
  return media;
}

int main() {
  double number_one{0};
  double number_two{0};
  double number_three{0};
  double number_four{0};
  std::cout << "Primer valor: ";
  std::cin >> number_one;
  std::cout << "Segundo valor: ";
  std::cin >> number_two;
  std::cout << "Tercer valor: ";
  std::cin >> number_three;
  std::cout << "Cuarto valor: ";
  std::cin >> number_four;
  Media(1.1, 2.4, 3.6, 4.7);
  std::cout << "El promedio es: " << Media(number_one, number_two, number_three,
  number_four) << std::endl;
  return 0;
}
