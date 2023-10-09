#include <iostream>

using namespace std;

int main() {
  // Declarar variables para almacenar los valores de entrada y salida
  double centimetros, pulgadas;
  // Solicitar al usuario que ingrese la cantidad en centímetros
  cout << "Ingrese la longitud en centimetros: ";
  cin >> centimetros;
  // Realizar la conversión de centímetros a pulgadas
  pulgadas = centimetros / 2.54;
  // Mostrar el resultado
  cout << centimetros << " centimetros son equivalentes a " << pulgadas << " pulgadas." << endl;
  return 0;
}
