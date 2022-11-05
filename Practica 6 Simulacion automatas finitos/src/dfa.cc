/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file dfa.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/dfa.h"

Dfa::Dfa(std::ifstream& dfa_file){
  State actual;
  int count = 0;
  std::string line, name, aux;
  dfa_file >> states_size_;
  dfa_file >> first_state_;

  while(getline(dfa_file, line)){
    if (count != 0) {
      actual.SetState(line);
      states_.push_back(actual);
      actual.clear();
    }
    count++;
  }
  aux = line.at(2);
  count = stoi(aux);
  for (int i = 3; i < count * 2 + 2; i++) {
    aux = line.at(i);
    alphabet_.SetSymbol(aux);
    i++;
  }
}
