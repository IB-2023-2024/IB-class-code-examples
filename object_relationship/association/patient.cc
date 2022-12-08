/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Patient class definition
 * @see https://www.learncpp.com/cpp-tutorial/association/
 */

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "doctor.h"
#include "patient.h"

void Patient::AddDoctor(const Doctor& doctor) {
  doctors_.emplace_back(doctor);
}

std::ostream& operator<<(std::ostream &out, const Patient &patient) {
  if (patient.doctors_.empty()) {
    out << patient.name() << " No tiene doctores en este momento";
    return out;
  }
  out << patient.name_ << " está consultando a los doctores: ";
  for (const auto& doctor : patient.doctors_)
    out << doctor.get().name() << ", ";
  return out;
}
