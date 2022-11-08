/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file nfa.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/nfa.h"

Nfa::Nfa(std::ifstream& nfa_file) {
  State actual;
  int count = 0;
  std::string line, aux;

  while(getline(nfa_file, line)){
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

bool Nfa::IsBranchAccepted(int pos, State actual, std::string line) {
  std::cout << "lapiz" << std::endl;
  std::string symbol, subline;
  std::vector<int> positions;
  Transition next = actual.at(pos);
  actual = states_.at(next.GetPos());

  for (unsigned i = 0; i < line.size(); i++) {
    //std::cout << actual.GetName() << std::endl;
    symbol = line.at(i);
    positions = actual.TransitionsPos(symbol);
    if (positions.size() > 1) {
      for (unsigned j = 0; j < positions.size(); j++) {
        subline = line.substr(i + 1,  line.size());
        if (IsBranchAccepted(positions.at(j), actual, subline)) {
          return true;
        }
      }
    } else {
      next = actual.GetTransition(symbol);
      actual = states_.at(next.GetPos());
    }
  }
  
  return actual.IsAceptation();
}

bool Nfa::Read(std::string line) {
  if (line.at(0) == '&') {
    return states_.at(start_state_).IsAceptation();
  }
  std::cout << "hola" << std::endl;
  State actual = states_.at(start_state_);
  Transition next;
  std::string symbol, subline;
  std::vector<int> positions;

  for (unsigned i = 0; i < line.size() - 1; i++) {
    //std::cout << actual.GetName() << " transita a ";
    symbol = line.at(i);
    std::cout << "simbolo: " << symbol << std::endl;
    positions = actual.TransitionsPos(symbol);
    std::cout << "posiciones: " << positions.size() << std::endl;

    std::cout << actual.GetName() << " transita a ";

    if (positions.size() > 1) {
      for (unsigned j = 0; j < positions.size(); j++) {
        subline = line.substr(i + 1,  line.size());
        if (IsBranchAccepted(positions.at(j), actual, subline)) {
          return true;
        }
      }
    } else {
      next = actual.GetTransition(symbol);
      std::cout << states_.at(next.GetPos()).GetName() << " con el simbolo " << symbol << std::endl;
      actual = states_.at(next.GetPos());
    }
  }
  return actual.IsAceptation();
}