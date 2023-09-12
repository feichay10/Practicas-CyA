/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file chain.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/chain.h"

const Chain EMPTY_CHAIN("&");

Chain::Chain() {
  chain_.clear();
}

Chain::Chain(std::string entry_chain) { set_chain(entry_chain); }

Chain::Chain(std::vector<Symbol> entry_chain) { chain_ = entry_chain; }

void Chain::set_chain(std::string entry_chain) {
  for (unsigned int i = 0; i < entry_chain.size(); i++) {
    Symbol symbol(entry_chain[i]);
    chain_.push_back(symbol.get_symbol());
  }
}

std::vector<Symbol> Chain::get_chain() {
  return chain_;
}

void Chain::insert_symbol(Symbol& entry_symbol) {
  chain_.push_back(entry_symbol);
}

Alphabet Chain::get_alphabet() {
  Alphabet alphabet;

}

int Chain::length() { return chain_.size(); }

Chain Chain::reverse() {
  Chain reverse_chain;

  for (int i = chain_.size() - 1; i >= 0; i--) {
    reverse_chain.insert_symbol(chain_[i]);
  }

  return reverse_chain;
}

std::vector<Chain> Chain::prefixes() {
  std::vector<Chain> prefixes;
  Chain prefix;

  prefixes.push_back(EMPTY_CHAIN);
  for (unsigned int i = 0; i < chain_.size(); i++) {
    prefix.insert_symbol(chain_[i]);
    prefixes.push_back(prefix);
  }

  return prefixes;
}

std::vector<Chain> Chain::suffixes() {
  std::vector<Chain> suffixes;
  Chain suffix;

  suffixes.push_back(EMPTY_CHAIN);
  for (int i = chain_.size() - 1; i >= 0; i--) {
    suffix.insert_symbol(chain_[i]);
    suffixes.push_back(suffix);
  }

  return suffixes;
}

std::vector<Chain> Chain::substrings() {
  std::vector<Chain> substrings;

  for (unsigned int i = 0; i < chain_.size(); i++) {
    for (unsigned int j = 1; j <= chain_.size() - i; j++) {
      Chain substring;
      for (unsigned int k = i; k < i + j; k++) {
        substring.insert_symbol(chain_[k]);
      }
      substrings.push_back(substring);
    }
  }

  return substrings;
}

std::ostream& operator<<(std::ostream& os, Chain entry_chain) {
  for (unsigned int i = 0; i < entry_chain.get_chain().size(); i++) {
    os << entry_chain.get_chain()[i].get_symbol();
  }

  return os;
}