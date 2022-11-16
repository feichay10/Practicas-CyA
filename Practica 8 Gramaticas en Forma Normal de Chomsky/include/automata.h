/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file automata.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementacion de la clase 'Automata'
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
#include "../include/state.h"

class Grammar;

/**
 * @brief Clase que representa un autómata finito determinista
 *
 */
class Automata {
 public:
  Automata();
  Automata(std::ifstream &);

  std::string getAlphabetSymbols(int);
  int getNumStates();
  std::vector<State> getStates();
  int getNumAlphabetSymbols();
  unsigned getStateSize();

  Grammar ConvertToGrammar();

 private:
  std::string alphabet_symbols_;
  int num_alphabet_symbols_ = 0;
  int num_states_;
  std::string start_state_;
  std::vector<State> states_;
  Alphabet alphabet_;
  State state_;
};