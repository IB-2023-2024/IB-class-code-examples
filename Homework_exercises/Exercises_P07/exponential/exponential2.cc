/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief  Ejercicios propuestos en las prácticas de Informática Básica
 *         Ejercicio 3. Práctica 7:
 *         La función exponencial, f(x)=ex, se puede calcular mediante su desarrollo en serie de Taylor
 *         Cuantos más términos tome de la serie, mayor será la precisión de la aproximación a la función.
 *         Diseñe una función
 *           double MyExp(double exponent, unsigned num_terms);
 *         que calcule el valor de ex para un valor de x que se le pase como parámetro (exponent). 
 *         El segundo parámetro de la función indica el número de términos del desarrollo en 
 *         serie de Taylor a utilizar para el cálculo.
 *
 *         Versión 1: Función factorial
 *         Versión 2: Función MyExponential, que caldula la serie. 
 *                    Primera versión (aún incompleta)
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 * @see https://wesmckinney.com/blog/avoid-unsigned-integers/
 */

#include <iostream>
#include <cassert>   // assert
#include <cmath>   // assert

// Returns the factorial of the argument
int Factorial(int number) {
  switch (number) {
    case 0:
    case 1:
      return 1;
    default:
      int factorial = 1;
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
      }
      return factorial;
  }
}

double MyExponential(double exponent, int num_terms) {
	double sum{1.0};

  for (int i = 1; i <= (num_terms - 1); ++i) {
		std::cout << 1.0 * Factorial(i) << std::endl;
		sum += 1.0 / Factorial(i);
	}
	return sum;
}

int main () {
  std::cout << "Introduzca el número de términos: ";
  int limit;
  std::cin >> limit;
  std::cout << "Introduzca el exponente: ";
  double exponent;
  std::cin >> exponent;
  std::cout << "Resultado  : " << MyExponential(exponent, limit) << std::endl;
  std::cout << "Result math: " << exp(exponent) << std::endl;
  return 0;
}
