// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 17/10/2021
// Archivo alphabet_class.cc: Donde se desarrollan las funciones de la clase
//         alfabeto contenida en el archivo de cabecera alphabet_class.h
//
// Referencias:
//         Enlaces de interes
//
// Historial de revisiones
// 17/10/2021 - Creacion (primera version) del codigo

#include "alphabet_class.h"

Alphabet::Alphabet(void) = default;

Alphabet::Alphabet(std::vector<Symbol>& alphabet) {
  for(auto citr = alphabet.begin(); citr != alphabet.end(); ++citr) {
    alphabet_.insert(*citr);
  }
}

Alphabet::Alphabet(Alphabet& alphabet) {
  *this = alphabet;
}

void Alphabet::SetterSymbol(const Symbol symbol) {
  alphabet_.insert(symbol);
}

void Alphabet::SetterAlphabet(std::vector<Symbol>& alphabet) {
  for(auto actual_symbol: alphabet) {
    alphabet_.insert(actual_symbol);
  }
}

void Alphabet::SetterAlphabet(Alphabet& alphabet) {
  *this = alphabet;
}

std::set<Symbol> Alphabet::GetAlphabet(void) const {
  return alphabet_;
}

size_t Alphabet::SizeAlphabet(void) {
  return alphabet_.size();
}

void Alphabet::operator=(Alphabet& alphabet) {
  alphabet.SetterAlphabet(*this);
}

std::ostream& operator<<(std::ostream& output, const Alphabet& alphabet) {
  output << "(";
  for(auto &&actual_symbol: alphabet.GetAlphabet()) {
    if(actual_symbol == *(alphabet.GetAlphabet().end())) {
      output << actual_symbol.GetSymbol() << ")";
    }else{
      output << actual_symbol.GetSymbol() << ", ";
    }
  }

  return output;
}
