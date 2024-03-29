/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file alphabet.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/alphabet.h"

Alphabet::Alphabet() {

}

Alphabet::Alphabet(std::string word) {
  list_.push_back(word);
}

Alphabet::Alphabet(std::vector<std::string> list) {
  list_ = list;
}

void Alphabet::SetWord(std::string word) {
  list_.push_back(word);
}

void Alphabet::SetSymbol(Symbol symbols) {
  bool flag = true;
  
  for (unsigned i = 0; i < alphabet_.size(); i++) {
    if (alphabet_.at(i).GetSymbol() == symbols.GetSymbol()) {
      flag = false;
    }
  }
  if (flag == true) {
    alphabet_.push_back(symbols);
  }
}

std::string Alphabet::GetSymbol(int pos) {
  return list_.at(pos);
}

std::vector<Symbol> Alphabet::GetAlphabet() {
  return alphabet_;
}

Symbol Alphabet::GetWord(int pos) {
  return alphabet_.at(pos);
}

unsigned Alphabet::GetListSize() {
  return list_.size();
}

unsigned Alphabet::GetAlphabetSize() {
  return alphabet_.size();
}

bool Alphabet::AlphabetComprobation(std::string strings) {
  if (strings == "&") {
    return true;
  } else {
    size_t count = 0;
    for (size_t i = 0; i < strings.size(); i++) {
      for (size_t j = 0; j < alphabet_.size(); j++) {
        Symbol auxiliary = alphabet_[j];
        if (strings[i] == auxiliary.GetSymbol()[i]) {
          count++;
        }
      }
    }
    if (count == strings.size()) {
      return true;
    } else {
      return false;
    }
  }
}