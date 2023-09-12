/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file chain.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CHAIN_H_
#define CHAIN_H_
#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "alphabet.h"
#include "symbol.h"

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
  Chain reverse();
  void insert_symbol(Symbol& entry_symbol);
  void clear_chain();

  // Overload Operators
  friend std::ostream& operator<<(std::ostream& os, Chain entry_chain);
  friend bool operator==(const Chain& chain_1, const Chain& chain_2);
  friend Chain operator+(const Chain& chain_1, const Chain& chain_2);
  friend bool operator!=(const Chain& chain_1, const Chain& chain_2);
  bool operator<(const Chain& entry_chain) const;

 private:
  std::vector<Symbol> chain_;
  
};

#endif  // CHAIN_H_