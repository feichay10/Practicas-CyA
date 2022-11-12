/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"

class Alphabet {
 public:
  Alphabet();
  Alphabet(std::string);
  Alphabet(std::vector<std::string>);

  void setWord(std::string);
  void setSymbol(Symbol);
  void setAlphabet(Symbol);

  Symbol getWord(int);
  std::string getSymbol(int);
  std::vector<Symbol> getAlphabet();
  unsigned getListSize();
  unsigned getAlphabetSize();

  bool AlphabetComprobation(std::string);

 private:
  std::vector<std::string> list_;
  std::vector<Symbol> alphabet_;
};