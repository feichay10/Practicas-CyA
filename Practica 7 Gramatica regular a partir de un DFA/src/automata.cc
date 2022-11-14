/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file automata.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/automata.h"
#include "../include/grammar.h"

Automata::Automata() {

}

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

void Automata::setAlphabet_symbols(std::string alphabet_symbols) {
  alphabet_symbols_ = alphabet_symbols;
}

void Automata::setNum_states(int num_states) { 
  num_states_ = num_states; 
}

void Automata::setStates(std::vector<State> states) { 
  states_ = states;
}

void Automata::setAlphabet(Alphabet alphabet) { 
  alphabet_ = alphabet; 
}

std::string Automata::getAlphabet_symbols(int pos) { 
  return alphabet_.getSymbol(pos);
}

int Automata::getNum_states() { 
  return num_states_; 
}

std::vector<State> Automata::getStates() { 
  return states_; 
}

int Automata::getNum_alphabet_symbols() { 
  return num_alphabet_symbols_; 
}

unsigned Automata::getStateSize() { 
  return state_.getStatesSize(); 
}

Grammar Automata::ConvertToGrammar() {
  return Grammar(*this);
}

// bool Automata::Read(std::string line) {
  
//   if (line.at(0) == '&') {
//     return states_.at(start_state_).IsAceptation();
//   }

//   State actual = states_.at(start_state_);      
//   Transition next;                              
//   std::string symbol;                           


//   for (unsigned i = 0; i < line.size() - 1; i++) {
//     symbol = line.at(i);     
//     if (!alphabet_.AlphabetComprobation(symbol)) {
//       std::cout << "ERROR. Esta cadena tiene simbolos que no pertecen al alfabeto del DFA" << std::endl;
//       return false;
//     }
//     std::cout << actual.GetName() << "transita a ";
//     next = actual.GetTransition(symbol); 
//     std::cout << states_.at(next.GetPos()).GetName() << " con el simbolo " << symbol << std::endl;
//     actual = states_.at(next.GetPos());
//   }
//   std::cout << std::endl;
//   return actual.IsAceptation();
// }