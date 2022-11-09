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
 * @date 2022-11-08
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

bool Nfa::Read(std::string line) {
  /**
   * @brief Reconoce si hay una cadena vacia 
   * 
   */
  if (line.at(0) == '&') {
    return states_.at(start_state_).IsAceptation();
  }

  State actual = states_.at(start_state_);
  Transition next;
  std::string symbol;

  /**
   * @brief Recorre la cadena de entrada y comprueba si la cadena de entrada tiene simbolos que pertenecen al DFA
   * 
   */
  for (unsigned i = 0; i < line.size() - 1; i++) {
    symbol = line.at(i);     
    if (!alphabet_.AlphabetComprobation(symbol)) {
      std::cout << "ERROR. Esta cadena tiene simbolos que no pertecen al alfabeto del DFA" << std::endl;
      return false;
    }
    //std::cout << actual.GetName() << "transita a ";
    next = actual.GetTransition(symbol);
    //std::cout << states_.at(next.GetPos()).GetName() << " con el simbolo " << symbol << std::endl;
    actual = states_.at(next.GetPos());
  }
  //std::cout << std::endl;
  return actual.IsAceptation();
}