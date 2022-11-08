/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file nfa.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "../include/alphabet.h"
#include "../include/state.h"

class Nfa{
 public:
  Nfa(std::ifstream&);

  bool IsBranchAccepted(int , State, std::string);
  bool Read(std::string);

 private:
  std::string alphabet_symbols_;
  int num_states_;
  int start_state_;
  std::vector<State> states_;
  Alphabet alphabet_;
};