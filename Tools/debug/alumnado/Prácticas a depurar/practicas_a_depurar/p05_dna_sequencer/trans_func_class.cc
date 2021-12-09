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
// Archivo trans_func_class.cc:
// 
// Donde se desarrollan las funciones de la clase TransFunc contenida
// en el archivo de cabecera trans_func_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 27/10/2021 - Creacion (primera version) del codigo
//              Solo he creado el archivo, le he puesto el comentario de
//              cabecera y declarado su include
// 30/10/2021 - He terminado la clase y sus metodos

#include "trans_func_class.h"

TransFunc::TransFunc() = default;

TransFunc::TransFunc(const std::vector<std::vector<size_t>>& trans_func, 
                     Alphabet& alphabet) {
  trans_func_ = trans_func;
  size_t col{0}; // Guarda el valor de la columna actual
  std::set<char> aux{alphabet.GetAlphabet()}; // LO sacamos para usarlo
  // Marcamos que por cada simbolo, hay un vector o columna asociada
  conversion_table_.reserve(aux.size()); 
  for (auto i{aux.begin()}; i != aux.end(); ++i, ++col) {
    // Al inicio va el caracter del alfabeto, al final está el número que nos
    // referencia en el vector trans_func_ a cual de sus columnas hay que irse
    std::vector<std::string> aux_vec{std::to_string(*i), std::to_string(col)};
    conversion_table_.emplace_back(aux_vec);
  }
}

TransFunc::TransFunc(const TransFunc& trans_func) {
  trans_func_ = trans_func.trans_func_;
  conversion_table_ = trans_func.conversion_table_;
}

size_t TransFunc::NextState(const size_t& actual_state, 
                            const char& actual_symbol) {
  size_t result{0};
  size_t aux_col{0}; 
  for (size_t i{0}; i < conversion_table_.size(); ++i) {
    int aux_int{std::stoi(conversion_table_[i].front())};
    if (char(aux_int) == actual_symbol) {
      aux_col = std::stoi(conversion_table_[i].back());
      break; // Paramos de buscar
    }
  }

  // Si se da el error de que el estado siguiente está en una posición de 
  // memoria que no se puede acceder, directamente se retorna cero
  if (actual_state < trans_func_.size()) {
    result = trans_func_[actual_state][aux_col];
  }

  return result;
}

void TransFunc::operator=(const TransFunc& trans_func) {
  trans_func_ = trans_func.trans_func_;
  conversion_table_ = trans_func.conversion_table_;
}

std::ostream& operator<<(std::ostream& out, TransFunc& trans_func) {
  std::string ceiling{"-----"};
  // Definimos el string que hará de techo y suelo de las filas de la tabla
  for (size_t i{0}; i < trans_func.conversion_table_.size(); ++i) {
    // en base a las variables de la clase, será más o menos grande
    ceiling += "-----";
  }
  ceiling.pop_back();
  ceiling.pop_back(); // Quitamos dos ultimos caracteres que sobran

  // Recorremos la función de transición para imprimir sus valores
  for (int i{-1}; i < int(trans_func.trans_func_.size()); ++i) {
    // Iniciamos en -1 para poder declarar el encabezado de la tabla
    if (i == -1) {
      out << ceiling + '\n';
      out << "| F.T |";
      // Aqui imprimimos los simbolos del alfabeto en el encabezado
      for (size_t k{0}; k < trans_func.conversion_table_.size(); ++k) {
        // Aquí hacemos conversiones para que los valores se impriman en valor
        // de char y no en representación de caracteres ASCII
        int aux_int{std::stoi(trans_func.conversion_table_[k][0])};
        char aux{char(aux_int)};
        out << " " << aux << " |";
      }

      out << '\n';
      out << ceiling;
      continue;
    }

    out << '\n';
    out << "| E " << i << " |";
    
    // Imprimimos cada fila con sus valores
    for (int j{0}; j < int(trans_func.conversion_table_.size()); ++j) {
      out << " " << trans_func.trans_func_[i][j] << " |";
    }

    out << '\n' << ceiling;
  }
  
  return out;
}
