/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Doctor class definition
 * @see https://www.learncpp.com/cpp-tutorial/association/
 */

#include <cstdint>
#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>

#include "doctor.h"
#include "patient.h"

void Doctor::addPatient(Patient& patient) {
	// Our doctor will add this patient
	patient_.push_back(patient);
 
	// and the patient will also add this doctor
	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream &out, const Doctor &doctor) {
	if (doctor.patient_.empty()) {
		out << doctor.name_ << " no tiene pacientes en este momento";
		return out;
	}

	out << doctor.name_ << " está llevando a los pacientes: ";
	for (const auto& patient : doctor.patient_)
		out << patient.get().name() << ", ";

	return out;
}
