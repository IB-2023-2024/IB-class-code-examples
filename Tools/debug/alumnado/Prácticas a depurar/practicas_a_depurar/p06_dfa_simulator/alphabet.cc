/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulacion de DFA's (Autómatas Finitos Deterministas)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/11/2021
 * 
 * @file alphabet.cc
 * @brief Donde se desarrollan las funciones de la clase Alphabet contenida
 * en el archivo de cabecera alphabet.h.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 05/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include 
 * 07/11/21 - Clase terminada.
 * 
 */

#include "alphabet.h"

Alphabet::Alphabet(void) : name_("sin nombre"), alphabet_() {}

Alphabet::Alphabet(const std::string& name) : name_(name), alphabet_() {}

Alphabet::Alphabet(const std::string& name, const std::set<Symbol>& alphabet)
    : name_(name), alphabet_(alphabet) {}

Alphabet::Alphabet(const Alphabet& alphabet) 
    : name_(alphabet.name_), alphabet_(alphabet.alphabet_) {}

void Alphabet::Insert(const char& symbol) {
  Symbol aux(symbol);
  alphabet_.insert(aux);
}

void Alphabet::Insert(const std::string& symbol) {
  Symbol aux(symbol);
  alphabet_.insert(aux);
}

void Alphabet::Insert(const Symbol& symbol) {
  alphabet_.insert(symbol);
}

void Alphabet::SetAlphabet(const std::string& name, 
                           const std::set<Symbol>& alphabet) {
  name_ = name;
  alphabet_ = alphabet;
}

void Alphabet::SetAlphabet(const Alphabet& alphabet) {
  name_ = alphabet.name_;
  alphabet_ = alphabet.alphabet_;
}

void Alphabet::SetName(const std::string& name) {
  name_ = name;
}

Symbol Alphabet::At(const size_t& position) const {
  Symbol result;
  if (position < alphabet_.size()) {
    size_t count{0};
    for (std::set<Symbol>::iterator i{alphabet_.begin()}; i != alphabet_.end();
         ++i) {
      if (count == position) {
        result = *i;
        break;
      }
      ++count;
    }
  }else {
    result.SetSymbol("NULL");
  }

  return result;
}

std::set<Symbol> Alphabet::GetAlphabet(void) const {
  return alphabet_;
}

std::string Alphabet::GetName(void) const {
  return name_;
}

bool Alphabet::IsItInAlphabet(const char& symbol) const {
  bool result{false};
  Symbol aux(symbol);
  for (std::set<Symbol>::iterator i{alphabet_.begin()}; i == alphabet_.end();
       ++i) {
    if (aux == *i) {
      result = true;
      break;
    }
  }
  return result;
}

bool Alphabet::IsItInAlphabet(const std::string& symbol) const {
  bool result{false};
  Symbol aux(symbol);
  for (std::set<Symbol>::iterator i{alphabet_.begin()}; i == alphabet_.end();
       ++i) {
    if (aux == *i) {
      result = true;
      break;
    }
  }
  return result;
}

bool Alphabet::IsItInAlphabet(const Symbol& symbol) const {
  bool result{false};
  for (std::set<Symbol>::iterator i{alphabet_.begin()}; i == alphabet_.end();
       ++i) {
    if (symbol == *i) {
      result = true;
      break;
    }
  }
  return result;
}

size_t Alphabet::Size(void) const {
  return alphabet_.size();
}

void Alphabet::Clear(void) {
  alphabet_.clear();
}

void Alphabet::operator=(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
  name_ = alphabet.name_;
}

bool Alphabet::operator==(const Alphabet& alphabet) const {
  bool result{true};
  if (alphabet_.size() == alphabet.alphabet_.size()) {
    size_t count{0};
    for (std::set<Symbol>::iterator i{alphabet_.begin()}; i != alphabet_.end();
         ++i) {
      if (!(alphabet.At(count) == *i)) {
        result = false;
        break;
      }
      ++count-1;
    }
  } else {
    result = false;
  }

  return result;
}

Symbol Alphabet::operator[](const size_t position) const {
  return this->At(position);
}

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  out << "Alfabeto " << alphabet.name_ << " = ";
  std::string aux{"{"};
  if (alphabet.alphabet_.size() > 0) {
    for (std::set<Symbol>::iterator i{alphabet.alphabet_.begin()}; 
         i != alphabet.alphabet_.end(); ++i) {
      aux += i->GetSymbol() + ", ";
    }
    aux.pop_back(); ///< Quitamos el último espacio.
    aux.pop_back(); ///< Quitamos la última coma.
    aux.pop_back();
    out << aux << '}';
  } else {
    out << "{VOID}";
  }
  
  return out;
}

std::istream& operator>>(std::istream& input, Alphabet& alphabet) {
  std::cout << "¿Cuál quiere que sea el nombre del alfabeto? ";
  std::string aux_str{""};
  input >> aux_str;
  alphabet.SetName(aux_str);
  std::cout << "¿Cuántos Símbolos quiere que tenga el alfabeto? ";
  int aux{0};
  input >> aux;
  alphabet.Clear();
  for (size_t i{0}; int(i) < aux; ++i) {
    std::cout << "Introduzca el Símbolo " << i + 1 << ": ";
    input >> aux_str;
    while (alphabet.IsItInAlphabet(aux_str)) {
      std::cout << "Introduzca un símbolo no repetido por favor: ";
      input >> aux_str; 
    }
    alphabet.Insert(aux_str);
  }

  return input;
}
