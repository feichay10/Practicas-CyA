#include "chain.h"

Chain::Chain() {}

Chain::Chain(std::string entry_chain) {
  for (unsigned int i = 0; i < entry_chain.size(); i++) {
    Symbol symbol(entry_chain[i]);
    chain_.push_back(symbol);
  }
}

void Chain::set_alphabet(Alphabet& entry_alphabet) {
  alphabet_ = entry_alphabet;
}

void Chain::set_chain(std::string entry_chain) {
  for (unsigned int i = 0; i < entry_chain.size(); i++) {
    Symbol symbol(entry_chain[i]);
    chain_.push_back(symbol);
  }
}

Alphabet Chain::get_alphabet() {
  return alphabet_;
}

std::string Chain::get_chain() {
  std::string chain;
  for (unsigned int i = 0; i < chain_.size(); i++) {
    chain += chain_[i].get_symbol();
  }
  return chain;
}

void Chain::insert_symbol(Symbol& entry_symbol) {
  chain_.push_back(entry_symbol);
}

int Chain::length() {
  // std::cout << "Longitud de la cadena: " << chain_.size() << std::endl;
  return chain_.size();
}

std::ostream& operator<<(std::ostream& os, const Chain& entry_chain) {
  for (unsigned int i = 0; i < entry_chain.chain_.size(); i++) {
    os << entry_chain.chain_[i];
  }
  return os;
}