#include <iostream>
#include <vector>
#include <fstream>

int main () {
  const std::string nombre_archivo = "secuencia.txt";
  std::ifstream archivo(nombre_archivo);
  int size{0};
  archivo >> size;
  std::vector<int> vector_numeros;
  for (int i = 0; i < size; i++) {
    int numero{0};
    archivo >> numero;
    vector_numeros.push_back(numero);
  }
  archivo.close();
  for (int j = (size - 1); j >= 0; j--) {
    std::cout << vector_numeros[j] << " ";
  }
  std::cout << std::endl;
  return 0;
}
