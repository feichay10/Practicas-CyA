/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ALPHABET_H_
#define ALPHABET_H_
#pragma once

#include <iostream>
#include <vector>
#include <set>

#include "symbol.h"

class Alphabet {
 public:
  // Constructors
  Alphabet();
  Alphabet(std::string entry_alphabet);

  // Getters and Setters
  void set_alphabet(Symbol entry_alphabet);
  std::vector<Symbol> get_alphabet();

  // Methods
  int size();

 private:
  std::vector<Symbol> alphabet_;
};

#endif  // ALPHABET_H_