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

/**
 * @brief Constructor por defecto
 * 
 */
Grammar::Grammar() {}

Grammar::Grammar(std::ifstream& grammar_file) {
  std::string line;

  while(getline(grammar_file, line)){
    std::cout << line << std::endl;
  }
}

/**
 * @brief Metodo para obtener el número de símbolos terminales de la gramática en Forma Normal de Chomsky
 * 
 * @return std::string 
 */
std::string Grammar::ChomskyAlgorithm(){
  
}