#include <iostream>
#include <cmath> // Necesario para la función sqrt

using namespace std;

int main() {
  double cateto1, cateto2, hipotenusa;
  // Solicitar al usuario las longitudes de los catetos
  cout << "Ingrese la longitud del primer cateto: ";
  cin >> cateto1;
  cout << "Ingrese la longitud del segundo cateto: ";
  cin >> cateto2;
  // Calcular la hipotenusa usando el teorema de Pitágoras
  hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
  // Mostrar el resultado
  cout << "La longitud de la hipotenusa es: " << hipotenusa << endl;
  return 0;
}
