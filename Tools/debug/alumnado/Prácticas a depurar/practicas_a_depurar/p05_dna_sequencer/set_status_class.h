// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia (ESIT)
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Autómatas Finitos y Reconocimiento de Patrones
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 27/10/2021
// Archivo set_status_class.h: 
// 
// Donde se aloja la declaración de la clase
// SetStatus y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes
// 

#ifndef _SET_STATUS_CLASS_
#define _SET_STATUS_CLASS_

#include <iostream>
#include <string>
#include <vector>

class SetStatus {
 public:
  SetStatus(); // Constructor por defecto
  // Constructor usado para llenar cada posición con su posion relativa en el
  SetStatus(const std::string& name, const size_t& num_status);
  // Constructor usado para asignarle valores exactos en cada posicion 
  SetStatus(const std::string& name, const std::vector<size_t>& end_status);
  SetStatus(const SetStatus& set_status); // Constructor de copia

  // Funciones de la clase
  // Devuelve si el número es parte del conjunto
  bool IsItAState(const size_t num);
  void operator=(const SetStatus& set_status);
  friend std::ostream& operator<<(std::ostream& out, SetStatus& set_status);

 private:
  std::string name_;
  std::vector<size_t> set_status_;
};

#endif
