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

void Transition::SetSymbol(const std::string symbol) {
  symbol_ = symbol;
}

void Transition::SetStateTo(const std::string state_to) {
  state_to_ = "q" + state_to;
  pos_ = stoi(state_to);
}

void Transition::SetPos(int pos) {
  pos_ = pos;
}

std::string Transition::GetSymbol() const {
  return symbol_;
}

std::string Transition::GetStateTo() const {
  return state_to_;
}

int Transition::GetPos() const {
  return pos_;
}