/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file symbol.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de la clase 'Symbol'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <string>

/**
 * @brief Clase 'Symbol' que representa un simbolo
 * 
 */
class Symbol {
 public:
  Symbol();
  Symbol(std::string symbol);

  void setSymbol(std::string);
  std::string getSymbol();
  unsigned getSize();

 private:
  std::string symbol_;
};