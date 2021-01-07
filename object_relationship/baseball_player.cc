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
  std::string name_{};
  int age_{};

  const std::string& name() const { return name_; }
  int age() const { return age_; }

  Person(const std::string& name = "", int age = 0) : name_{name}, age_{age} {
  }
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person {
public:
  double batting_average_{};
  int home_runs_{};

  BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0) : batting_average_{battingAverage}, home_runs_{homeRuns} {
  }
};

int main() {
  // Create a new BaseballPlayer object
  BaseballPlayer joe{};
  // Assign it a name (we can do this directly because m_name is public. It should not be!)
  joe.name_ = "Joe";
  // Print out the name
  std::cout << joe.name() << '\n'; // use the name() function we've acquired from the Person base class

  return 0;
}
