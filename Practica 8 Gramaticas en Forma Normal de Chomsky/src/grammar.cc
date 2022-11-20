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
 * @brief Contiene la implementación de los diferentes metodos de la clase
 * 'Grammar'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/grammar.h"

/**
 * @brief Constructor por defecto
 *
 */
Grammar::Grammar() {}

// 2                    Numero de simbolos terminales
// a                    Simbolo terminal
// b                    Simbolo terminal
// 3                    Numero de simbolos no terminales
// S                    Simbolo no terminal
// A                    Simbolo no terminal
// B                    Simbolo no terminal
// S                    Simbolo inicial
// 3                    Numero de producciones
// S -> aS | bA         Produccion 1
// A -> aB | bB         Produccion 2
// B -> aB | bB | &     Produccion 3

/**
 * @brief Constructor parametrizado que recibe un fichero de entrada (una
 * gramatica regular) y lo "construye"
 *
 * @param grammar_file
 */
Grammar::Grammar(std::ifstream& grammar_file) {
  std::cout << "Entro al constructor de Grammar" << std::endl;
  std::string line;
  int count = 0;

  while (getline(grammar_file, line)) {
    if (count == 0) {
      num_terminal_symbols_ = std::stoi(line);
      std::cout << "Numero de simbolos terminales: " << num_terminal_symbols_ << std::endl;
      count++;
    } 
    if (count == 1) {
      std::cout << "Simbolos terminales: " << std::endl;
      for (int i = 0; i < num_terminal_symbols_; i++) {
        getline(grammar_file, line);
        std::cout << line << std::endl;
        terminal_symbols_.push_back(line);
      }
    } else if (count == 2) {
      num_non_terminal_symbols_ = std::stoi(line);
      std::cout << "Numero de simbolos no terminales: " << num_non_terminal_symbols_ << std::endl;
    } else if (count == 3) {
      std::cout << "Simbolos no terminales: " << std::endl;
      std::cout << line << std::endl;
      non_terminal_symbols_.push_back(line);
      for (int i = 0; i < num_non_terminal_symbols_ - 1; i++) {
        getline(grammar_file, line);
        std::cout << line << std::endl;
        non_terminal_symbols_.push_back(line);
      }
    } 
    else if (count == 4) {
      start_symbol_ = line;
      std::cout << "Simbolo inicial: " << start_symbol_ << std::endl;
    } else if (count == 5) {
      num_productions_ = std::stoi(line);
      std::cout << "Numero de producciones: " << num_productions_ << std::endl;
    } 
    else if (count == 6) {
      for (int i = 0; i < num_productions_; i++) {
        getline(grammar_file, line);
        std::cout << line << std::endl;
        productions_.push_back(line);
      }
    }
    count++;
  }
}

/**
 * @brief Metodo para obtener el número de símbolos terminales de la gramática
 * en Forma Normal de Chomsky
 *
 * @return std::string
 */
std::string Grammar::ChomskyAlgorithm() {}