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
#ifndef CYA_PR7_NFA_H_
#define CYA_PR7_NFA_H_
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "state.h>
#include "alphabet.h>
#include "chain.h>
#include <bits/stdc++.h>

class Nfa {
 public:
  //Constructores
  Nfa(){};
  Nfa(std::string& input_nfa, std::string& input_txt, std::string& output_txt);

  //Métodos
  //void Sintaxis();
  void Recognize();
  std::unordered_set<int> EpsilonClosure(std::unordered_set<int>& next_states);
  //Operadores
  friend std::ostream& operator<<(std::ostream& os, const Nfa& nfa);

 private:
  //Objetos para hacer uso de la librería fstream
  std::ifstream r_nfa;
  std::ifstream r_input_txt;
  std::ofstream w_output_txt;

  //Variables para el uso de lectura y escritura
  std::string input_nfa_;
  std::string input_txt_;
  std::string output_txt_;

  Alphabet alphabet_;
  Chain chain_;
  std::vector<State> matrix_transition_;
  int number_states_{0};
  int start_state_{0};
};

#endif //CYA_PR7_NFA_H_
