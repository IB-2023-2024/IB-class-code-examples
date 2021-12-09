// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 17/10/2021
// Archivo word_class.cc: Donde se desarrollan las funciones de la clase
//         cadena contenida en el archivo de cabecera word_class.h
//
// Referencias:
//         Enlaces de interes
//
// Historial de revisiones
// 17/10/2021 - Creacion (primera version) del codigo

#include "word_class.h"

//Constructor por defecto
Word::Word(void) = default;

//Constructor normal
Word::Word(std::vector<Symbol>& word) {
  word_ = word;
}

//Constructor de copia
Word::Word(Word& word) {
  word_ = word.GetWord();
}

void Word::SetWord(std::vector<Symbol>& word) {
  word_.clear(); //Vaciamos el atributo interno por si acaso
  for(int i{0}; i < int(word.size()); ++i) {
    word_.emplace_back(word.at(i));
  }
}

void Word::SetWord(Word& word) {
  std::vector<Symbol> aux_word = word.GetWord();
  this->SetWord(aux_word);
}

std::vector<Symbol> Word::GetWord(void) {
  return word_;
}

Symbol Word::GetSymbol(int& position) {
  if((position >= int(word_.size())) || (position < 0)) {
    Symbol temp;
    return temp;
  }
  return word_.at(position);
}

std::string Word::ShowWord(void) {
  std::string aux{""};
  for(size_t i{0}; i < word_.size(); ++i) {
    aux += word_[i].GetSymbol();
  }
  return aux;
}

void Word::EmplaceBackOfWord(std::string& symbol) {
  Symbol aux_symbol(symbol);
  word_.emplace_back(aux_symbol);
}

void Word::EmplaceBackOfWord(Symbol& symbol) {
  word_.emplace_back(symbol);
}

void Word::ClearWord(void) {
  word_.clear();
}

size_t Word::SizeWord(void) {
  return word_.size();
}

std::vector<Word> Word::Power(int& power) {
  std::vector<Word> aux_set_words;

  Symbol avoid_symbol("&");
  std::vector<Symbol> aux_vec_symbol;
  aux_vec_symbol.emplace_back(avoid_symbol);

  Word aux_word(aux_vec_symbol);

  for(int i{0}; i < power; ++i) {
    std::vector<Symbol> aux_vec_symbol2(aux_word.GetWord());
    std::vector<Symbol> aux_vec_symbol3(this->GetWord());

    for(int j{0}; j < int(aux_vec_symbol3.size()); ++j) {
      aux_vec_symbol2.emplace_back(aux_vec_symbol3.at(j));
    }

    aux_word.SetWord(aux_vec_symbol3);

    aux_set_words.at(i) = aux_word;
    
  }
  
  return aux_set_words;
}

void Word::operator=(Word& word) {
  word.SetWord(word_);
}

bool Word::operator==(Word& word) {
  return word.GetWord() == word_;
}

Word Word::operator+(Word& word) {
  for(auto actual_symbol: word_) {
    word.EmplaceBackOfWord(actual_symbol);
  }
  return word;
}

std::ostream& operator<<(std::ostream& output, Word& word) {
  for(size_t i{0}; i < word.word_.size(); ++i) {
    output << word.word_.at(i);
  }
  return output;
}

std::istream& operator>>(std::istream& input, Word& word) {
  Symbol symbol;
  size_t aux_size{0};

  word.ClearWord();
  std::cout << "\n¿Cuántos símbolos va a tener su cadena? ";
  std::cin >> aux_size;
  for(size_t i{0}; i < aux_size; ++i) {
    if(i == 0) {
      std::cout << "\nIntroduzca el primer simbolo: ";
    }else {
      std::cout << "\nIntroduzca el siguiente simbolo: ";
    }
    std::cin >> symbol;
    word.EmplaceBackOfWord(symbol);
  }

  std::cout << "\nLectura terminada\n";

  return input;
}

