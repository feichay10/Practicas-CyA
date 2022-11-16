/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file grammar.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los diferentes metodos de la clase 'Grammar'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/grammar.h"
#include "../include/automata.h"

/**
 * @brief Constructor por defecto
 * 
 */
Grammar::Grammar() {}

/**
 * @brief Constructor de la clase 'Grammar', recibe un DFA y lo convierte a una gramática regular
 * 
 * @param dfa Recibe un DFA
 */
Grammar::Grammar(Automata &dfa) {
  std::vector<State> states = dfa.getStates();

  num_terminal_symbols_ = dfa.getNumAlphabetSymbols();                        // Número de símbolos terminales  
  for (int i = 0; i < dfa.getNumAlphabetSymbols(); i++) {
    terminal_symbols_.push_back(dfa.getAlphabetSymbols(i));                   // Símbolos terminales
  }
  num_non_terminal_symbols_ = dfa.getNumStates();                             // Número de símbolos no terminales
  for (unsigned i = 0; i < states.size(); i++) {
    non_terminal_symbols_.push_back(states[i].getName());                     // Símbolos no terminales
  }
  start_symbol_ = states[0].getName();                                        // Start
  num_productions_ = dfa.getNumStates();                                      // Número de producciones
  for (size_t i = 0; i < states.size(); i++) {
    std::string production = states[i].getName() + " -> ";                    // Producciones, se añade el símbolo no terminal
    productions_.push_back(production);                                       // Se añade la producción en un vector
    std::vector<Transition> transition_aux = states[i].getTransitions();      // Se obtienen las transiciones del estado
    for (size_t j = 0; j < transition_aux.size(); j++) {                      
      std::string production_aux = productions_[i];                                       // Se obtiene la producción
      production_aux += transition_aux[j].getSymbol() + transition_aux[j].getPos();       // Se añade el símbolo terminal y el símbolo no terminal
      productions_[i] = production_aux;                                                   // Se actualiza la producción                        
      if (j != transition_aux.size() - 1) {
        productions_[i] += " | ";                                                         // Se añade el símbolo '|' si no es la última transición
      }
    }
    if (states[i].IsAceptation()) {
      productions_[i] += " | &";                                                         // Se añade el símbolo '&' si es un estado de aceptación
    }
  }

  is_regular(dfa);                                                                             // Se comprueba si es una gramática regular
}

/**
 * @brief Metodo para pasar el nombre de un estado a un símbolo no terminal
 * 
 * @param state Recibe el nombre de un estado
 * @return std::string 
 */
std::string Grammar::GetNonTerminalSymbol(std::string state) {
  int n = stoi(state);
  std::string no_terminal_symbols = "SABCDEFGHIJKLMNOPQRSTUVWXYZ";

  return no_terminal_symbols.substr(n, 1);
}

/**
 * ###### Modificacion ######
 * @brief Metodo para saber si la gramatica es regular o no
 * 
 * @param dfa 
 * @return true 
 * @return false 
 */
bool Grammar::is_regular(Automata &dfa) {
  std::string production_aux;
  std::vector<State> states = dfa.getStates();

  for (size_t i = 0; i < states.size(); i++) {                                  
    std::vector<Transition> transition_aux = states[i].getTransitions();   
    for (size_t j = 0; j < transition_aux.size(); j++) {            
      production_aux += transition_aux[j].getSymbol() + transition_aux[j].getPos();
      // std::cout << "Check " << production_aux << std::endl;
      if (production_aux.size() > 2) {
        std::cout << "\nLa gramatica no es regular" << std::endl;
        return false;
      }
      production_aux.clear();                                                                        
    }
  }
  std::cout << "\nLa gramatica es regular" << std::endl;
  return true;
}

/**
 * @brief Metodo para imprimir la gramática regular por pantalla
 * 
 */
void Grammar::PrintOnScreen() {
  std::cout << "DFA to Grammar:" << std::endl;
  std::cout << "Numero de simbolos terminales: " << num_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < terminal_symbols_.size(); i++) {
    std::cout << "Simbolo terminal: " << terminal_symbols_[i] << std::endl;
  }
  std::cout << "Numero de simbolos no terminales: " << num_non_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < non_terminal_symbols_.size(); i++) {
    std::cout << "Simbolo no terminal: " << non_terminal_symbols_[i] << std::endl;
  }
  std::cout << "Start: " << start_symbol_ << std::endl;
  std::cout << "Numero de producciones: " << num_productions_ << std::endl;
  for (unsigned i = 0; i < productions_.size(); i++) {
    std::cout << "Produccion " << i + 1 << ": " << productions_[i] << std::endl;
  }
}

/**
 * @brief Metodo para escribir la gramática regular en un fichero
 * 
 * @param output_file Fichero de salida introducido por el usuario
 */
void Grammar::PrintToFile(std::ofstream &output_file) {
  output_file << num_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < terminal_symbols_.size(); i++) {
    output_file << terminal_symbols_[i] << std::endl;
  }
  output_file << num_non_terminal_symbols_ << std::endl;
  for (unsigned i = 0; i < non_terminal_symbols_.size(); i++) {
    output_file << non_terminal_symbols_[i] << std::endl;
  }
  output_file << start_symbol_ << std::endl;
  output_file << num_productions_ << std::endl;
  for (unsigned i = 0; i < productions_.size(); i++) {
    output_file << productions_[i] << std::endl;
  }
}
