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
  size_t pos = 0;
  Transition next;
  Alphabet alphabet;
  aux = line.at(pos); // Coger el nombre del estado
  pos++;
  
  if (line.size() != pos) {
    if (line.at(pos) == ' ') {
      pos++;
    }
  }
  
  name_ = "q"  + aux;

  // Condicion para saber si es el estado de aceptacion o no
  if (line.at(pos) == '0') {
    aceptation_ = false; // No es de aceptacion
  } else {
    aceptation_ = true; // Es de aceptacion
  }

  pos++;

  if (line.size() != pos) {
    if (line.at(pos) == ' ') {
      pos++;
    }
  }

  aux = line.at(pos); // Coge el numero de transiciones
  pos++;

  if (line.size() != pos) {
    if (line.at(pos) == ' ') {
      pos++;
    }
  }

  transitions_num_ = stoi(aux);

  if (transitions_num_ != 0) {
    for (size_t i = pos; i < line.size() - 1; i++) {
      aux = line.at(i);
      next.SetSymbol(aux);
      i++;
      if (line.at(i) == ' ') {
        i++;
      }
      aux = line.at(i);
      pos = stoi(aux);
      next.SetPos(pos);
      transitions_.push_back(next);
      i++;
    }

    std::cout << std::endl;
    std::cout << "Estado = " << name_ << std::endl;
    std::cout << "¿Estado de aceptacion? " << aceptation_ << std::endl;
    std::cout << "Transiciones: " << transitions_.size() << std::endl;
    for (unsigned i = 0; i < transitions_.size(); i++) {
      std::cout << "Con el simbolo '" << transitions_.at(i).GetSymbol() << "' va a ";
      std::cout << "q" << transitions_.at(i).GetPos() << std::endl;
    }
  }
}

bool State::IsAceptation() {
  return aceptation_;
}

bool State::IsStart() {
  return start_;
}

std::string State::GetName() {
  return name_;
}

Transition State::GetTransition(std::string symbol) {
  for (unsigned i = 0; i < transitions_.size(); i++) {
    if (transitions_.at(i).GetSymbol() == symbol) {
      return transitions_.at(i);
    }
  }
  exit(1);
}

Transition State::at(int pos) {
  return transitions_.at(pos);
}

std::vector<int> State::TransitionsPos(std::string symbol) {
  std::vector<int> aux;
  for (unsigned i = 0; i < transitions_.size(); i++) {
    if (symbol == transitions_.at(i).GetSymbol()) {
      aux.push_back(i);
    }
  }
  return aux;
}

void State::clear() {
  aceptation_ = false;
  start_ = false;
  transitions_num_ = 0;
  transitions_.clear();
  name_ = "";
}