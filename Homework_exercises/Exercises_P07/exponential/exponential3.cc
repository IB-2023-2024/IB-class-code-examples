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
 *         Versión 2: Función MyExponential, que caldula la serie
 *         Versión 3: Se introduce la funcion Power
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 * @see https://wesmckinney.com/blog/avoid-unsigned-integers/
 * @see https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
 */

#include <iostream>
#include <cassert> // assert
#include <cmath>   // assert
#include <iomanip> // std::setprecision, std::setw

// Returns the factorial of the argument
double Factorial(int number) {
  switch (number) {
    case 0:
    case 1:
      return 1;
    default:
      double factorial = 1.0;
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
      }
      // std::cout << "Factorial: " << factorial << std::endl;
      return factorial;
  }
}

// To check if a floating point number equals zero
inline bool IsNearlyEqual(double oper1, double oper2) {
  const double kEpsilon = 1e-7; 
  return std::abs(oper1 - oper2) <= kEpsilon * std::abs(oper1);
}

// Computes base^exponent
double Power(const double base, const int exponent) {
	double result = 1.0;

	assert(exponent >= 0);
	if (exponent == 0) {
		return 1.0;
	}
	for (int i = 0; i < exponent; ++i) {
		result *= base;
	}
	return result;
}

// Computes the Taylor serie for e^exponent for num_terms terms
double MyExponential(const double exponent, const int num_terms) {
	double sum{1.0};  // The value of the first term

  for (int i = 1; i < num_terms; ++i) {  // The loop omits the first term
		sum += Power(exponent, i) / Factorial(i);
    // std::cout << "i: " << i << std::endl;
	}
	return sum;
}

int main () {
	// Uncomment to test the Power function
  // std::cout << "Power : " << Power(2.0, 3) << std::endl;
  // std::cout << "Power : " << Power(2.0, 1) << std::endl;

  std::cout << "Introduzca el número de términos: ";
  int limit;
  std::cin >> limit;
  std::cout << "Introduzca el exponente: ";
  double exponent;
  std::cin >> exponent;

	std::cout << std::fixed << std::setprecision(16);  // fix the number of decimal digits
  std::cout << "Resultado  : " << std::setw(32) << MyExponential(exponent, limit) << std::endl;
  std::cout << "Result math: " << std::setw(32) << exp(exponent) << std::endl;
  return 0;
}
