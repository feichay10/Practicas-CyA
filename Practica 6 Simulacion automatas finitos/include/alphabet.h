/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "symbol.h"

class Alphabet {
 public:
  Alphabet();
  Alphabet(std::string);
  Alphabet(std::vector<std::string>);

  void SetSymbol(Symbol);
  void SetAlphabet(Symbol);

 private:
  std::vector<std::string> list_;
  std::vector<Symbol> alphabet_;
};
