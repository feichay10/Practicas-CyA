/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file alphabet.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <iostream>
#include "symbol.h"
#include <vector>

class Alphabet {
 public:
  Alphabet();

  void set_alphabet(Symbol entry_alphabet);
  std::vector<Symbol> get_alphabet();

  void insert_symbol(Symbol entry_symbol);
  bool find_symbol(Symbol& entry_symbol);
  void find(const Symbol& entry_symbol) const;

  friend std::ostream& operator<<(std::ostream& os, std::vector<Symbol> entry_alphabet);

 private:
  std::vector<Symbol> alphabet_;
};

#endif // ALPHABET_H_