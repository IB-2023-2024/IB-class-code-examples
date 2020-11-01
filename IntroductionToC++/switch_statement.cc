/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief switch statement
 *
 * Modify the code to study different versions of the switch statement
 * This switch example can easily be implemented with an if-else-if statement
 *
 * The switch statement has a somewhat peculiar syntax inherited from the early 
 * times of the first C compilers, because it uses labels instead of blocks. 
 * In the most typical use, this means that break statements are needed after 
 * each group of statements for a particular label. 
 * If break is not included, all statements following the case 
 * (including those under any other labels) are also executed, until the end 
 * of the switch block or a jump statement (such as break) is reached.
 *
 * @see http://www.cplusplus.com/doc/tutorial/control/
 */

#include <iostream>

int main () {
  const int kNumber{1};  // Play modifying this value

  switch (kNumber) {
  case 1:
    std::cout << "The number is 1" << std::endl;
    break;
  case 2:
    std::cout << "The number is 2" << std::endl;
    break;
  default:
    std::cout << "Unknown number" << std::endl;
  }

switch (kNumber) {
  case 1:
  case 2:
  case 3:
    std::cout << "The number is 1, 2 or 3" << std::endl;
    break;
  default:
    std::cout << "The number is not 1, 2 nor 3" << std::endl;
  }
}
