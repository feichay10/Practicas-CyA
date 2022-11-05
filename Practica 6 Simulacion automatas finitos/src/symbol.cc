/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file symbol.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "symbol.h"

Symbol::Symbol(char symbol) {
  symbol_.clear();
  symbol_.push_back(symbol);
}

void Symbol::SetSymbol(std::string symbol){
  symbol_ = symbol;
}

std::string Symbol::GetSymbol() const {
  return symbol_;
}

unsigned Symbol::GetSize() {
  return symbol_.size();
}