/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Patient class declaration
 *        In C++ you can't store references in a vector because the component type in a std::vector
 *        has to be 'assignable' and references are not assignable (you can only initialize them 
 *        once when they are declared, and you cannot make them reference something else later). 
 *        That's the reason why we use a std::reference_wrapper in this example.
 *
 * @see https://www.learncpp.com/cpp-tutorial/association/
 * @see https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper
 * @see https://www.tutorialspoint.com/reference-wrapper-in-cplusplus
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <functional> // reference_wrapper

class Patient {
public:
  Patient(const std::string& name) : name_{ name } { }
  friend std::ostream& operator<<(std::ostream &out, const Patient &patient);
  const std::string& name() const { return name_; }
  // We'll friend Doctor::AddPatient() so it can access the private function Patient::AddDoctor()
  friend void Doctor::AddPatient(Patient& patient);
private:
  std::string name_{};
  std::vector<std::reference_wrapper<const Doctor>> doctors_{}; 
  // We're going to make AddDoctor private because we don't want the public to use it.
  // They should use Doctor::AddPatient() instead, which is publicly exposed
  void AddDoctor(const Doctor& doctor);
};

#endif
