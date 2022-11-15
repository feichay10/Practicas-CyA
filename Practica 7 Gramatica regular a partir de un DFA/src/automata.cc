/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file automata.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los diferentes metodos de la clase 'Automata'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/automata.h"
#include "../include/grammar.h"

/**
 * @brief Constructor por defecto
 *
 */
Automata::Automata() {}

/**
 * @brief Constructor de la clase 'Automata', recibe un fichero de entrada que
 * es un DFA y lo contruye
 *
 * @param automata_file Fichero de entrada que contiene un DFA
 */
Automata::Automata(std::ifstream& automata_file) {
  State actual;
  int count = 0;
  std::string line, aux;

  while (getline(automata_file, line)) {
    if (count == 0) {  // Recoge los simbolos del alfabeto del automata
      for (size_t i = 0; i < line.size() - 1; i++) {
        if (line[i] != ' ') {
          alphabet_symbols_ += line[i];
          std::cout << "Simbolo del alfabeto: " << alphabet_symbols_ << std::endl;
          num_alphabet_symbols_++;
          alphabet_.setSymbol(alphabet_symbols_);
          alphabet_symbols_.clear();
        }
      }
    } else if (count == 1) {  // Numero de estados
      num_states_ = std::stoi(line);
      std::cout << "Numero de estados: " << num_states_ << std::endl;
    } else if (count == 2) {  // Estado inicial
      start_state_ = line;
      std::cout << "Estado inicial: " << start_state_ << std::endl;
    } else if (count != 0) {  // Recoge los estados del automata
      actual.setState(line);
      states_.push_back(actual);
      actual.clear();
    }
    count++;
  }
}

/**
 * @brief Devuelve el simbolo del alfabeto
 * 
 * @param pos Posicion del simbolo del alfabeto
 * @return std::string 
 */
std::string Automata::getAlphabetSymbols(int pos) {
  return alphabet_.getSymbol(pos);
}

/**
 * @brief Devuelve el numero de estados
 * 
 * @return int 
 */
int Automata::getNumStates() { 
  return num_states_; 
}

/**
 * @brief Devuelve los estados del automata
 * 
 * @return std::vector<State> 
 */
std::vector<State> Automata::getStates() { 
  return states_; 
}

/**
 * @brief Devuelve el numero de simbolos del alfabeto
 * 
 * @return int 
 */
int Automata::getNumAlphabetSymbols() { 
  return num_alphabet_symbols_; 
}

/**
 * @brief Devuelve el tamaño del estado
 * 
 * @return unsigned o
 */
unsigned Automata::getStateSize() { 
  return state_.getStatesSize(); 
}

/**
 * @brief Convierte un DFA a una gramatica regular y retorna un objeto de la clase 'Grammar', el propio contructor de la clase
 * 
 * @return Grammar 
 */
Grammar Automata::ConvertToGrammar() { 
  return Grammar(*this); 
}