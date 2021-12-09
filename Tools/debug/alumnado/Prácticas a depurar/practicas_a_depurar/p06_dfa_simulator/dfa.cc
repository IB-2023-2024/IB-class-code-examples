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
 * @file dfa.cc
 * @brief Donde se desarrollan las funciones de la clase Dfa contenida
 * en el archivo de cabecera dfa.h.
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

#include "dfa.h"

Dfa::Dfa(void) 
    : alphabet_(), all_status_(), initial_state_(), aceptation_status_(), 
      trans_func_() {}

Dfa::Dfa(std::ifstream& dfa_def) 
    : alphabet_(), all_status_(), initial_state_(1), aceptation_status_(), 
      trans_func_(), creation_failed_(false) {
  std::vector<std::string> file;
  std::string aux_chain{""};
  int num_transitions{-1}; 
  size_t count_lines{0};
  Symbol symbol;

  /// Leemos todo el archivo de entrada para almacenarlo.
  while (!dfa_def.eof()) {
    getline(dfa_def, aux_chain);
    file.emplace_back(aux_chain);
  }
  
  /// Iteramos por cada línea del archivo.
  for (size_t i{0}; i < file.size(); ++i) {
    if (file[i] == "" || file[i].front() == ' ') continue;
    std::istringstream act_line(file[i]);
    aux_chain = "";
    ++count_lines;

    /// Caso para cuando leemos la línea 1.
    if (count_lines == 1) {
      bool readed{false};
      while (getline(act_line, aux_chain, ' ')) {
        if (!readed) {
          readed = !readed;
          if (std::stoi(aux_chain) < 0) {
            creation_failed_ = true;
            break;
          } else {
            TransFunc aux(std::stoi(aux_chain));
            trans_func_ = aux;
          }
        } else {
          creation_failed_ = true;
          break;
        }
      }

      if (creation_failed_) break;
      continue;
    }

    /// Caso para cuando leemos la línea 2.
    if (count_lines == 2) {
      bool readed{false};
      while (getline(act_line, aux_chain, ' ')) {
        if (!readed) {
          readed = true;
          if (std::stoi(aux_chain) < 0 || 
              std::stoi(aux_chain) >= int(trans_func_.Size())) {
            creation_failed_ = true;
            break;
          } else {
            initial_state_ = std::stoi(aux_chain);
          }
        } else {
          creation_failed_ = true;
          break;
        }
      }

      if (creation_failed_) break;
      continue;
    }

    size_t readed_things_in_line{0};
    int act_state{-1};
    /// Ahora leemos las líneas donde se encuentra la información principal
    /// Por cada línea, leemos todas sus strings.
    while (getline(act_line, aux_chain, ' ')) {
      ++readed_things_in_line;
      /// Leemos que estado vamos a analizar.
      if (readed_things_in_line == 1) {
        if (std::stoi(aux_chain) >= 0 && 
            std::stoi(aux_chain) < int(trans_func_.Size())) {
          act_state = std::stoi(aux_chain);
        } else {
          creation_failed_ = true;
          break;
        }
        continue;
      }

      /// Leemos si es de aceptación.
      if (readed_things_in_line == 2) {
        if (aux_chain != "0" && aux_chain != "1") {
          creation_failed_ = true;
          break;
        }

        if (aux_chain == "1") {
          aceptation_status_.Insert(act_state);
        }
        continue;
      }

      /// Leemos el número de transiciones, solo lo escribimos una vez.
      if (readed_things_in_line == 3) {
        if (num_transitions == -1) {
          num_transitions = std::stoi(aux_chain);
        } else {
          if (std::stoi(aux_chain) != num_transitions) {
            creation_failed_ = true;
            break;
          }
        }
        continue;
      }

      /// Si nos pasamos de transiciones establecidas, hay error de lectura.
      if (int(readed_things_in_line) > ((num_transitions * 2) + 3)) {
        creation_failed_ = true;
        break;
      }

      /// Las posiciones pares equivalen a los símbolos, los leemos sin dudar.
      if ((readed_things_in_line % 2) == 0) {
        Symbol aux(aux_chain);
        symbol = aux;
        if (count_lines != 3) {
          if (!alphabet_.IsItInAlphabet(aux)) {
            creation_failed_ = true;
            break;
          }
        } else {
          alphabet_.Insert(symbol);
          trans_func_.AddSymbol(symbol);
        }
      } else { /// Las impares son los estados a los que llevan.
        if (std::stoi(aux_chain) >= 0 && 
            std::stoi(aux_chain) < int(trans_func_.Size())) {
              int next_state{std::stoi(aux_chain)};
          /// Si devuelve true, ha habido un error.
          if (trans_func_.AddTransition(act_state, symbol, next_state)) {
            creation_failed_ = true;
            break;
          }
        } else {
          creation_failed_ = true;
          break;
        }
      }
    }

    /// Si nos pasamos de transiciones establecidas, hay error de lectura.
      if (int(readed_things_in_line) != ((num_transitions * 2) + 3)) {
        creation_failed_ = true;
        break;
      }

    if (creation_failed_) break;
  }

  if (count_lines != (2 + trans_func_.Size())) creation_failed_ = true;
}

Dfa::Dfa(const Dfa& dfa)
    : alphabet_(dfa.alphabet_), all_status_(dfa.all_status_), 
      initial_state_(dfa.initial_state_), 
      aceptation_status_(dfa.aceptation_status_), 
      trans_func_(dfa.trans_func_) {}

Alphabet Dfa::GetAlphabet(void) const {
  return alphabet_;
}

SetStatus Dfa::GetAllStatus(void) const {
  return all_status_;
}

int Dfa::GetInitialState(void) const {
  return initial_state_;
}

SetStatus Dfa::GetAceptationStatus(void) const {
  return aceptation_status_;
}

TransFunc Dfa::GetTransFunc(void) const {
  return trans_func_;
}

bool Dfa::Fail(void) const {
  return creation_failed_;
}

bool Dfa::IsItInAlphabet(const Chain& chain) const {
  bool result{true};
  for (size_t i{0}; i < chain.Size(); ++i) {
    if (!alphabet_.IsItInAlphabet(chain[i])) {
      result = false;
      break;
    }
  }
  return result;
}

bool Dfa::EvalStr(const Chain& chain) const {
  bool result{false};
  int act_state{initial_state_};
  for (size_t i{0}; i < chain.Size(); ++i) {
    act_state = trans_func_.NextState(act_state, chain[i]);
  }

  if (aceptation_status_.IsItAState(std::size_t(act_state))) result = true;
  return result;
}

void Dfa::EvalStrInFile(std::ifstream& input, std::ofstream& out) const {
  std::vector<std::string> vec_words;
  std::string aux_chain{""};
  while (!input.eof()) {
    getline(input, aux_chain);
    vec_words.emplace_back(aux_chain);
  }

  for (size_t i{0}; i < vec_words.size(); ++i) {
    Chain chain;
    std::istringstream aux_stringstream(vec_words[i]);
    for (size_t j{0}; j < vec_words[i].size(); ++j) {
      Symbol temp(vec_words[i][j]);
      chain.EmplaceBack(temp);
    }

    if (chain[0].GetSymbol() == "&" && chain.Size() == 1) {
      out << "& -- Accepted\n";
      continue;
    } else {
      if (!this->IsItInAlphabet(chain)) {
        out << chain << " -- Rejected (no está en el alfabeto)\n";
        continue;
      }
    }
    

    if (this->EvalStr(chain)) {
      out << chain << " -- Accepted";
    } else {
      out << chain << " -- Rejected";
    }

    if (i != (vec_words.size() - 1)) out << std::endl;
  }
}

std::ostream& operator<<(std::ostream& out, const Dfa& dfa) {
  out << "Este Autómata Finito Determinista (AFN o DFA) está compuesto por";
  out << "\nuna colección de 5 elementos:";
  out << "\n\n1. Un alfabeto de entrada (Sigma):";
  out << "\n   " << dfa.alphabet_; 
  out << "\n\n2. Una colección finita de estados Q:";
  out << "\n   " << dfa.all_status_;
  out << "\n\n3. Un estado inicial 's': " << dfa.initial_state_;
  out << "\n\n4. Una colección F de estados finales o de aceptación:";
  out << "\n   " << dfa.aceptation_status_;
  out << "\n\n5. Una función de transición de estados: Q x (Símb. Alf.) ==> Q";
  out << "\n   que determina el único estado siguiente para el";
  out << "\n   par (Qi, simb.) correspondiente al estado actual y la entrada:";
  out << '\n' << dfa.trans_func_ << '\n';

  return out;
}
