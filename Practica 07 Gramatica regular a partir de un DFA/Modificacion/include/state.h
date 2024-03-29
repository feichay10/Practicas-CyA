/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file state.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de la clase 'State'
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
#include "../include/grammar.h"
#include "transition.h"

/**
 * @brief Clase 'State' que representa un estado de la máquina de estados finitos
 * 
 */
class State {
 public:
  State();
  State(bool, int);

  void setAceptation();
  void setStart();
  void setName(std::string);
  void setState(std::string);

  std::string getName();
  Transition getTransition(std::string);
  std::vector<Transition> getTransitions();
  std::string getStates(int);
  unsigned getStatesSize();

  bool IsAceptation();
  bool IsStart();
  Transition at(int);
  std::vector<int> TransitionsPos(std::string);

  void clear();

 private:
  bool start_;
  bool aceptation_;
  std::string name_;
  int transitions_num_;
  std::vector<Transition> transitions_;
  std::vector<std::string> states_;
};