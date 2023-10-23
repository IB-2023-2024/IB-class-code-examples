/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito-Izquierdo
 * @date 23 October 2023
 * @brief Programa que imprime los N primeros términos de la Serie de Fibonacci.
 *        Los primeros términos de la serie son: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,...
 *
 */

#include <iostream>

int main() {
  int numberOfElements;

  // Solicitar al usuario la cantidad de términos que desea imprimir
  std::cout << "Ingrese la cantidad de términos de la Serie de Fibonacci que desea imprimir: ";
  std::cin >> numberOfElements;

  if (numberOfElements <= 0) {
    std::cout << "Por favor, ingrese un número positivo." << std::endl;
    return 1;
  }

  // Inicializamos los primeros dos términos de la serie
  int firstElement = 0;
  int secondElement = 1;

  std::cout << "Los primeros " << numberOfElements << " términos de la Serie de Fibonacci son:" << std::endl;

  // Imprimir los términos de la serie
  for (int i = 1; i <= numberOfElements; i++) {
    std::cout << firstElement << " ";
    int temp = firstElement;
    firstElement = secondElement;
    secondElement = temp + secondElement;
  }

  std::cout << std::endl;

  return 0;
}
