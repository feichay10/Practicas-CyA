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

#include "alphabet.h"

Alphabet::Alphabet(std::string word) {
  list_.push_back(word);
}

Alphabet::Alphabet(std::vector<std::string> list) {
  list_ = list;
}

void Alphabet::SetSymbol(Symbol symbol) {
  bool flag = true;
  for (unsigned i = 0; i < alphabet_.size(); i++) {
    if (alphabet_.at(i).GetSymbol() == symbol.GetSymbol()) {
      flag = false;
    }
  }
  if (flag == true) {
    alphabet_.push_back(symbol);
  }
}