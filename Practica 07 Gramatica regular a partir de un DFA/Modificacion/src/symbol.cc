/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file symbol.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los diferentes metodos de la clase 'Symbol'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/symbol.h"

/**
 * @brief Constructor por defecto
 *
 */
Symbol::Symbol() {}

/**
 * @brief Constructor de la clase 'Symbol', que inicializa un simbolo
 * 
 * @param symbol 
 */
Symbol::Symbol(std::string symbol) { 
  setSymbol(symbol); 
}

/**
 * @brief Setter de la variable 'symbol_'
 * 
 * @param symbol 
 */
void Symbol::setSymbol(std::string symbol) { 
  symbol_ = symbol; 
}

/**
 * @brief Getter de la variable 'symbol_'
 * 
 * @return std::string 
 */
std::string Symbol::getSymbol() { 
  return symbol_; 
}

/**
 * @brief Getter del tamaño de la variable 'symbol_'
 * 
 * @return unsigned 
 */
unsigned Symbol::getSize() { 
  return symbol_.size(); 
}