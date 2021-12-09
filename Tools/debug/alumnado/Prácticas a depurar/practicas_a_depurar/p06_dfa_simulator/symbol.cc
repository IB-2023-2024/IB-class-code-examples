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
 * @file symbol.cc
 * @brief Donde se desarrollan las funciones de la clase Symbol contenida
 * en el archivo de cabecera symbol.h.
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

#include "symbol.h"

Symbol::Symbol() : symbol_() {}

Symbol::Symbol(const char& character) {
  symbol_ = character;
}

Symbol::Symbol(const std::string& chain) : symbol_(chain) {}

Symbol::Symbol(const Symbol& symbol) : symbol_(symbol.GetSymbol()){}

void Symbol::SetSymbol(const char& character) {
  symbol_ = character;
}

void Symbol::SetSymbol(const std::string& chain) {
  symbol_ = chain;
}

void Symbol::SetSymbol(const Symbol& symbol) {
  *this = symbol;
}

void Symbol::EmplaceBack(const char& character) {
  symbol_ += character;
}

void Symbol::EmplaceBack(const std::string& chain) {
  symbol_ += chain;
}

void Symbol::EmplaceBack(const Symbol& symbol) {
  symbol_ += symbol.symbol_;
}

std::string Symbol::GetSymbol(void) const {
  return symbol_;
}

size_t Symbol::Size(void) const {
  return symbol_.size();
}

bool Symbol::operator==(const Symbol& symbol) const {
  return symbol_ == symbol.symbol_;
}

void Symbol::operator=(const Symbol& symbol) {
  symbol_ = symbol.symbol_;
}

void Symbol::operator+=(const Symbol& symbol) {
  symbol_ += symbol.symbol_;
}

Symbol Symbol::operator+(const Symbol& symbol) {
  *this += symbol;
  return *this;
}

bool Symbol::operator<(const Symbol& symbol) const {
  return (symbol_ < symbol.symbol_);
}

std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  return out << symbol.symbol_;
}

std::istream& operator>>(std::istream& input, Symbol& symbol) {
  return input >> symbol.symbol_;
}
