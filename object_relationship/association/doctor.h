/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Doctor class declaration
 *        A doctor holds a vector of patients
 *
 * @see https://www.learncpp.com/cpp-tutorial/association/
 * @see https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper
 * @see https://www.tutorialspoint.com/reference-wrapper-in-cplusplus
 */

#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <functional> // reference_wrapper

// Since Doctor and Patient have a circular dependency, we're going to forward declare Patient
class Patient;

class Doctor {
 public:
  Doctor(const std::string& name) : name_{ name } { } 
  void AddPatient(Patient& patient);
  friend std::ostream& operator<<(std::ostream &out, const Doctor &doctor);
  const std::string& name() const { return name_; }
 private:
  std::string name_{};
  std::vector<std::reference_wrapper<const Patient>> patients_{};
};

#endif
