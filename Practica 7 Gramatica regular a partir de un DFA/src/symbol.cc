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
  setSymbol(symbol);
}

void Symbol::setSymbol(std::string symbol){
  symbol_ = symbol;
}

std::string Symbol::getSymbol(){
  return symbol_;
}

unsigned Symbol::getSize() {
  return symbol_.size();
}