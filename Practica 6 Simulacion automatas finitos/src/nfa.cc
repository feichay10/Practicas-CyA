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