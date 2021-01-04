/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 18 Dec 2020
 * @brief Tests Unitarios con la plataforma gtest
 *        Programa principal del usuario que invoca a las diferentes funciones desarrolladas
 * @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P12-Classes-GTests-Exercism/blob/master/Classes-GTests-Exercism.md
 */

#include <iostream>

#include "factorial.h"
#include "cubic.h"
#include "formula.h"
#include "addition.h"
#include "multiply.h"
#include "square_root.h"
#include "date.h"
#include "sample2.h"

int main(int argc, char **argv) {
  const int kValue1{4};
  const int kValue2{5};

	std::cout << "Ejecutando main() que invoca varias funciones definidas por el usuario.\n";
	std::cout << "Factorial(" << kValue1 << "): " << Factorial(kValue1) << std::endl;
	std::cout << "cubic(" << kValue1 << "): " << Cubic(kValue1) << std::endl;
  std::cout << "Bla: " << Formula::Bla(kValue1) << std::endl;
  std::cout << "Addition Result: " << Addition::TwoValues(kValue1, kValue2) << std::endl;
  std::cout << "Multiply Result: " << Multiply::TwoValues(kValue1, kValue2) << std::endl;
	std::cout << "SquareRoot(" << kValue1 << "): " << SquareRoot(kValue1) << std::endl;

  Date today{2020, 12, 1};  // initialize using parameterized constructor (C++11)
  const Date date1{};               // initialize using default constructor
  const Date date2{2020, 1, 18}; 
  const Date date3{2020, 12, 18}; 
	if (date3 > date2) {
	  std::cout << date3 << " > " << date2 << std::endl;
	}
	else
	{
	  std::cout << date3 << " <= " << date2 << std::endl;
	}
	std::cout << "Date: " << date2 << std::endl;

	MyString cadena{"12"};
	std::cout << "Longitud: " << cadena.Length() << std::endl;
  
	std::cout << "ToString: " << ToString(date1) << std::endl;

  return 0;
}
