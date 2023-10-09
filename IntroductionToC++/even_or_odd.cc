#include <iostream>

int main() {
  int numero;
  // Solicitar al usuario que ingrese un número entero
  std::cout << "Ingrese un número entero: ";
  std::cin >> numero;
  // Verificar si el número es par o impar
  if (numero % 2 == 0) {
    std::cout << numero << " es un número par." << std::endl;
  } else {
    std::cout << numero << " es un número impar." << std::endl;
  }
  return 0;
}
