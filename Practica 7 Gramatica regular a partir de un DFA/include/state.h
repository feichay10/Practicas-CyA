/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file state.h
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <string>

#include "../include/alphabet.h"
#include "transition.h"

class State {
 public:
  State();
  State(bool, int);

  void SetAceptation();
  void SetStart();
  void SetName(std::string);
  void SetState(std::string);

  bool IsAceptation();
  bool IsStart();
  std::string GetName();
  Transition GetTransition(std::string);
  Transition at(int);
  std::vector<int> TransitionsPos(std::string);

  void clear();

 private:
  bool start_;
  bool aceptation_;
  std::string name_;
  int transitions_num_;
  std::vector<Transition> transitions_;
};