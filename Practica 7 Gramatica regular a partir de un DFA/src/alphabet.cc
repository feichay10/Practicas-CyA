/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file alphabet.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/alphabet.h"

Alphabet::Alphabet() {

}

void Alphabet::setSymbol(Symbol symbols) {
  bool flag = true;
  
  for (unsigned i = 0; i < alphabet_.size(); i++) {
    if (alphabet_.at(i).getSymbol() == symbols.getSymbol()) {
      flag = false;
    }
  }
  if (flag == true) {
    alphabet_.emplace_back(symbols);
  }
}

std::string Alphabet::getSymbol(int pos) {
  return alphabet_.at(pos).getSymbol();
}

unsigned Alphabet::getAlphabetSize() {
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
        if (strings[i] == auxiliary.getSymbol()[i]) {
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