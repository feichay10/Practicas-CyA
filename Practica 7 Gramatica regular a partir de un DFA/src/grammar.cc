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
#include "../include/automata.h"
#include "../include/state.h"
#include "../include/transition.h"

Grammar::Grammar() {

} 

Grammar::Grammar(Automata &dfa){
  std::vector<State> states = dfa.getStates();

  num_terminal_symbols_ = dfa.getNum_alphabet_symbols();
  for(unsigned i = 0; i < dfa.getNum_alphabet_symbols(); i++) {
    terminal_symbols_.push_back(dfa.getAlphabet_symbols(i));
  }
  num_non_terminal_symbols_ = dfa.getNum_states();
  for(unsigned i = 0; i < states.size(); i++) {
    non_terminal_symbols_.push_back(states[i].getName());
  }
  start_symbol_ = dfa.getStates()[0].getName();
  num_productions_ = dfa.getNum_states();
  for(unsigned i = 0; i < states.size(); i++) {
    std::string production = states[i].getName() + " -> ";
    
    // std::cout << "production: " << production << std::endl;
    productions_.push_back(production);
  }
}

void Grammar::setNum_terminal_symbols(int num_terminal_symbols) {
  num_terminal_symbols_ = num_terminal_symbols;
}

void Grammar::setNum_non_terminal_symbols(int num_non_terminal_symbols) {
  num_non_terminal_symbols_ = num_non_terminal_symbols;
}


void Grammar::setStart_symbol(std::string start_symbol) {
  start_symbol_ = start_symbol;
}

int Grammar::getNum_terminal_symbols() {
  return num_terminal_symbols_;
}

int Grammar::getNum_non_terminal_symbols() {
  return num_non_terminal_symbols_;
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
  std::cout << "Grammar:" << std::endl;
  std::cout << "Number of terminal symbols: " << num_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < terminal_symbols_.size(); i++){
    std::cout << "Terminal symbol: " << terminal_symbols_[i] << std::endl;
  }
  std::cout << "Number of non-terminal symbols: " << num_non_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < non_terminal_symbols_.size(); i++){
    std::cout << "Non-terminal symbol: " << non_terminal_symbols_[i] << std::endl;
  }
  std::cout << "Start Non-terminal-symbol: " << start_symbol_ << std::endl;
  std::cout << "Number of productions: " << num_productions_ << std::endl;
  for(unsigned i = 0; i < productions_.size(); i++) {
    std::cout << "Production: " << productions_[i] << std::endl;
  }
}

void Grammar::PrintToFile(std::ofstream &output_file) {
  output_file << num_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < terminal_symbols_.size(); i++){
    output_file << terminal_symbols_[i] << std::endl;
  }
  output_file << num_non_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < non_terminal_symbols_.size(); i++){
    output_file << non_terminal_symbols_[i] << std::endl;
  }
  output_file << start_symbol_ << std::endl;
  output_file << num_productions_ << std::endl;
}
