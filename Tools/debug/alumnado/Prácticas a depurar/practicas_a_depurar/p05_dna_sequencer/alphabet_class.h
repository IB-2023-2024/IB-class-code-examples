// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia (ESIT)
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Autómatas Finitos y Reconocimiento de Patrones
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 27/10/2021
// Archivo alphabet_class.h: 
// 
// Donde se aloja la declaración de la clase
// Alphabet y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes
// 

#ifndef _ALPHABET_CLASS_
#define _ALPHABET_CLASS_

#include <iostream>
#include <set>
#include <string>

class Alphabet {
 public:
  Alphabet(); // Constructor por defecto
  // Constructor para analizar cadenas de ADN
  Alphabet(const std::string& name, 
           const char& A, const char& C, const char& G, const char& T); 
  Alphabet(const Alphabet& alphabet); // Constructor de copia

  // Funciones de la clase
  // Comprueba si todos los simbolos de la cadena estan en el alfabeto
  bool IsItInAlphabet(const std::string& chain);
  void operator=(const Alphabet& alphabet);
  friend std::ostream& operator<<(std::ostream& out, Alphabet& alphabet);

  // Getter
  std::set<char> GetAlphabet();

 private:
  // Nombre del alfabeto, para aclarar en el operador<< que simbolos usamos
  std::string name_; 
  std::set<char> alphabet_;
};

#endif
