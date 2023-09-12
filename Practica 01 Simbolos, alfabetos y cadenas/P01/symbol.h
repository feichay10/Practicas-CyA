/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file symbol.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <string>

class Symbol {
 public:
  Symbol();
  Symbol(std::string entry_symbol);
  Symbol(const Symbol& entry_symbol);
  Symbol(char entry_symbol);
  
  void set_symbol(char entry_symbol);
  char get_symbol();

  bool operator==(const Symbol& entry_symbol) const;
  bool operator!=(const Symbol& entry_symbol) const;
  friend std::ostream& operator<<(std::ostream& os, const Symbol& entry_symbol);

 private:
  char symbol_;
};

#endif  // SYMBOL_H_