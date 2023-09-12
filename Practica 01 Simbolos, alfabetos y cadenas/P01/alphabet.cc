/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file alphabet.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "alphabet.h"

Alphabet::Alphabet() {
  alphabet_.clear();
}

void Alphabet::set_alphabet(Symbol entry_alphabet) {
  alphabet_.push_back(entry_alphabet);
}

std::vector<Symbol> Alphabet::get_alphabet() {
  return alphabet_;
}

void Alphabet::insert_symbol(Symbol entry_symbol) {
  alphabet_.push_back(entry_symbol);
}

bool Alphabet::find_symbol(Symbol& entry_symbol) {
  for (unsigned int i = 0; i < alphabet_.size(); i++) {
    if (alphabet_[i] == entry_symbol) {
      return true;
    }
  }
  return false;
}

// void Alphabet::find(const Symbol& entry_symbol) const {
//   for (unsigned int i = 0; i < alphabet_.size(); i++) {
//     if (alphabet_[i] == entry_symbol) {
//       std::cout << "The symbol " << entry_symbol << " is in the alphabet." << std::endl;
//       return;
//     }
//   }
//   std::cout << "The symbol " << entry_symbol << " is not in the alphabet." << std::endl;
// }

std::ostream& operator<<(std::ostream& os, std::vector<Symbol> entry_alphabet) {
  for (unsigned int i = 0; i < entry_alphabet.size(); i++) {
    os << entry_alphabet[i] << " ";
  }
  return os;
}