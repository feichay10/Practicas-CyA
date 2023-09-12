/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <iostream>
#include <vector>
#include <algorithm>

#include "symbol.h"
#include "chain.h"

class Chain;

class Alphabet {
 public:
  // Constructors
  Alphabet();

  // Getters and Setters
  void set_alphabet(Symbol entry_alphabet);
  std::vector<Symbol> get_alphabet();

  // Methods of the class
  bool check_chain_belong_alphabet(std::pair<Chain, Alphabet> input);

 private:
  std::vector<Symbol> alphabet_;
};

#endif  // ALPHABET_H_