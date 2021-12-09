// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 17/10/2021
// Archivo alphabet_class.h: Donde se aloja la declaración de la clase
//         alfabeto y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes

#ifndef _ALPHABET_CLASS_
#define _ALPHABET_CLASS_

#include <vector>
#include <set>

#include "symbol_class.h"

class Alphabet {
 public:
  //Constructores
  Alphabet(void);
  Alphabet(std::vector<Symbol>& alphabet);
  Alphabet(Alphabet& alphabet);

  //Setters y Getter
  void SetterSymbol(const Symbol symbol);
  void SetterAlphabet(std::vector<Symbol>& alphabet);
  void SetterAlphabet(Alphabet& alphabet);
  std::set<Symbol> GetAlphabet(void) const;

  //Funciones
  size_t SizeAlphabet(void);

  //Operadores
  void operator=(Alphabet& alphabet);

  //Operadores de Flujo de salida
  friend std::ostream& operator<<(std::ostream& output, Alphabet& alphabet);

 private:
  std::set<Symbol> alphabet_;
};

#endif
