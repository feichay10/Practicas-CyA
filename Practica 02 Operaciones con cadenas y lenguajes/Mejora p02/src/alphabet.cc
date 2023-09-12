/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file alphabet.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/alphabet.h"

Alphabet::Alphabet() {}

Alphabet::Alphabet(std::string entry_alphabet) {
  Symbol symbol;
  for (unsigned int i = 0; i < entry_alphabet.length(); i++) {
    symbol.set_symbol(entry_alphabet[i]);
    alphabet_.push_back(symbol);
  }
}

void Alphabet::set_alphabet(Symbol entry_alphabet) {
  alphabet_.push_back(entry_alphabet);
}

std::vector<Symbol> Alphabet::get_alphabet() { return alphabet_; }

int Alphabet::size() { return alphabet_.size(); }