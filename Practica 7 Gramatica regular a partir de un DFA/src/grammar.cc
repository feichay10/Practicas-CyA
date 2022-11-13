/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file grammar.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/grammar.h"

Grammar::Grammar() {

} 

void Grammar::setNum_terminal_symbols(int num_terminal_symbols) {
  num_terminal_symbols_ = num_terminal_symbols;
}

void Grammar::setTerminal_symbols(std::string terminal_symbols) {
  terminal_symbols_ = terminal_symbols;
}

void Grammar::setNon_terminal_symbols(std::string non_terminal_symbols) {
  non_terminal_symbols_ = non_terminal_symbols;
}

void Grammar::setStart_symbol(std::string start_symbol) {
  start_symbol_ = start_symbol;
}

int Grammar::getNum_terminal_symbols() {
  return num_terminal_symbols_;
}

std::string Grammar::getTerminal_symbols() {
  return terminal_symbols_;
}

std::string Grammar::getNon_terminal_symbols() {
  return non_terminal_symbols_;
}

std::string Grammar::getStart_symbol() {
  return start_symbol_;
}

std::string Grammar::GetNonTerminalSymbol(std::string symbol) {
  int n = stoi(symbol);
  std::string no_terminal_symbols = "SABCDEFGHIJKLMNOPQRSTUVWXYZ";

  return no_terminal_symbols.substr(n, 1);
}

void Grammar::PrintOnScreen() {

}

void Grammar::PrintToFile(std::ofstream &output_file) {

}
