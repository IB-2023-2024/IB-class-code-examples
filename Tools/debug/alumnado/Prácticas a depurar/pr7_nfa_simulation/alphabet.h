/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 7: NFA simulation
* Autor: Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* Fecha de creación: 14/10/2021
* Referencias:  https://google.github.io/styleguide/cppguide.html
*/

#ifndef CYA_PR6_ALPHABET_H_
#define CYA_PR6_ALPHABET_H_
#include <set>
#include <fstream>

class Alphabet {
 public:
  //Constructor
  Alphabet(){};
  Alphabet (std::ifstream& r_dfa, std::string& input_dfa);

  //Getter
  std::string GetAlphabet() {return(alphabet_);};

  // Operadores
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);
  Alphabet& operator=(Alphabet& alph) {
    alphabet_set_ = alph.alphabet_set_;
    return *this;
  }
  int Size() {return alphabet_set_.size();};

  //Método/s
  std::string Symbol(int i);
  bool IsContained(std::string& symbol);

  std::set<std::string> alphabet_set_;
 private:
  std::string alphabet_;

};

#endif //CYA_PR6_ALPHABET_H_