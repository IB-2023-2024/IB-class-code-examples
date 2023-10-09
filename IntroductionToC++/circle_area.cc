#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double radio;
  const double PI = 3.14159265359;  // Valor constante de pi
  // Solicitar al usuario que ingrese el radio del círculo
  cout << "Ingrese el radio del circulo: ";
  cin >> radio;
  // Calcular el perímetro y el área del círculo
  double perimetro = 2 * PI * radio;
  double area = PI * pow(radio, 2);
  // Mostrar el resultado en la pantalla
  cout << "Perimetro del circulo: " << perimetro << endl;
  cout << "Area del circulo: " << area << endl;
  return 0;
}
