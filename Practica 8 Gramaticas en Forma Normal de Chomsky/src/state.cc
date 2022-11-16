/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file state.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los diferentes metodos de la clase 'State'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/state.h"

/**
 * @brief Constructor de clase 'State', inicializa el estado de aceptacion 
 * y el estado inicial como false por defecto
 * 
 */
State::State() {
  aceptation_ = false;
  start_ = false;
}

/**
 * @brief Constructor de clase 'State'
 * 
 * @param aceptation Estado de aceptación
 * @param transitions_num Numero de transiciones
 */
State::State(bool aceptation, int transitions_num) {
  std::string aux = "q";

  aceptation_ = aceptation;
  start_ = false;
  name_ = aux + std::to_string(transitions_num);
}

/**
 * @brief Pone el estado como estado de aceptación
 * 
 */
void State::setAceptation() {
  aceptation_ = true;
}

/**
 * @brief Pone el estado como estado inicial
 * 
 */
void State::setStart() {
  start_ = true;
}

/**
 * @brief Setter de la variable 'name_'
 * 
 * @param name Nombre del estado
 */
void State::setName(std::string name){
  name_ = name;
}

/**
 * @brief Se introduce los estados con sus transiciones
 * 
 * @param line Introduccion de los estados del DFA
 */
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

/**
 * @brief Getter de la variable 'name_'
 * 
 * @return std::string 
 */
std::string State::getName() {
  return name_;
}

/**
 * @brief Devuelve la transicion del estado
 * 
 * @param symbol Introducir el simbolo de la transicion
 * @return Transition 
 */
Transition State::getTransition(std::string symbol) {
  for (unsigned i = 0; i < transitions_.size(); i++) {
    if (transitions_.at(i).getSymbol() == symbol) {
      return transitions_.at(i);
    }
  }
  exit(1);
}

/**
 * @brief Devuelve el numero de transiciones
 * 
 * @return std::vector<Transition> 
 */
std::vector<Transition> State::getTransitions() {
  return transitions_;
}

/**
 * @brief Devuelve el estado en la posicion 'pos'
 * 
 * @param pos Posicion del estado
 * @return std::string 
 */
std::string State::getStates(int pos) {
  return states_.at(pos);
}

/**
 * @brief Devuelve el tamaño del vector de estados
 * 
 * @return unsigned 
 */
unsigned State::getStatesSize() {
  return states_.size();
}

/**
 * @brief Devuelve si el estado es de aceptacion o no
 * 
 * @return true 
 * @return false 
 */
bool State::IsAceptation() {
  return aceptation_;
}

/**
 * @brief Devuelve si el estado es inicial o no
 * 
 * @return true 
 * @return false 
 */
bool State::IsStart() {
  return start_;
}

/**
 * @brief Devuelve la transicion del estado en la posicion 'pos'
 * 
 * @param pos 
 * @return Transition 
 */
Transition State::at(int pos) {
  return transitions_.at(pos);
}

/**
 * @brief Retorna el simbolo de la transicion en la posicion 'pos'
 * 
 * @param symbol 
 * @return std::vector<int> 
 */
std::vector<int> State::TransitionsPos(std::string symbol) {
  std::vector<int> aux;
  for (unsigned i = 0; i < transitions_.size(); i++) {
    if (symbol == transitions_.at(i).getSymbol()) {
      aux.push_back(i);
    }
  }
  return aux;
}

/**
 * @brief Resetea los estados y transiciones
 * 
 */
void State::clear() {
  aceptation_ = false;
  start_ = false;
  transitions_num_ = 0;
  transitions_.clear();
  name_ = "";
}