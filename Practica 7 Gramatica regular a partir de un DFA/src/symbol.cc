/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file symbol.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/symbol.h"

Symbol::Symbol() {

}

Symbol::Symbol(std::string symbol) {
  SetSymbol(symbol);
}

void Symbol::SetSymbol(std::string symbol){
  symbol_ = symbol;
}

std::string Symbol::GetSymbol(){
  return symbol_;
}

unsigned Symbol::GetSize() {
  return symbol_.size();
}