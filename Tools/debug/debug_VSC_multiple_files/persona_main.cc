/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 13 2021
 * @brief clase Persona
 *        este es un programa cliente que usa la clase Persona
 *
 * @see https://github.com/ULL-ESIT-IB-2021-2022/P11-Classes-CMake/blob/main/Classes-CMake.md
 */

#include <iostream>

#include "persona.h"
 
int main() {
  Persona otra;
  Persona albert{"Albert", "Einstein", 18}; 
  otra.Print();
  albert.Print();
  return 0;
}
