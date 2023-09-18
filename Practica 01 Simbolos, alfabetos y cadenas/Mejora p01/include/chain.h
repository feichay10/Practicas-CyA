/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file chain.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#ifndef CHAIN_H_
#define CHAIN_H_

#include <string>
#include <vector>
#include <iostream>

#include "alphabet.h"
#include "symbol.h"

class Alphabet;

class Chain {
 public:
  // Constructors
  Chain();
  Chain(std::string entry_chain);
  Chain(std::vector<Symbol> entry_chain);

  // Getters and Setters
  void set_chain(std::string entry_chain);
  std::vector<Symbol> get_chain();
  
  // Methods of the chain
  void insert_symbol(Symbol& entry_symbol);
  Alphabet get_alphabet();

  // Operations of the chain
  int length();
  Chain reverse();
  std::vector<Chain> prefixes();
  std::vector<Chain> suffixes();
  std::vector<Chain> substrings();

  // Overload Operators
  friend std::ostream& operator<<(std::ostream& os, Chain entry_chain);

 private:
  std::vector<Symbol> chain_;
};

#endif  // CHAIN_H_