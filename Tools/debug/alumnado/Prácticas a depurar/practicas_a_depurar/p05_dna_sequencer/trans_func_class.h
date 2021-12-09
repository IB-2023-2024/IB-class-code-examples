// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia (ESIT)
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Autómatas Finitos y Reconocimiento de Patrones
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 27/10/2021
// Archivo trans_func_class.h: 
// 
// Donde se aloja la declaración de la clase
// TransFunc y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes
// 

#ifndef _TRANS_FUNC_CLASS_
#define _TRANS_FUNC_CLASS_

#include <iostream>
#include <vector>

#include "alphabet_class.h"

class TransFunc {
 public:
  TransFunc(); // Constructor por defecto
  // Constructor para el DFA
  TransFunc(const std::vector<std::vector<size_t>>& trans_func, 
            Alphabet& alphabet);
  TransFunc(const TransFunc& trans_func); // Constructor de copia

  // Funciones de la clase
  size_t NextState(const size_t& actual_state, const char& actual_symbol);
  void operator=(const TransFunc& trans_func);
  friend std::ostream& operator<<(std::ostream& out, TransFunc& trans_func);

 private:
  std::vector<std::vector<size_t>> trans_func_;
  std::vector<std::vector<std::string>> conversion_table_;
};

#endif
