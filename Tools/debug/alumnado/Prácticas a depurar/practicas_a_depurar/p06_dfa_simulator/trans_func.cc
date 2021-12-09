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
 * @file trans_func.cc
 * @brief Donde se desarrollan las funciones de la clase TransFunc contenida
 * en el archivo de cabecera trans_func.h.
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
 * 08/11/21 - He terminado la clase y sus métodos.
 */

#include "trans_func.h"

TransFunc::TransFunc(void) : trans_func_(), conversion_table_() {}

TransFunc::TransFunc(const int& num_status) 
    : trans_func_(), conversion_table_() {
  if (num_status > 0) trans_func_.resize(num_status);
}

TransFunc::TransFunc(const TransFunc& trans_func) 
    : trans_func_(trans_func.trans_func_), 
      conversion_table_(trans_func.conversion_table_) {}

void TransFunc::AddSymbol(const Symbol& symbol) {
  if (conversion_table_.size() == 0) {
    conversion_table_.emplace_back(symbol);
    for (size_t i{0}; i < trans_func_.size(); ++i) {
      trans_func_[i].emplace_back(-1);
    }
  } else {
    for (size_t i{0}; i < conversion_table_.size(); ++i) {
      if (symbol == conversion_table_[i]) break;
      if (i == (conversion_table_.size() - 1)) {
        conversion_table_.emplace_back(symbol);
        for (size_t i{0}; i < trans_func_.size(); ++i) {
          trans_func_[i].emplace_back(-1);
        }
      }
    }
  }
}

bool TransFunc::AddState(const int& state) {
  bool result{false};
  if (state == int(trans_func_.size())) {
    std::vector<int> aux(conversion_table_.size(), -1);
    trans_func_.emplace_back(aux);
  } else {
    result = true;
  }

  return result;
}

bool TransFunc::AddTransition(const int& state, const Symbol& symbol, 
                              const int& next_state) {
  bool result{false};
  int col{-1};
  if (next_state >= int(trans_func_.size()) || next_state < 0) result = true;
  if (state >= int(trans_func_.size()) || state < 0) result = true;
  for (size_t i{0}; i < conversion_table_.size(); ++i) {
    if (symbol == conversion_table_[i]) {
      col = int(i);
      break;
    }
  }

  if (col == -1) result = true;

  if (result == false) {
    trans_func_[state][col] = next_state;
  }

  return result;
}

int TransFunc::NextState(const int& state, const Symbol& symbol) const {
  int result{0};
  int col{-1};
  if (state >= int(trans_func_.size()) || state < 0) result = -1;
  for (size_t i{0}; i < conversion_table_.size(); ++i) {
    if (symbol == conversion_table_[i]) col = i;
  }

  if (col == -1) result = -1;
  if (result >= 0) result = trans_func_[state][col];
  return result;
}

bool TransFunc::IsItADfa(void) const {
  bool result{true};
  for (size_t i{0}; i < trans_func_.size(); ++i) {
    if (conversion_table_.size() == trans_func_[i].size()) {
      for (size_t j{0}; j < trans_func_[i].size(); ++j) {
        if (trans_func_[i][j] >= int(trans_func_.size()) || 
            trans_func_[i][j] < 0) {
          result = false;
          break;
        }
      }
    } else {
      result = false;
      break;
    }

    if (!result) break;
  }

  return result;
}

bool TransFunc::IsItInConversionTable(const Symbol& symbol) const {
  bool result{false};
  for (size_t i{0}; i < conversion_table_.size(); ++i) {
    if (symbol == conversion_table_[i]) {
      result = true;
      break;
    }
  }

  return result;
}

bool TransFunc::IsItAState(const int& state) const {
  if (state >= 0 && state < int(trans_func_.size())) return true;
  return false;
}

size_t TransFunc::Size(void) const {
  return trans_func_.size();
}

void TransFunc::operator=(const TransFunc& trans_func) {
  trans_func_ = trans_func.trans_func_;
  conversion_table_ = trans_func.conversion_table_;
}

std::ostream& operator<<(std::ostream& out, const TransFunc& trans_func) {
  for (int i{-1}; i < int(trans_func.trans_func_.size()); ++i) {
    if (i == -1) {
      out << '\n';
      out << "| F.T |";
      for (size_t k{0}; k < trans_func.conversion_table_.size(); ++k) {
        out << " " << trans_func.conversion_table_[k] << " |";
      }

      out << '\n';
      continue;
    }

    out << '\n';
    out << "| E " << i << " |";
    for (int j{0}; j < int(trans_func.conversion_table_.size()); ++j) {
      out << " " << trans_func.trans_func_[i][j] << " |";
    }

    out << '\n';
  }
  
  return out;
}
