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

#ifndef CYA_PR7_CHAIN_H_
#define CYA_PR7_CHAIN_H_
#include <iostream>
#include <string>
#include <vector>
#include "alphabet.h"

class Chain {
 public:
  //Constructores
  Chain() {chain_.emplace_back("&");};
  Chain(std::string& chain, Alphabet& alphabet);

  //Getter
  std::vector<std::string> GetChain(){return(chain_);};

  //Método/s
  int Length(){return(chain_.size());};

  //Operadores
  friend std::ostream& operator<<(std::ostream& os, Chain& chain);
  std::string &operator[](int i){return(str = chain_[i]);};

 private:
  std::vector<std::string> chain_;
  std::string str;
};

#endif //CYA_PR7_CHAIN_H_