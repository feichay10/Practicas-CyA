/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file symbol.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/symbol.h"

Symbol::Symbol() {}

Symbol::Symbol(std::string entry_symbol) { symbol_ = entry_symbol[0]; }

Symbol::Symbol(const Symbol& entry_symbol) { symbol_ = entry_symbol.symbol_; }

Symbol::Symbol(char entry_symbol) { symbol_ = entry_symbol; }

void Symbol::set_symbol(char entry_symbol) { symbol_ = entry_symbol; }

char Symbol::get_symbol() { return symbol_; }

bool Symbol::operator==(const Symbol& entry_symbol) const {
  return symbol_ == entry_symbol.symbol_;
}

std::ostream& operator<<(std::ostream& os, const Symbol& entry_symbol) {
  os << entry_symbol.symbol_;
  return os;
}

bool Symbol::operator<(const Symbol& entry_symbol) const {
  return symbol_ < entry_symbol.symbol_;
}

bool Symbol::operator>(const Symbol& entry_symbol) const {
  return symbol_ > entry_symbol.symbol_;
}