/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Example to illustrate inheritance
 * @see https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/
 */

#include <iostream>
#include <string>

class Person {
 public:
  Person(const std::string& name = "", int age = 0) : name_{name}, age_{age} { }
  const std::string& name() const { return name_; }
  int age() const { return age_; }

  std::string name_{};
  int age_{};
};

// Employee publicly inherits from Person
class Employee: public Person {
 public:
  Employee(double hourlySalary = 0.0, long employeeID = 0) : hourly_salary_{hourlySalary}, employee_id_{employeeID} { }
  void PrintNameAndSalary() const {
    std::cout << name_ << ": " << hourly_salary_ << '\n';
  }

  double hourly_salary_{};
  long employee_id_{};
};

int main() {
  Employee frank{20.25, 12345};
  frank.name_ = "Frank"; // we can do this because name_ is public. It should not be!!
  frank.PrintNameAndSalary();
  return 0;
}
