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
// Archivo dfa_dna_class.cc:
// 
// Donde se desarrollan las funciones de la clase DfaDna contenida
// en el archivo de cabecera dfa_dna_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 27/10/2021 - Creacion (primera version) del codigo
//              Solo he creado el archivo, le he puesto el comentario de
//              cabecera y declarado su include
// 

#include "dfa_dna_class.h"

DfaDna::DfaDna() {
  // Como no puedo usar la inialización en lista, creo unos objetos y se los
  // paso a los de la clase con el operador "="
  const char kA{'A'};
  const char kC{'C'};
  const char kG{'G'};
  const char kT{'T'};
  const std::string kAlphabetName{"ADN"};
  const Alphabet aux_alphabet(kAlphabetName, kA, kC, kG, kT);
  alphabet_ = aux_alphabet;
  
  const std::string kAllStatusName{"de arranque del DFA"};
  const size_t kAllStatusNum{6};
  const SetStatus aux_all_status(kAllStatusName, kAllStatusNum);
  all_status_ = aux_all_status;

  initial_state_ = 0;

  const std::string kNameAcepStatus{"de aceptación del DFA"};
  const std::vector<size_t> kVecAcepStatus{2, 4};
  const SetStatus aux_aceptation_status(kNameAcepStatus, kVecAcepStatus);
  aceptation_status_ = aux_aceptation_status;

  // Creamos el vector que hará de función de transición y ponemos los valores
  // de la función con ayuda de un for y varios if's, no uso un switch porque 
  // no me dejaba declarar una variable dentro de un case
  std::vector<std::vector<size_t>> vec_aux_trans_func;
  for (size_t i{0}; i < kAllStatusNum; ++i) {
    // Quería hacer un switch dentro del for, pero no me dejaba inicializar un
    // vector dentro de un case si había más de un case
    if (i == 0) {
      std::vector<size_t> aux{1, 5, 5, 3};
      vec_aux_trans_func.emplace_back(aux);
      continue;
    }

    if (i == 1 || i == 2) {
      std::vector<size_t> aux{2, 1, 1, 1};
      vec_aux_trans_func.emplace_back(aux);
      continue;
    }

    if (i == 3 || i == 4) {
      std::vector<size_t> aux{3, 3, 3, 4};
      vec_aux_trans_func.emplace_back(aux);
      continue;
    }

    if (i == 5) {
      std::vector<size_t> aux{5, 5, 5, 5};
      vec_aux_trans_func.emplace_back(aux);
    }
  }

  const TransFunc aux_trans_func(vec_aux_trans_func, alphabet_);
  trans_func_ = aux_trans_func;
}

DfaDna::DfaDna(const DfaDna& dfa_dna) {
  alphabet_ = dfa_dna.alphabet_;
  all_status_ = dfa_dna.all_status_;
  initial_state_ = dfa_dna.initial_state_;
  aceptation_status_ = dfa_dna.aceptation_status_;
  trans_func_ = dfa_dna.trans_func_;
}

bool DfaDna::IsItInAlphabet(const std::string& dna_chain) {
  return alphabet_.IsItInAlphabet(dna_chain);
}

void DfaDna::EvalSubstr(const std::string& dna_chain, 
                           std::ostream& output_accepted, 
                           std::ostream& output_rejected) {
  std::vector<std::string> vec_accepted;
  // Este if sería igual al if del main_dna_sequencer.cc donde miro si la
  // cadena tiene simbolos desconocidos, pero lo hago dos veces, una aquí
  // y otra allí porque así me aseguro de que nunca se le pase una cadena
  // invalida, por si en el futuro en una futura modificación del programa
  // reusara esta función y lo usara en un lugar donde no tenga el if del main
  if (!alphabet_.IsItInAlphabet(dna_chain)) {
    vec_accepted.emplace_back("Error de lectura, hay simbolos desconocidos");
  } else {
    if (dna_chain.size() < 2) {
      vec_accepted.emplace_back("Error, cadena muy pequeña para ser evaluada");
    } else {
      std::string act_substr{""};
      size_t act_state{initial_state_};

      // Este for recorre las longitudes que tendremos que coger a la hora de
      // ir extrayendo substring de la cadena dna_chain, empieza en 2 y termina
      // en la logitud total de la cadena
      for (size_t i{2}; i <= dna_chain.size(); ++i) {
        // Este for recorre la cadena dna_chain y va marcando la primera
        // posición donde vamos a empezar a extraer la substring
        for (size_t j{0}; (i + j) <= dna_chain.size(); ++j) {
          // Guardamos en cada iteración en act_substr el valor de todas las
          // substrings posibles de la cadena dna_chain
          act_state = 0;
          act_substr = dna_chain.substr(j, i);
          for (size_t k{0}; k < act_substr.size(); ++k) {
            // Pasamos al siguiente estado por cada simbolo de la cadena que
            // quede por leer
            const char aux_char = act_substr[k];
            act_state = trans_func_.NextState(act_state, aux_char);
          }
          // Si el estado actual es de aceptación, entonces se añade la
          // subcadena al vector de retorno, pero antes de añadirla,
          // comprobamos si la cadena que vamos a añadir, ya está incluida
          // en el vector, en cuyo caso, no la ponemos, es redundante
          if (aceptation_status_.IsItAState(act_state)) {
            if (vec_accepted.size() == 0) {
              vec_accepted.emplace_back(act_substr);
              output_accepted << act_substr << '\n';
            } else {
              for (size_t i{0}; i < vec_accepted.size(); ++i) {
                if (act_substr == vec_accepted[i]) break;
                if (i == (vec_accepted.size() - 1)) {
                  vec_accepted.emplace_back(act_substr);
                  output_accepted << act_substr << '\n';
                }
              }
            }
          } else {
            if (vec_accepted.size() == 0) {
              output_rejected << act_substr << '\n';
            } else {
              for (size_t i{0}; i < vec_accepted.size(); ++i) {
                if (act_substr == vec_accepted[i]) break;
                if (i == (vec_accepted.size() - 1)) {
                  output_rejected << act_substr << '\n';
                }
              }
            }
          }
        }
      }
    }
  }

}

std::ostream& operator<<(std::ostream& out, DfaDna& dfa_dna) {
  out << "Este Autómata Finito Determinista (AFN o DFA) está compuesto por";
  out << "\nuna colección de 5 elementos:";
  out << "\n\n1. Un alfabeto de entrada (Sigma):";
  // Debido a como tengo declarado el método, tengo que crear un objeto de la
  // clase y mostrar ese, porque no me deja mostrarlo directamente
  Alphabet show_alphabet(dfa_dna.GetAlphabet());
  out << "\n   " << show_alphabet; 

  out << "\n\n2. Una colección finita de estados Q:";
  SetStatus show_all_status(dfa_dna.GetAllStatus());
  out << "\n   " << show_all_status;

  out << "\n\n3. Un estado inicial 's': " << dfa_dna.GetInitialState();

  out << "\n\n4. Una colección F de estados finales o de aceptación:";
  SetStatus show_aceptation_status(dfa_dna.GetAceptationStatus());
  out << "\n   " << show_aceptation_status;

  out << "\n\n5. Una función de transición de estados: Q x (Símb. Alf.) ==> Q";
  out << "\n   que determina el único estado siguiente para el";
  out << "\n   par (Qi, simb.) correspondiente al estado actual y la entrada:";
  TransFunc show_trans_func(dfa_dna.GetTransFunc());
  out << '\n' << show_trans_func << '\n';

  return out;
}

Alphabet DfaDna::GetAlphabet() {
  return alphabet_;
}

SetStatus DfaDna::GetAllStatus() {
  return all_status_;
}

size_t DfaDna::GetInitialState() {
  return initial_state_;
}

SetStatus DfaDna::GetAceptationStatus() {
  return aceptation_status_;
}

TransFunc DfaDna::GetTransFunc() {
  return trans_func_;
}
