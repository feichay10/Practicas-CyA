/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file automata.h
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "../include/alphabet.h"
#include "../include/grammar.h"
#include "../include/state.h"

class Automata {
 public:
  Automata(std::ifstream &);

  // void setAlphabet_symbols(std::string);
  // void setNum_states(int);
  // void setNum_start_states(int);
  // void setStates(std::vector<State>);
  // void setAlphabet(Alphabet);
  // std::string getAlphabet_symbols();
  // int getNum_states();
  // int getNum_start_states();
  // std::vector<State> getStates();
  // Alphabet getAlphabet();

  bool Read(std::string);
  Grammar ConvertToGrammar(Grammar);

 private:
  std::string alphabet_symbols_;
  int num_states_;
  std::string start_state_;
  std::vector<State> states_;
  Alphabet alphabet_;
};