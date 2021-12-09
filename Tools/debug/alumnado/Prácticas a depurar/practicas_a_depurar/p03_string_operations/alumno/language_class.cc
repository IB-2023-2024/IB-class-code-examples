// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 17/10/2021
//
// Archivo language_class.cc: Donde se desarrollan las funciones de la clase
//         lenguaje contenida en el archivo de cabecera language_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 17/10/2021 - Creacion (primera version) del codigo

#include "language_class.h"

Language::Language(void): word_user_(), alphabet_user_() {}

Language::Language(std::istringstream& actual_line) {

    std::string chain{""}; //String entera que guarda las cadenas de la linea
    //String que se le pasara al constructor de la clase Language
    Symbol aux_symbol;
    int alphabet_size{-1};
    //Conjunto que se le pasara al constructor de la clase Language
    //aunque sea un vector, es nuestro alfabeto
    std::vector<Symbol> aux_alphabet; 


    //Leemos la linea, si solo tiene una cadena, el alfabeto esta vacio y hay
    //que generarlo a partir de la cadena que hay, si hay mas de una cadena
    //en la linea, se van metiendo menos la ultima leida
    while(getline(actual_line, chain, ' ')) {
      ++alphabet_size;
      if(alphabet_size > 0) {
        aux_alphabet.emplace_back(aux_symbol);
      }
      aux_symbol.SetSymbol(chain);
    }

    //Variable que será pasado a nuestro objeto word_user_
    std::vector<Symbol> aux_word;

    //Ahora recorremos chain para reconocer donde están los simbolos
    size_t base_position{0}; //variable que usamos para indicar el inicio
    size_t lenght{1};

    if(alphabet_size == 0) {
      for(int i{0}; i < int(chain.size()); ++i) {
        std::string aux{""};
        aux += chain.at(i);
        aux_alphabet.emplace_back(aux);
        aux_word.emplace_back(aux);
      }
    }else {
      for(size_t i{0}; i < chain.size(); ++i) {
        for(size_t j{0}; j < aux_alphabet.size(); ++j) {
          if(aux_alphabet.at(j).GetSymbol() == 
             chain.substr(base_position, lenght)) {
            aux_word.emplace_back(chain.substr(base_position, lenght));
            base_position = i + 1;
            lenght = 0;
          }
        }
        ++lenght;
      }
    }
    
    //Atributos internos ya inicializados
    alphabet_user_.SetterAlphabet(aux_alphabet);
    word_user_.SetWord(aux_word);
}

Language::Language(Language& language) {
  *this = language;
}

void Language::SetWordToLanguage(Word& word) {
  word_user_ = word;
}

void Language::SetAlphabetToLanguage(Alphabet& alphabet) {
  alphabet_user_ = alphabet;
}

Word Language::GetWordOfLanguage(void) {
  return word_user_;
}

Alphabet Language::GetAlphabetOfLanguage(void) {
  return alphabet_user_;
}

const size_t Language::Opcode1Size() {
  return word_user_.SizeWord();
}

Word Language::Opcode2Inverse() {

  std::vector<Symbol> aux_vec_symbol;

  for(int i{int(word_user_.GetWord().size() - 1)}; i >= 0; --i) {
    aux_vec_symbol.emplace_back(word_user_.GetWord().at(i));
  }
  
  Word aux_word(aux_vec_symbol);

  return aux_word;
}

std::string Language::Opcode3Prefix() {
  std::string result{"{&, "};
  int aux{0};

  for(int i{0}; i < int(word_user_.SizeWord()); ++i) {
    while(aux <= i) {
      result += word_user_.GetWord().at(aux).GetSymbol();
      ++aux;
      
    }
    result += ", ";
    
    aux = 0;
    
  }

  result.pop_back();
  result.pop_back();
  result += "}";
  
  return result;
}

std::string Language::Opcode4Postfix() {
  std::string result{"{&, "};
  int lenght{0};

  for(int i{int(word_user_.SizeWord() - 1)}; i >= 0; --i) {
    while(i + lenght <= int(word_user_.SizeWord() - 1)) {
      result += word_user_.GetWord().at(i + lenght).GetSymbol();
      ++lenght;

    }

    result += ", ";
    lenght = 0;
  }

  result.pop_back();
  result.pop_back();
  result += "}";

  return result;
}

std::string Language::Opcode5Substr() {
  std::string result{"{&, "};
  int lenght{1};

  while(lenght <= int(word_user_.SizeWord())) {
    for(int i{0}; i < int(word_user_.SizeWord() - lenght + 1); ++i) {
      for(int j{i}; j < (lenght + i); ++j) {
        result += word_user_.GetWord().at(j).GetSymbol();
      }
      result += ", ";
    }
    ++lenght;
  }

  result.pop_back();
  result.pop_back();
  result += "}";

  return result;
}

std::string Language::Opcode6ChainCmp(std::vector<Symbol> user_word) {
  std::string result{""};
  bool substr{false};
  int base_position{0};
  std::vector<Symbol> aux_word(word_user_.GetWord());

  result += word_user_.ShowWord() + " ";

  if(!(user_word > aux_word)) {
    for(int i{0}; i < int(aux_word.size()); ++i) {
      for(int j{0}; j < int(user_word.size()); ++j) {
        if(aux_word.at(i + base_position) == user_word.at(j)) {
          if(user_word.at(j) == user_word.back()) {
            substr = true;
          
          }

          if(i + base_position < int(aux_word.size() - 1)) {
            ++base_position;

          }else {
            break;
          }
        

        }else {
          base_position = 0;
          break;
        }
      }

      if(substr) {
        break;
      }
    }

    if(substr) {
      if(aux_word.size() == user_word.size()) {
        result += "== ";
      }

      if(aux_word.size() > user_word.size()) {
        result += "> ";
      }
    }else {
      result += "!= ";
    }

  }else {
    result += "!= ";
  }
  

  Word temp_word(user_word);
  result += temp_word.ShowWord();

  return result;
}

Word Language::Opcode7ChainConcatenation(std::vector<Symbol> user_word) {

  std::vector<Symbol> temp_word(word_user_.GetWord());

  for(int i{0}; i < int(user_word.size()); ++i) {
    temp_word.emplace_back(user_word.at(i));
    alphabet_user_.SetterSymbol(user_word.at(i));
  }

  word_user_.SetWord(temp_word);

  return word_user_;
}

Word Language::Opcode8Power(int& power) {
  Word result;

  if(power == 0) {
    Symbol temp_symbol{"&"};
    std::vector<Symbol> temp_word;
    temp_word.emplace_back(temp_symbol);
    result.SetWord(temp_word);
  }else {
    std::vector<Symbol> temp_word;
    
    for(int i{1}; i <= power; ++i) {
      for(int j{0}; j < int(word_user_.SizeWord()); ++j) {
        temp_word.emplace_back(word_user_.GetWord().at(j));
      }
    }

    result.SetWord(temp_word);
  }

  return result;
}
 
std::string Language::Opcode9NewPower(int& power) {
  std::vector<Word> set_words(word_user_.Power(power));
  std::string result{"L = {&, "};

  for(int i{0}; i < int(set_words.size()); ++i) {
    std::vector<Symbol> aux_word(set_words.at(i).GetWord());
    for(int j{0}; j < int(aux_word.size()); ++j) {
      result += aux_word.at(j).GetSymbol();
    }

    result += ", ";
  }

  result.pop_back();
  result.pop_back();
  result += "}";

  return result;
}

void Language::operator=(Language& language) {
  language.SetWordToLanguage(word_user_);
  language.SetAlphabetToLanguage(alphabet_user_);
}

