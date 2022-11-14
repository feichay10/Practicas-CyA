/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file state.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
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

void State::setAceptation() {
  aceptation_ = true;
}

void State::setStart() {
  start_ = true;
}

void State::setName(std::string name){
  name_ = name;
}

void State::setState(std::string line) {
  std::string aux;
  size_t pos = 0;
  Transition next;
  Alphabet alphabet;
  Grammar grammar;
  aux = line.at(pos);               // Coger el nombre del estado
  pos++;
  
  if (line.size() != pos) {
    if (line.at(pos) == ' ') {
      pos++;
    }
  }

  name_ = grammar.GetNonTerminalSymbol(aux);
  states_.push_back(name_);


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
      next.setSymbol(aux);
      i++;
      if (line.at(i) == ' ') {
        i++;
      }
      aux = line.at(i);
      aux = grammar.GetNonTerminalSymbol(aux);
      next.setPos(aux);
      transitions_.push_back(next);
      i++;
    }

    std::cout << std::endl;
    std::cout << "Estado = " << name_ << std::endl;
    std::cout << "¿Estado de aceptacion? " << aceptation_ << std::endl;
    std::cout << "Transiciones: " << transitions_.size() << std::endl;
    for (unsigned i = 0; i < transitions_.size(); i++) {
      std::cout << "Con el simbolo '" << transitions_.at(i).getSymbol() << "' va a ";
      std::cout << transitions_.at(i).getPos() << std::endl;
    }
  }
}

std::string State::getName() {
  return name_;
}

Transition State::getTransition(std::string symbol) {
  for (unsigned i = 0; i < transitions_.size(); i++) {
    if (transitions_.at(i).getSymbol() == symbol) {
      return transitions_.at(i);
    }
  }
  exit(1);
}

std::vector<Transition> State::getTransitions() {
  return transitions_;
}

std::string State::getStates(int pos) {
  return states_.at(pos);
}

unsigned State::getStatesSize() {
  return states_.size();
}

bool State::IsAceptation() {
  return aceptation_;
}

bool State::IsStart() {
  return start_;
}

Transition State::at(int pos) {
  return transitions_.at(pos);
}

std::vector<int> State::TransitionsPos(std::string symbol) {
  std::vector<int> aux;
  for (unsigned i = 0; i < transitions_.size(); i++) {
    if (symbol == transitions_.at(i).getSymbol()) {
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