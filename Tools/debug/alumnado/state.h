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
#ifndef CYA_PR7_STATE_H_
#define CYA_PR7_STATE_H_
#include <vector>
#include "alphabet.h"
#include <map>

class State {
 public:
 //Constructor
  State(){};
  State (std::string& readed_line, Alphabet& alphabet);

  //Operadores
  friend std::ostream& operator<<(std::ostream& os, const State& state);

  State& operator=(State state) {
    for (auto it=state.state_.begin(); it!=state.state_.end(); ++it) {
      std::string first {it->first};
      state_[first] = it->second;
    }
    acceptance = state.acceptance;
    n_transitions = state.n_transitions;
    return *this;
  }

  bool acceptance = false;
  std::map<std::string, std::vector<int>> state_;
  int n_transitions{0};
};

#endif //CYA_PR7_STATE_H_