/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file transition.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/transition.h"

Transition::Transition() {}

Transition::Transition(std::string symbol, std::string state_to) {
  symbol_ = symbol;
  state_to_ = state_to;
}

void Transition::setSymbol(const std::string symbol) {
  symbol_ = symbol;
}

void Transition::setStateTo(const std::string state_to) {
  state_to_ = "q" + state_to;
  pos_ = stoi(state_to);
}

void Transition::setPos(std::string pos) {
  pos_ = pos;
}

std::string Transition::getSymbol() const {
  return symbol_;
}

std::string Transition::getStateTo() const {
  return state_to_;
}

std::string Transition::getPos() const {
  return pos_;
}