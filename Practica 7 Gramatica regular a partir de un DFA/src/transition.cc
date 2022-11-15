/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file transition.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los diferentes metodos de la clase 'Transition'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/transition.h"

/**
 * @brief Constructor por defecto
 * 
 */
Transition::Transition() {}

/**
 * @brief Constructor de clase 'Transition', inicializa los simbolos y los estados
 * 
 * @param symbol 
 * @param state_to 
 */
Transition::Transition(std::string symbol, std::string state_to) {
  symbol_ = symbol;
  state_to_ = state_to;
}

/**
 * @brief Setter de la variable 'symbol_'
 * 
 * @param symbol 
 */
void Transition::setSymbol(const std::string symbol) {
  symbol_ = symbol;
}

/**
 * @brief Setter de la variable 'state_to_'
 * 
 * @param state_to 
 */
void Transition::setStateTo(const std::string state_to) {
  state_to_ = "q" + state_to;
  pos_ = stoi(state_to);
}

/**
 * @brief Setter de la variable 'pos_'
 * 
 * @param pos 
 */
void Transition::setPos(std::string pos) {
  pos_ = pos;
}

/**
 * @brief Getter de la variable 'symbol_'
 * 
 * @return std::string 
 */
std::string Transition::getSymbol() const {
  return symbol_;
}

/**
 * @brief Getter de la variable 'state_to_'
 * 
 * @return std::string 
 */
std::string Transition::getStateTo() const {
  return state_to_;
}

/**
 * @brief Getter de la variable 'pos_'
 * 
 * @return std::string 
 */
std::string Transition::getPos() const {
  return pos_;
}