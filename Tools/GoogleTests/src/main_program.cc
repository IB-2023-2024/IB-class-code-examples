#include <iostream>

#include "factorial.h"
#include "cubic.h"
#include "formula.h"
#include "addition.h"
#include "multiply.h"
#include "square_root.h"

int main(int argc, char **argv) {
  const int kValue1{4};
  const int kValue2{5};

	std::cout << "Ejecutando main() que invoca varias funciones definidas por el usuario.\n";
	std::cout << "Factorial(" << kValue1 << "): " << factorial(kValue1) << std::endl;
	std::cout << "cubic(" << kValue1 << "): " << cubic(kValue1) << std::endl;
  std::cout << "Bla: " << Formula::bla(kValue1) << std::endl;
  std::cout << "Addition Result: " << Addition::twoValues(kValue1, kValue2) << std::endl;
  std::cout << "Multiply Result: " << Multiply::twoValues(kValue1, kValue2) << std::endl;
	std::cout << "SquareRoot(" << kValue1 << "): " << SquareRoot(kValue1) << std::endl;
  return 0;
}
