/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramática en Forma Normal de Chomsky
 * @file grammar.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementacion de la clase 'Grammar'
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <sstream>

class Automata;
/**
 * @brief Clase que representa una gramática regular
 * 
 */
class Grammar {
 public:
  Grammar();
  Grammar(std::ifstream &);

  void ChomskyAlgorithm();
  void PrintOnScreen();
  void PrintToFile(std::ofstream &);
  
 private:
  int num_terminal_symbols_;
  int num_non_terminal_symbols_;
  std::vector<std::string> terminal_symbols_;  
  std::vector<std::string> non_terminal_symbols_;
  std::string start_symbol_;
  int num_productions_;
  std::vector<std::pair<std::string, std::string>> productions_;
};