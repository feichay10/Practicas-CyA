/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
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

void Alphabet::set_alphabet(Symbol entry_alphabet) {
  alphabet_.push_back(entry_alphabet);
}

std::vector<Symbol> Alphabet::get_alphabet() { return alphabet_; }

bool Alphabet::check_chain_belong_alphabet(std::pair<Chain, Alphabet> input) {
  Chain chain = input.first;
  Alphabet alphabet = input.second;

  // unique symbols of the alphabet
  // std::vector<char> unique_alphabet_symbols;
  // for (unsigned int i = 0; i < alphabet.get_alphabet().size(); i++) {
  //   if (std::find(unique_alphabet_symbols.begin(), unique_alphabet_symbols.end(), alphabet.get_alphabet()[i].get_symbol()) == unique_alphabet_symbols.end()) {
  //     if (alphabet.get_alphabet()[i].get_symbol() == ' ') {
  //       continue;
  //     } else {
  //       unique_alphabet_symbols.push_back(alphabet.get_alphabet()[i].get_symbol());
  //     }
  //   }
  // }
  // std::sort(unique_alphabet_symbols.begin(), unique_alphabet_symbols.end());

  // // unique symbols of the chain
  // std::vector<char> unique_chain_symbols;
  // for (unsigned int i = 0; i < chain.get_chain().size(); i++) {
  //   if (std::find(unique_chain_symbols.begin(), unique_chain_symbols.end(), chain.get_chain()[i]) == unique_chain_symbols.end()) {
  //     unique_chain_symbols.push_back(chain.get_chain()[i]);
  //   }
  // }
  // std::sort(unique_chain_symbols.begin(), unique_chain_symbols.end());

  // // check if all the symbols of the chain are in the alphabet
  // bool found = true;
  // for (unsigned int i = 0; i < unique_chain_symbols.size(); i++) {
  //   for (unsigned int j = 0; j < unique_alphabet_symbols.size(); j++) {
  //     if (unique_chain_symbols[i] == ' ' || unique_alphabet_symbols[j] == ' ') {
  //       continue;
  //     } 
  //     if (unique_chain_symbols[i] == unique_alphabet_symbols[j]) {
  //       found = true;
  //       i++;
  //     } else {
  //       found = false;
  //     }
  //   }
  // }

  // return found;

  return true;
}

