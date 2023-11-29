/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Teacher class
 *        For the sake of simplicity we implement the class in this header 
 *        file and therefore there is no teacher.cc file
 *
 * @see https://www.learncpp.com/cpp-tutorial/aggregation/
 */

#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher {
 public:
  Teacher(const std::string& name) : name_{ name } { }
  std::string name() const { return name_; }
 private:
  std::string name_{};
};
#endif
