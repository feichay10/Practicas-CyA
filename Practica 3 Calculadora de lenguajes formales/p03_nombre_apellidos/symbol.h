/**
*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file symbol.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <string>

class symbol {
 public:
  symbol() = default;
  symbol(char symbol);
  bool operator<(const symbol& symbol);
  std::string getsymbol() const;

 private:
  std::string symbol_;
};

bool operator<(const symbol& symbol1, const symbol& symbol2);
bool operator==(const symbol& symbol1, const symbol& symbol2);
std::ostream& operator<<(std::ostream& out, const symbol& symbol);