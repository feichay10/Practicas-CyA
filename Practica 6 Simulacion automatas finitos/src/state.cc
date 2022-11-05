/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file state.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/state.h"

State::State() {
  aceptation_ = false;
  start_ = false;
}

State::State(bool aceptation, int transitions_num) {
  std::string aux = "q";

  aceptation_ = aceptation;
  start_ = false;
  name_ = aux + std::to_string(transitions_num);
}

void State::SetAceptation() {
  aceptation_ = true;
}

void State::SetStart() {
  start_ = true;
}

void State::SetName(std::string name){
  name_ = name;
}

void State::SetState(std::string line) {
  std::string aux;
  Transition next;
  
  aux = line.at(0);
  name_ = "q"  + aux;
  
  if (line.at(1) == '0') {
    aceptation_ = false;
  } else {
    aceptation_ = true;
  }
  aux = line.at(2);
  transitions_num_ = stoi(aux);
  for (int i = 3; i < line.size() - 1; i++) {
    aux = line.at(i);
    next.SetSymbol(aux);
    aux = line.at(i + 1);
    next.SetStateTo(aux);
    transitions_.push_back(next);
    i++;
  }

  // std::cout << "nombre = " << name_ << std::endl;
  // std::cout << "acepta? " << aceptation_ << std::endl;
  // std::cout << "Transiciones" << std::endl;
  // for (unsigned i = 0; i < transitions_.size(); i++) {
  //   std::cout << "Con el simbolo '" << transitions_.at(i).GetSymbol() << "' va a ";
  //   std::cout << transitions_.at(i).GetStateTo() << std::endl << std::endl;
  // }
}

bool State::IsAceptation() {
  return aceptation_;
}

bool State::IsStart() {
  return start_;
}

Transition State::GetTransition(std::string symbol) {
  for (unsigned i = 0; i < transitions_.size(); i++) {
    if (transitions_.at(i).GetSymbol() == symbol) {
      return transitions_.at(i);
    }
  }
}

void State::clear() {
  aceptation_ = false;
  start_ = false;
  name_.clear();
  transitions_num_ = 0;
  transitions_.clear();
}