/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito-Izquierdo
 * @date 23 October 2023
 * @brief Programa que entregua como salida todos los divisores del número entero introducido.
 *
 */

#include <iostream>
#include <cmath>

int main() {
  int numero;

  // Solicitar al usuario que ingrese un número entero
  std::cout << "Ingrese un número entero: ";
  std::cin >> numero;

  // Asegurarse de que el número ingresado sea positivo
  if (numero < 0) {
    std::cout << "Por favor, ingrese un número entero positivo." << std::endl;
    return 1; // Salir del programa con un código de error
  }

  std::cout << "Divisores de " << numero << ": ";

  // Iterar a través de los números desde 1 hasta el número ingresado
  for (int i = 1; i <= numero; i++) {
    // Si i es un divisor de numero, imprímelo
    if (numero % i == 0) {
      std::cout << i << " ";
    }
  }

  std::cout << std::endl;

  return 0; // Salir del programa con un código de éxito
}
