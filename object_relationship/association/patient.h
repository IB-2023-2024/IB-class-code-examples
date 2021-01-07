/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Patient class declaration
 *
 * @see https://www.learncpp.com/cpp-tutorial/association/
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
public:
	Patient(const std::string& name) : name_{ name } {
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Patient &patient);
	const std::string& name() const { return name_; }
 
	// We'll friend Doctor::addPatient() so it can access the private function Patient::addDoctor()
	friend void Doctor::addPatient(Patient& patient);
private:
	std::string name_{};
	std::vector<std::reference_wrapper<const Doctor>> doctor_{}; // so that we can use it here
 
	// We're going to make addDoctor private because we don't want the public to use it.
	// They should use Doctor::addPatient() instead, which is publicly exposed
	void addDoctor(const Doctor& doctor);
};

#endif
