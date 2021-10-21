/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief const with references
 * 
 * References are fast but reduce control
 * To avoid unwanted changes use const
 *
 * In this example, number, ref and kRef all reference the same value
 * They are all 'alias'
 *
 * @see https://www.tutorialspoint.com/cplusplus/cpp_references.htm
 */

# include <iostream>

int main () {
  int number{42}; 
  int another_number{7};
  int& ref{number};
  const int& kRef{number};

  ref = 0;
  std::cout << ref << " " << number << " " << kRef << std::endl;

  number = 24;
  std::cout << ref << " " << number << " " << kRef << std::endl;

  ref = another_number;        // You can change the value of ref
  // kRef = another_number;    // But YOU CAN'T CHANGE (it's const) the value of kRef
  std::cout << ref << " " << another_number << " " << kRef << std::endl;

  return 0;
}
