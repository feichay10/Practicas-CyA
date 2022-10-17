/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file symbol.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "symbol.h"

symbol::symbol(char symbol) {
  symbol_.clear();
  symbol_.push_back(symbol);
}

bool symbol::operator<(const symbol& symbol) {
  return (symbol_.size() < symbol.getsymbol().size());
}

std::string symbol::getsymbol() const {
  return symbol_;
}

// Este operador es para el insert del set, es para el alphabet
bool operator<(const symbol& symbol1, const symbol& symbol2) {
  return (symbol1.getsymbol() < symbol2.getsymbol());
}

// Comparar dos simbolos para ver si son iguales 
bool operator==(const symbol& symbol1, const symbol& symbol2) {
  return (symbol1.getsymbol()[0] == symbol2.getsymbol()[0]);
}

std::ostream& operator<<(std::ostream& out, const symbol& symbol) {
  out << symbol.getsymbol();
  return out;
}