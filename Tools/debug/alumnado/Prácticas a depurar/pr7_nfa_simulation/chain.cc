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

#include "chain.h"
#include <vector>
#include <algorithm>
bool compare(std::string a, std::string b) {
  bool greater = false;
  if(a.length() >= b.length()) { greater = true;}
  return(greater);
}

Chain::Chain(std::string& chain, Alphabet& alphabet_) {
  chain_.clear();
  std::vector<std::string> alphabet;

  for (std::set<std::string>::iterator it = alphabet_.alphabet_set_.begin();
                                    it != alphabet_.alphabet_set_.end(); ++it) {
      alphabet.emplace_back(*it);
    }

  sort(alphabet.begin(), alphabet.end(), compare);

  for(long unsigned int i{chain.length()}; i > 0; i--) {

    //for para hacer iteraciones igual a la longitud del alfabeto
    for(long unsigned int j {alphabet.size()}; j > 0; j--){
      //Cogemos los x primeros términos de chain(copia de cadena)
      long unsigned int x{alphabet[j-1].length()};
      std::string symbol;
      for(long unsigned int y{0}; y < x; y++) {
        symbol = symbol + chain[y];
      }
      //Comparamos si los x primeros términos son iguales y
      //en caso afirmativo creamos la cadena
      if(symbol == alphabet[j-1]) {
        chain.erase(0,symbol.length());
        chain_.push_back(symbol);
      }
    }
  }
}


std::ostream& operator<<(std::ostream& os, Chain& chain) { 
  for ( int i{0}; i < chain.chain_.size(); i++ ) {
    os << chain.chain_[i] << " ";
  }

  return (os);
}