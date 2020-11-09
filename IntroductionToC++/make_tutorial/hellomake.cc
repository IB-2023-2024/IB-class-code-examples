/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief hellomake.c Source code for make tutorial
 *        Usually a simple C++ project is organized around (at least) 3 files:
 *        * One file (this) containing the main function and perhaps some other functions
 *        * A header file (hellofunc.h in this example) containing function declarations
 *        * A .cc file (hellofunc.cc in this example) containing the code (definition) of the functions
 * 
 * @see http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
 */

#include "hellomake.h"  // Contains the MyPrintHelloMake Declaration

int main() {
  // call a function in another file
  MyPrintHelloMake();
  return(0);
}
