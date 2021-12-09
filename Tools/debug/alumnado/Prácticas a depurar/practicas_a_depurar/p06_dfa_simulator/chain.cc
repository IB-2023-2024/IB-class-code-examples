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
 * @file chain.cc
 * @brief Donde se desarrollan las funciones de la clase Chain contenida
 * en el archivo de cabecera chain.h.
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

#include "chain.h"

Chain::Chain(void) : chain_() {}

Chain::Chain(const std::vector<Symbol>& chain) : chain_(chain) {}

Chain::Chain(const Chain& chain) : chain_(chain.GetChain()) {}

void Chain::EmplaceBack(const char& symbol) {
  Symbol aux(symbol);
  chain_.emplace_back(aux);
}

void Chain::EmplaceBack(const std::string& symbol) {
  Symbol aux(symbol);
  chain_.emplace_back(aux);
}

void Chain::EmplaceBack(const Symbol& symbol) {
  chain_.emplace_back(symbol);
}

std::vector<Symbol> Chain::GetChain(void) const {
  return chain_;
}

Symbol Chain::At(const size_t& position) const {
  if (position < chain_.size()) {
    return chain_[position];
  } else {
    Symbol aux("NULL");
    return aux;
  }
}

void Chain::Clear(void) {
  chain_.clear();
}

size_t Chain::Size(void) const {
  return chain_.size();
}

void Chain::operator=(const Chain& chain) {
  chain_.clear();
  for (size_t i{0}; i < chain.Size(); ++i) {
    chain_.emplace_back(chain[i]);
  }
}

bool Chain::operator==(const Chain& chain) const {
  bool result{true};
  if (chain.Size() == chain_.size()) {
    for (size_t i{0}; i < chain_.size(); ++i) {
      if (!(chain_[i] == chain[i])) {
        result = false;
        break;
      }
    }
  } else {
    result = false;
  }
  return result;
}

Symbol Chain::operator[](const size_t& position) const {
  return this->At(position);
}

Chain Chain::operator+(const Chain& chain) {
  for (size_t i{0}; i < chain.Size(); ++i) {
    chain_.emplace_back(chain[i]);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Chain& chain) {
  for (size_t i{0}; i < chain.Size(); ++i) {
    out << chain[i];
  }
  return out;
}

std::istream& operator>>(std::istream& input, Chain& chain) {
  size_t aux{0};
  std::cout << "¿Cuántos símbolos va a tener su cadena? ";
  std::cin >> aux;
  chain.chain_.reserve(aux);
  std::string aux_str{""};
  for (size_t i{0}; i < aux; ++i) {
    std::cout << "\nIntroduzca el símbolo " << i + 1 << ": ";
    std::cin >> aux_str;
    chain.EmplaceBack(aux_str);
  }
  
  return input;
}
