/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief A simple example to illustrate aggregation of objects
 *        The example uses classes Teacher and Department.
 *        Here we’re going to make a couple of simplifications: 
 *        First, the department will only hold one teacher. 
 *        Second, the teacher will be unaware of what department they’re part of.
 *
 * @see https://www.learncpp.com/cpp-tutorial/aggregation/
 */

#include <iostream>
#include <string>

#include "teacher.h"
#include "department.h"
 
int main() {
	// Create a teacher outside the scope of the Department
  Teacher einstein{"Albert Einstein"}; // create a teacher

  {
    // Create a department and use the constructor parameter to pass the teacher to it.
    Department department{einstein};
  } // department goes out of scope here and is destroyed

  // sande still exists here, but the department doesn't

  std::cout << einstein.name() << " still exists!\n";

  return 0;
}
