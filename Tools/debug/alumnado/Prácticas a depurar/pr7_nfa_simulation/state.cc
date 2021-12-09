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
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <regex>
#include "state.h"
#include <math.h>

State::State(std::string& readed_line, Alphabet& alphabet) {

  //Expresion regular para encontrar las transiciones

  //Miramos si el estado es de aceptación o no
  std::regex e ("\\b[a-zA-Z]+ \\d+|& \\d*");
  n_transitions = readed_line[4] - '0';
  if(readed_line[2] == '1') {
    acceptance = true;
  }

  for(int i{0}; i < alphabet.Size(); i++) {
    std::string symbol {alphabet.Symbol(i)};
                                                                 //std::cout << "---Símbolo -> " <<  symbol << " " << symbol.length() << " " <<  std::endl;

    std::smatch m;
    std::vector<int> v;
    std::string readed_line_cpy = readed_line;

    while (std::regex_search (readed_line_cpy,m,e)) {

      for (std::string x:m) {
                                                          // std::cout <<"---" <<x<<"---" << std::endl;
        // Cogemos el estado siguiente al revés
        std::string next_state_string_reverse;
        for ( long unsigned int i{x.length()}; i > 0; i-- ){
          next_state_string_reverse += x[i];
          if ( x[i - 1] == ' ') {break;}
        }
        //Ponemos el estado siguiente al derecho
        std::string next_state_string;
        for ( long unsigned int i{next_state_string_reverse.length()}; i > 0; i--) {
          next_state_string += next_state_string_reverse[i];
        }

        int next_state{0};
        for ( int i{1}; i < next_state_string_reverse.length(); i++ ) {
          next_state += (next_state_string_reverse[i] - '0') * (pow(10,i-1));
        }

        std::string s;
        for(int j{0}; x[j] != ' '; j++) { 
          s+= x[j];
                                                                // std::cout << "{" << x[j] << "}";
        }
                                                               //  std::cout << "s_string ->"<< s << " " << s.length()<< " siguiente " << next_state <<std::endl;
        if (s == symbol) { 
                                                               //  std::cout << "Pasooooo--------------------------------------" << std::endl;
          v.emplace_back(next_state);
        }
      }
      readed_line_cpy = m.suffix().str();
    }
    if(!v.empty()) {
      state_[symbol] = v;
    }
  }
                                                             //    std::cout << "\n-------------------------------------------------------------------------------------" << std::endl;
};

std::ostream& operator<<(std::ostream& os, const State& state) {

  for (auto it=state.state_.begin(); it!=state.state_.end(); ++it) {
    std::cout << it->first << " => ";
    //  << it->second << '\n';
    for(int i{0}; i < it->second.size(); i++) {
      std::cout << "q" << it->second[i] << " ";
    }
  }

  return (os);
}


