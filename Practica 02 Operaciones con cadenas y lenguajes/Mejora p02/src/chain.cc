/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
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

Chain Chain::reverse() {
  Chain reverse_chain;

  for (int i = chain_.size() - 1; i >= 0; i--) {
    reverse_chain.insert_symbol(chain_[i]);
  }

  return reverse_chain;
}

void Chain::insert_symbol(Symbol& entry_symbol) {
  chain_.push_back(entry_symbol);
}

void Chain::clear_chain() { chain_.clear(); }

std::ostream& operator<<(std::ostream& os, Chain entry_chain) {
  for (unsigned int i = 0; i < entry_chain.get_chain().size(); i++) {
    os << entry_chain.get_chain()[i].get_symbol();
  }

  return os;
}

bool operator==(const Chain& chain_1, const Chain& chain_2) {
  if (chain_1.chain_.size() != chain_2.chain_.size()) {
    return false;
  } else {
    unsigned long int contador = 0;
    for (unsigned int i = 0; i < chain_1.chain_.size(); i++) {
      if (chain_1.chain_[i] == chain_2.chain_[i]) {
        ++contador;
      }
    }
    if (contador == chain_1.chain_.size()) {
      return true;
    } else {
      return false;
    }
  }
}

// Concatenation of two chains
Chain operator+(const Chain& chain_1, const Chain& chain_2) {
  Chain concatenation_chain;
  std::vector<Symbol> chain_1_vector = chain_1.chain_;
  std::vector<Symbol> chain_2_vector = chain_2.chain_;
  std::string str;

  for (unsigned int i = 0; i < chain_1_vector.size(); i++) {
    str.push_back(chain_1_vector[i].get_symbol());
  }

  for (unsigned int i = 0; i < chain_2_vector.size(); i++) {
    str.push_back(chain_2_vector[i].get_symbol());
  }

  concatenation_chain.set_chain(str);

  return concatenation_chain;
}

bool operator!=(const Chain& chain_1, const Chain& chain_2) {
  if (chain_1.chain_.size() != chain_2.chain_.size()) {
    return true;
  } else {
    unsigned long int contador = 0;
    for (unsigned int i = 0; i < chain_1.chain_.size(); i++) {
      if (chain_1.chain_[i] == chain_2.chain_[i]) {
        ++contador;
      }
    }
    if (contador == chain_1.chain_.size()) {
      return false;
    } else {
      return true;
    }
  }
}

bool Chain::operator<(const Chain& entry_chain) const {
  if (chain_.size() < entry_chain.chain_.size()) {
    return true;
  } else if (chain_.size() > entry_chain.chain_.size()) {
    return false;
  } else {
    for (unsigned int i = 0; i < chain_.size(); i++) {
      if (chain_[i] < entry_chain.chain_[i]) {
        return true;
      } else if (chain_[i] > entry_chain.chain_[i]) {
        return false;
      }
    }
  }
  return false;
}