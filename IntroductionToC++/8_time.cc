/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito-Izquierdo
 * @date 23 October 2023
 * @brief Programa que solicita al usuario la hora actual del reloj y un número entero
 *        de horas, H e indique como salida qué hora marcará el reloj dentro de H horas.
 *
 */

#include <iostream>

using namespace std;

int main() {
  int horaActual, horasPasadas, horaFutura;

  // Solicitar la hora actual al usuario
  cout << "Introduce la hora actual del reloj (en formato 24 horas): ";
  cin >> horaActual;

  // Validar que la hora introducida esté en el rango correcto (0-23)
  if (horaActual < 0 || horaActual > 23) {
    cout << "La hora introducida no es válida. Debe estar en el rango de 0 a 23." << endl;
    return 1; // Salir del programa con un código de error
  }

  // Solicitar el número de horas a avanzar
  cout << "Introduce el número de horas a avanzar: ";
  cin >> horasPasadas;

  // Calcular la hora futura
  horaFutura = (horaActual + horasPasadas) % 24;

  // Mostrar la hora futura
  cout << "La hora que marcará el reloj dentro de " << horasPasadas << " horas será: " << horaFutura << ":00" << endl;

  return 0;
}
