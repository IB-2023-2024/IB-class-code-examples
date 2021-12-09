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

#include <iostream>
#include "nfa.h"
#include <fstream>
#include <string>
#include "state.h"
#include <vector>
#include <regex>
#include <set>
#include <bits/stdc++.h>

Nfa::Nfa(std::string& input_nfa, std::string& input_txt, std::string& output_txt) {

  // Inicializamos los atributos privados
  input_nfa_ = input_nfa;
  input_txt_ = input_txt;
  output_txt_ = output_txt;
  // Miramos que la sintaxis del archivo de entrada esté bien
  //Sintaxis();

  // Creamos los objetos necesarios
  Alphabet alphabet {r_nfa, input_nfa_};
  alphabet_ = alphabet;

  //Abrimos el archivo de lectura
  r_nfa.open(input_nfa_, std::ios::in);
  //r_nfa.open(input_nfa_, std::ios::out) si es de escritura

  if (r_input_txt.fail()) {
    std::cout << "El archivo del NFA no se pudo abrir o no se ha creado" << std::endl;
    exit(EXIT_SUCCESS);
  }
  
  int line{0};
  while (!r_nfa.eof()) {

    std::string readed_line;
    getline(r_nfa, readed_line);
    if (line == 0) {
      number_states_ = std::stoi(readed_line);
    }
    if (line == 1) {
      start_state_ =  std::stoi(readed_line);
    }
    if (line >= 2) {
      State state{readed_line, alphabet};

      matrix_transition_.emplace_back(state);
    }
    line++;
  }

  
  r_nfa.close();
}

std::unordered_set<int> Nfa::EpsilonClosure(std::unordered_set<int>& next_states) {
  // std::unordered_set<int> next_states_closured = next_states;
  State state;
  std::unordered_set<int> next_states_closured;
  //Hacemos que next_states_closure sea igual a las & transiciones de next_states
  for (std::unordered_set<int>::iterator it = next_states.begin();it != next_states.end(); ++it) {
    if (! (matrix_transition_[*it].state_["&"].empty()) ) {
      int size_epsilon = matrix_transition_[*it].state_["&"].size();
      for ( int j{0}; j < size_epsilon; j++ ) {
        State state;
        state = matrix_transition_[*it];
        int q = state.state_["&"][j];
        next_states_closured.insert(q);
      }
    }
  }
  //Ya tenemos un set en el cual hay estados que se acceden con & transiciones
  //Ahora miramos cada una de esas & transiciones

  int counter{0};
  std::pair<std::unordered_set<int>::iterator, bool> is_inside;
  bool all_clausured_elements = false;
  while ( all_clausured_elements != true ) {
      // Recorro el set de next_states_closured
    for (std::unordered_set<int>::iterator it = next_states_closured.begin();
                                      it != next_states_closured.end(); ++it) {
      state = matrix_transition_[*it];

      //ahora tengo que hacer un for con el número de transiciones de state
      for (int i{0}; i < state.state_.size(); i++ ) {
          for ( int j{0}; j < state.state_["&"].size(); j++) {
            is_inside = next_states_closured.insert(state.state_["&"][j]);
            next_states_closured.insert(state.state_["&"][j]);
            if (is_inside.second == true) {
              counter++;
            }
        }
        // si encontramos & transiciones las metemos en next_states_clausure
        // si meto state_[&] me devuelve un vector, así que inserto con un bucle
        // is_inside = next_states_clausure.insert()
      }
    }
    if (counter != 0) {
      counter = 0;
    }
    else if (counter == 0) {
      //all_clausured_elements == true;
      break;
    }
  }
  return (next_states_closured);

}

void Nfa::Recognize() {

  std::string readed_line;

    w_output_txt.open(output_txt_, std::ios::out);
  r_input_txt.open(input_txt_,  std::ios::in);
  if ( r_input_txt.fail() ) {
    std::cout << "El archivo de CADENAS no se pudo abrir o no se ha creado";
    exit(EXIT_SUCCESS);
  }

  while ( !r_input_txt.eof() ) {
    getline(r_input_txt, readed_line);
    Chain chain {readed_line, alphabet_};
    bool acceptance = false;
    std::unordered_set<int> actual_states;
    actual_states.insert(start_state_);
    std::unordered_set<int> next_states = EpsilonClosure(actual_states);
    std::unordered_set<int> helper;


    for (int i{0}; i < chain.Length(); i++ ) {
      actual_states = next_states;
      next_states.clear();
      next_states = EpsilonClosure(actual_states);
      //Estados siguientes = estados siguientes consumiendo un símbolo
      for (std::unordered_set<int>::iterator it = actual_states.begin();
                                    it != actual_states.end(); ++it) {

        int size = matrix_transition_[*it].state_[chain[i]].size();
        for ( int j{0}; j < size; j++ ) {
          State state;
          state = matrix_transition_[*it];
          int q = state.state_[chain[i]][j];
          next_states.insert(q);
        }
        //Introducimos también epsilon transiciones en cada estado siguiente
        if (! (matrix_transition_[*it].state_["&"].empty()) ) {
          int size_epsilon = matrix_transition_[*it].state_["&"].size();
          for ( int j{0}; j < size_epsilon; j++ ) {
            State state;
            state = matrix_transition_[*it];
            int q = state.state_["&"][j];
            next_states.insert(q);
          }
        }

      }
      actual_states.clear();
      helper.clear();
    }
    
    for (std::unordered_set<int>::iterator it = next_states.begin();
            it != next_states.end(); ++it) {
      State state;
      state = matrix_transition_[*it];
      if(state.acceptance == true) {
        acceptance = true;
      }
    }
    if ( acceptance == true ) {
      w_output_txt << chain << " --- aceptada\n";
    }else{
      w_output_txt << chain << " --- rechazada\n";
    }
  }
    w_output_txt.close();
  
  r_input_txt.close();
}



std::ostream& operator<<(std::ostream& os, const Nfa& nfa) {
  //El dfa está formado por: M ≡ (Σ,Q,q0,F,δ)
  os << "M ≡ (Σ,Q,q0,F,δ)" << std::endl;
  os << "Alfabeto(Σ):" << nfa.alphabet_ << std::endl;
  os << "Conjunto de estados(Q): ";
  for (int i = 0; i < nfa.matrix_transition_.size(); i++) { 
    os << "q" << i << " ";
  }
  os << std::endl;
  os << "Estado de arranque(q0): q" << nfa.start_state_ << std::endl; 
  os << "Estado/s de aceptación(F): ";
  for (int i = 0; i < nfa.matrix_transition_.size(); i++) {
    State state;
    state = nfa.matrix_transition_[i];
    if(state.acceptance == true) {
      os << "q" << i << " ";
    }
  }
  os << std::endl;
  os << "Función de transición(δ): " << std::endl;
  os << "Estados | símbolos -> estado/s siguiente/s" << std::endl;
  for (int i = 0; i < nfa.matrix_transition_.size(); i++) {
    State state;
    state = nfa.matrix_transition_[i];
    os << "   " << i;

    for (auto it=state.state_.begin(); it!=state.state_.end(); ++it) {
      os << "      " << (*it).first << "-> ";
      for(int i{0}; i < it->second.size(); i++) {
        os << it->second[i] << "/";
      }
      os << '\b';
      os << " ";
    }
  os << std::endl;
  }
  return (os);
}
