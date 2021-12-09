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
// Archivo set_status_class.cc:
// 
// Donde se desarrollan las funciones de la clase SetStatus contenida
// en el archivo de cabecera set_status_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 27/10/2021 - Creacion (primera version) del codigo
//              Solo he creado el archivo, le he puesto el comentario de
//              cabecera y declarado su include
// 30/10/2021 - He terminado la clase y sus metodos

#include "set_status_class.h"

SetStatus::SetStatus() 
    : name_("Conjunto de Estados sin nombre"), set_status_() {}

SetStatus::SetStatus(const std::string& name, const size_t& num_status) 
    : name_("Conjunto de Estados " + name), set_status_() {
  set_status_.reserve(num_status); // Reservamos el espacio una vez
  for (size_t i{0}; i < num_status; ++i) {
    set_status_.emplace_back(i); // Metemos el valor de la posicion
  }
}

SetStatus::SetStatus(const std::string& name, 
                     const std::vector<size_t>& end_status)
    : name_("Conjunto de Estados " + name), set_status_(end_status) {}

SetStatus::SetStatus(const SetStatus& set_status) 
    : name_(set_status.name_), set_status_(set_status.set_status_) {}

bool SetStatus::IsItAState(const size_t num) {
  bool result{false};
  for (size_t i{0}; i < set_status_.size(); ++i) {
    if (num == set_status_[i]) {
      result = true;
      break;
    }
  }
  return result;
}

void SetStatus::operator=(const SetStatus& set_status) {
  name_ = set_status.name_;
  set_status_ = set_status.set_status_;
}

std::ostream& operator<<(std::ostream& out, SetStatus& set_status) {
  out << set_status.name_ << " = ";
  if (set_status.set_status_.size() > 0) {
    std::string aux{"{"};
    for (size_t i{0}; i < set_status.set_status_.size(); ++i) {
      aux += std::to_string(set_status.set_status_[i]) + ", ";
    }
    aux.pop_back();
    aux.pop_back();
    out << aux + "}";
  } else {
    out << "{VOID}";
  }
  return out;
}
