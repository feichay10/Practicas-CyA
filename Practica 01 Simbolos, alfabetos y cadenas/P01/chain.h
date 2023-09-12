/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file chain.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-07-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef CHAIN_H_
#define CHAIN_H_

#include <string>
#include <vector>

#include "alphabet.h"
#include "symbol.h"

class Chain {
 public:
  Chain();
  Chain(std::string entry_chain);

  void set_alphabet(Alphabet& entry_alphabet);
  void set_chain(std::string entry_chain);
  Alphabet get_alphabet();
  std::string get_chain();
  void insert_symbol(Symbol& entry_symbol);

  // Operations of the chain
  int length();
  Chain reverse();
  std::vector<Chain> prefixes();
  std::vector<Chain> suffixes();
  std::vector<Chain> substrings();

  // Operators
  friend std::ostream& operator<<(std::ostream& os, const Chain& entry_chain);

 private:
  std::vector<Symbol> chain_;
  Alphabet alphabet_;
};

#endif  // CHAIN_H_