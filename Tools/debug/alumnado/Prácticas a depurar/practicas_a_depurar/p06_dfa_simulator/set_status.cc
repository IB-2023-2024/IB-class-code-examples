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
 * @file set_status.cc
 * @brief Donde se desarrollan las funciones de la clase SetStatus contenida
 * en el archivo de cabecera set_status.h.
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
 *
 */

#include "set_status.h"

SetStatus::SetStatus(void) : name_("sin nombre"), set_status_() {}

SetStatus::SetStatus(const std::string& name) : name_(name), set_status_() {}

SetStatus::SetStatus(const std::string& name, const size_t& num_status) 
    : name_(name), set_status_() {
  for (size_t i{0}; i < num_status; ++i) set_status_.insert(i);
}

SetStatus::SetStatus(const std::string& name, const std::set<size_t>& status) 
    : name_(name), set_status_(status) {}

SetStatus::SetStatus(const SetStatus& status) 
    : name_(status.name_), set_status_(status.set_status_) {}

void SetStatus::Insert(const size_t& state) {
  set_status_.insert(state);
}

void SetStatus::SetSet(const std::set<size_t>& status) {
  set_status_ = status;  
}

void SetStatus::SetSet(const SetStatus& status) {
  set_status_ = status.set_status_;
}

void SetStatus::SetName(const char& name) {
  name_ = name;
}

void SetStatus::SetName(const std::string& name) {
  name_ = name;
}

int SetStatus::At(const size_t& position) const {
  int result{-1};
  size_t count{0};
  for (std::set<size_t>::iterator i{set_status_.begin()}; 
       i != set_status_.end(); ++i) {
    if (position == count) result = *i;
    ++count;
  }

  return result;
}

std::string SetStatus::GetName(void) const {
  return name_;
}

std::set<size_t> SetStatus::GetSetStatus(void) const {
  return set_status_;
}

bool SetStatus::IsItAState(const size_t& num) const {
  bool result{false};
  for (std::set<size_t>::iterator i{set_status_.begin()}; 
       i != set_status_.end(); ++i) {
    if (num == *i) {
      result = true;
      break;
    }
  }

  return result;
}

void SetStatus::Clear(void) {
  set_status_.clear();
}

void SetStatus::operator=(const SetStatus& status) {
  name_ = status.name_;
  set_status_ = status.set_status_;
}

int SetStatus::operator[](const size_t& state) const {
  return this->At(state);
}

std::ostream& operator<<(std::ostream& out, const SetStatus& status) {
  out << "Conjunto de estados " << status.name_ << " = ";
  std::string aux{"{"};
  if (!status.set_status_.empty()) {
    for (std::set<size_t>::iterator i{status.set_status_.begin()}; 
         i != status.set_status_.end(); ++i) {
      aux = aux + std::to_string(*i) + ", ";
    }
    aux.pop_back(); ///< Quitamos el último espacio.
    aux.pop_back(); ///< Quitamos la última coma.
    out << aux << '}';
  } else {
    out << "{VOID}";
  }
  
  return out;
}


