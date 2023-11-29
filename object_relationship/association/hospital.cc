/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief A simple example to illustrate association of objects
 *
 * @see https://www.learncpp.com/cpp-tutorial/association/
 */

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "doctor.h"
#include "patient.h"

int main() {
  // Create a Patient outside the scope of the Doctor
  Patient alvarez{"Alvarez"};
  Patient diaz{"Díaz"};
  Patient gonzalez{"González"};
  Doctor barrera{"Barrera"};
  Doctor simon{"Simón"};

  barrera.AddPatient(alvarez);
  simon.AddPatient(alvarez);
  simon.AddPatient(gonzalez);

  std::cout << barrera << '\n';
  std::cout << simon << '\n';
  std::cout << alvarez << '\n';
  std::cout << diaz << '\n';
  std::cout << gonzalez << '\n';

  return 0;
}
