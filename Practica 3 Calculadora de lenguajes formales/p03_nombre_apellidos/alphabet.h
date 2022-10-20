/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <set>
#include <string>

#include "symbol.h"

class alphabet {
 public:
  alphabet() = default;

  void set_alphabet(symbol letter);
  std::set<symbol> get_alphabet() const;

 private:
  std::set<symbol> alphabet_;
};
