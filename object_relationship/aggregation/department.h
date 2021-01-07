/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Department class
 *        For the sake of keeping the example concise 
 *        we implement the class in this header file and therefore
 *        there is no department.cc file
 *
 * @see https://www.learncpp.com/cpp-tutorial/aggregation/
 */

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "teacher.h"

class Department {
 public:
  Department(const Teacher& teacher) : teacher_{ teacher } {
  }
 private:
  const Teacher& teacher_; // This dept holds only one teacher for simplicity, but it could hold many teachers
};

#endif
