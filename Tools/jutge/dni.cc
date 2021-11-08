/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Oct 27 2021
 * @brief Computes the DNI letter from the number
 *        The program takes directly the input and prints the output
 * @see http://www.interior.gob.es/web/servicios-al-ciudadano/dni/calculo-del-digito-de-control-del-nif-nie
 */

#include <iostream>
#include <string>

int main() {
  int dni{0};

  std::cin >> dni;
  const std::string kLetters{"TRWAGMYFPDXBNJZSQVHLCKE"};
  std::cout << "DNI letter: " << kLetters[dni % 23] << std::endl;
  return 0;
}
