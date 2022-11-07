/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file automata.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/automata.h"

Automata::Automata(std::ifstream& automata_file) {
  State actual;
  int count = 0;
  std::string line, name, aux;

  while(getline(automata_file, line)){
    if(count == 0){
      for (size_t i = 0; i < line.size() - 1; i++) {
        if(line[i] != ' '){
          alphabet_symbols_ += line[i];
          std::cout << "Simbolo del alfabeto: " << alphabet_symbols_ << std::endl;
          alphabet_.SetSymbol(alphabet_symbols_);
          alphabet_symbols_.clear();
        }
      }
    } 
    else if(count == 1){
      num_states_ = std::stoi(line);
      std::cout << "Numero de estados: " << num_states_ << std::endl;
    } else if(count == 2){
      start_state_ = std::stoi(line);
      std::cout << "Estado inicial: " << start_state_ << std::endl;
    } 
    else if(count != 0){
      actual.SetState(line);
      states_.push_back(actual);
      actual.clear();
    }
    count++;
  }
}

bool Automata::IsAlphabet(std::string strings) {
  bool aux = false;
  std::string symbol;

  for (unsigned i = 0; i < strings.size(); i++) {
    aux = false;
    for (unsigned j = 0; j < alphabet_.GetAlphabetSize(); j++) {
      symbol = strings.at(i);
      if (symbol == alphabet_.GetWord(j).GetSymbol()) {
        aux = true;
      }
    }
    if (!aux) {
      return false;
    }
  }
  return true;
}

bool Automata::Read(std::string line) {
  if (line.at(0) == '&') {
    return states_.at(start_state_).IsAceptation();
  }
  if (!IsAlphabet(line)) {
    return false;
  }
  State actual = states_.at(start_state_);
  Transition next;
  std::string aux;

  for (unsigned i = 0; i < line.size(); i++) {
    aux = line.at(i);
    next = actual.GetTransition(aux);
    actual = states_.at(next.GetPos());
  }
  return actual.IsAceptation();
}