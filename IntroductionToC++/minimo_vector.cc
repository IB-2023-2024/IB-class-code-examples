/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Nov 8 2023
 * @brief Computing the minimum of data in a vector
 */

#include <iostream>
#include <vector>

void MinimoVector(const std::vector<int>& vector) {
  int minimo{99999999};
  for (int i{0}; i < vector.size(); ++i) { 
    if (vector[i] < minimo) {
      minimo = vector[i];
    }
  }
  // return minimo;
}

int main() {
  std::vector<int> vector;

  while (true) {
    std::cout << "Introduzca un valor entero (99 para terminar): ";
    int dato{0};
    std::cin >> dato;
    if (dato == 99) {
      break;
    }
    vector.emplace_back(dato);
  }
  std::cout << "Valor mínimo: " << MinimoVector(vector) << std::endl;
  MinimoVector(vector);
  return 0;
}
