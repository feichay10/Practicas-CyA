/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file dfa.h
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-08
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

class Dfa {
 public:
  Dfa(std::ifstream &);

  bool Read(std::string);
  bool IsAlphabet(std::string);

 private:
  int states_size_;
  int first_state_;
  std::vector<State> states_;
  Alphabet alphabet_;
};