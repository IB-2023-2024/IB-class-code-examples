/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito-Izquierdo
 * @date 23 October 2023
 * @brief Programa que genera todas las potencias de 2, desde la 0-ésima hasta
 *        la ingresada por el usuario
 *
 */

#include <iostream>
#include <cmath>

int main() {
  int numberOfPowers;
  std::cout << "Ingrese el número de potencias: ";
  std::cin >> numberOfPowers;
  if (numberOfPowers < 0) {
    std::cout << "El número de potencias debe ser no negativo." << std::endl;
    return 1;
  }
  for (int i = 0; i <= numberOfPowers; i++) {
    int power = std::pow(2, i);
    std::cout << "2^" << i << " = " << power << std::endl;
  }
  return 0;
}