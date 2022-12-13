/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file alphabet.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "alphabet.h"
#include "symbol.h"

void alphabet::set_alphabet(symbol letter) {
  alphabet_.insert(letter);
}

std::set<symbol> alphabet::get_alphabet() const { 
  return alphabet_; 
}
