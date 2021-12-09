// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Autómatas Finitos y Reconocimiento de Patrones
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 27/10/2021
//
// Archivo alphabet_class.cc:
// 
// Donde se desarrollan las funciones de la clase Alphabet contenida
// en el archivo de cabecera alphabet_class.h
//
// Referencias:
// Enlaces de interes
// 
// Historial de revisiones
// 27/10/2021 - Creacion (primera version) del codigo
//              Solo he creado el archivo, le he puesto el comentario de
//              cabecera y declarado su include
// 28/10/2021 - He creado el contenido de la clase, 3 constructores, dos
//              funciones, dos atributos privados y he escrito el codigo de
//              los metodos
// 30/10/2021 - He terminado la clase y sus metodos

#include "alphabet_class.h"

Alphabet::Alphabet() : name_("Alfabeto Sin Nombre"), alphabet_() {}

// Constructor para alfabetos de cadenas de ADN
Alphabet::Alphabet(const std::string& name, 
                   const char& A, const char& C, const char& G, const char& T)
    : name_("Alfabeto " + name), alphabet_() {
  alphabet_.insert(A);
  alphabet_.insert(C);
  alphabet_.insert(G);
  alphabet_.insert(T);
}

Alphabet::Alphabet(const Alphabet& alphabet) 
    : name_(alphabet.name_), alphabet_(alphabet.alphabet_) {}

// Funcion que analiza si la cadena a evaluar tiene simbolos del alfabeto
bool Alphabet::IsItInAlphabet(const std::string& chain) {
  bool result{true};
  bool aux{false}; // Nos dice si el caracter actual está contenido 
  for (size_t i{0}; i < chain.size(); ++i) {
    aux = false;
    for (std::set<char>::iterator j{alphabet_.begin()}; j != alphabet_.end();
         ++j) {
      if (chain[i] == *j) {
        aux = true;
        break;
      }
    }
    if (!aux) {
      result = false;
      break;
    }
  }
  return result;
}

void Alphabet::operator=(const Alphabet& alphabet) {
  name_ = alphabet.name_;
  alphabet_ = alphabet.alphabet_;
}

std::ostream& operator<<(std::ostream& out, Alphabet& alphabet) {
  out << alphabet.name_ + " = ";
  std::string aux{"{"};
  if (alphabet.alphabet_.size() > 0) {
    size_t j{0};
    for (std::set<char>::iterator i{alphabet.alphabet_.begin()}; 
         j < alphabet.alphabet_.size(); ++i, ++j) {
      aux = aux + *i + ", ";
    }
    aux.pop_back(); // Quitamos la ultima coma y espacio
    aux.pop_back();
    out << aux << '}';
  } else {
    out << "{VOID}";
  }
  
  return out;
}

std::set<char> Alphabet::GetAlphabet() {
  return alphabet_;
}
