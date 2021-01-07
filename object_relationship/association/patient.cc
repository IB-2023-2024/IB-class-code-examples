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
#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>

#include "doctor.h"
#include "patient.h"

void Patient::addDoctor(const Doctor& doctor) {
  doctor_.push_back(doctor);
}

std::ostream& operator<<(std::ostream &out, const Patient &patient) {
	if (patient.doctor_.empty()) {
		out << patient.name() << " No tiene doctores en este momento";
		return out;
	}

	out << patient.name_ << " está viendo a los doctores: ";
	for (const auto& doctor : patient.doctor_)
		out << doctor.get().name() << ", ";

	return out;
}
