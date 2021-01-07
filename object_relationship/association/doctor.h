/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Doctor class declaration
 * @see https://www.learncpp.com/cpp-tutorial/association/
 */

#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

// Since Doctor and Patient have a circular dependency, we're going to forward declare Patient
class Patient;

class Doctor {
 public:
	Doctor(const std::string& name) : name_{ name } {
	}

	void addPatient(Patient& patient);
	friend std::ostream& operator<<(std::ostream &out, const Doctor &doctor);
	const std::string& name() const { return name_; }
 private:
	std::string name_{};
	std::vector<std::reference_wrapper<const Patient>> patient_{};
};

#endif
