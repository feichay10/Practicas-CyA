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
 * @brief Contiene la implementación de la clase 'Alphabet'
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

/**
 * @brief Clase que representa un alfabeto
 * 
 */
class Alphabet {
 public:
  Alphabet();

  void setSymbol(Symbol);
  std::string getSymbol(int);
  unsigned getAlphabetSize();

  bool AlphabetComprobation(std::string);

 private:
  std::vector<Symbol> alphabet_;
};