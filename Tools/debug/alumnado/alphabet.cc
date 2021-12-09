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

#include "alphabet.h"
#include <iostream>
#include <fstream>
#include <regex>

Alphabet::Alphabet (std::ifstream& r_dfa, std::string& input_dfa) {
  std::string readed_line;
//   std::regex reg ("[a-zA-Z]");
//   std::smatch m;
  //Abrimos los archivos de lectura
  r_dfa.open(input_dfa, std::ios::in);

  //Comprobamos si el archivo está creado y/o se puede abrir correctamente
  if (r_dfa.fail()) {
    std::cout << "El archivo no se pudo abrir o no se ha creado" << std::endl;
  }

  while (!r_dfa.eof()) {

    getline(r_dfa, readed_line);
    std::smatch m;
    std::regex e ("[a-zA-Z]+|&");
    while (std::regex_search (readed_line,m,e)) {
    for (std::string x:m) {
        alphabet_set_.insert(x);
    }
    readed_line = m.suffix().str();
  }
   
  }

  for (std::set<std::string>::iterator it = alphabet_set_.begin();
                                 it != alphabet_set_.end(); ++it) {
    alphabet_ +=*it + " ";
  }

  r_dfa.close();

}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  for (std::set<std::string>::iterator it = alphabet.alphabet_set_.begin();
                                  it != alphabet.alphabet_set_.end(); ++it) {
    os << ' ' << *it;
  }
  return (os);
}

std::string Alphabet::Symbol(int i) {
  std::string s;
  int counter{0};
  for (std::set<std::string>::iterator it = alphabet_set_.begin();
                                  it != alphabet_set_.end(); ++it) {
    if (counter == i ) {
      s = *it;
    }
    counter++;
  }
  return(s);
  
}

bool Alphabet::IsContained(std::string& symbol) {
  bool is_contained = false;
  for (std::set<std::string>::iterator it = alphabet_set_.begin();
                                  it != alphabet_set_.end(); ++it) {
    if (symbol == *it) {
      is_contained = true;
    }
  }
  return (is_contained);
}