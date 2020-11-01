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
 * In this example, num, ref and kRef all reference the same value
 * They are all 'alias'
 *
 * @see https://www.tutorialspoint.com/cplusplus/cpp_references.htm
 */

# include <iostream>
using namespace std;

int main () {
  int num{42}; 
  int another_num{7};
  int& ref = num;
  const int& kRef = num;
  ref = 0;
  cout << ref << " " << num << " " << kRef << endl;
  num = 24;
  cout << ref << " " << num << " " << kRef << endl;

  ref = another_num;     // You can change the value of ref
  // kRef = another_num;    // But you can't change (it's const) the value of kRef
  cout << ref << " " << another_num << " " << kRef << endl;

  return 0;
}
