/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramática en Forma Normal de Chomsky
 * @file grammar.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los diferentes metodos de la clase
 * 'Grammar'
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

// cd
// /mnt/f/Google\ Drive\ ALU/Ingenieria\ Informatica/2ºIng\ Informatica/Primer\ Cuatrimestre/Computabilidad\
// Y\ Algoritmia/Curso\ 2022-2023/Practicas-CyA/Practica\ 8\ Gramaticas\ en\ Forma\
// Normal\ de\ Chomsky/

#include "grammar.h"

/**
 * @brief Constructor por defecto
 *
 */
Grammar::Grammar() {}

/**
 * @brief Constructor parametrizado que recibe un fichero de entrada (una
 * gramatica regular) y lo "construye"
 *
 * @param grammar_file
 */
Grammar::Grammar(std::ifstream& grammar_file) {
  std::string line;
  int count = 0;

  while (getline(grammar_file, line)) {
    if (count == 0) {
      num_terminal_symbols_ = std::stoi(line);
      std::cout << "Numero de simbolos terminales: " << num_terminal_symbols_
                << std::endl;
      count++;
    }
    if (count == 1) {
      std::cout << "Simbolos terminales: " << std::endl;
      for (int i = 0; i < num_terminal_symbols_; i++) {
        getline(grammar_file, line);
        terminal_symbols_.push_back(line);
        std::cout << terminal_symbols_[i] << std::endl;
      }
    } else if (count == 2) {
      num_non_terminal_symbols_ = std::stoi(line);
      std::cout << "Numero de simbolos no terminales: "
                << num_non_terminal_symbols_ << std::endl;
    } else if (count == 3) {
      std::cout << "Simbolos no terminales: " << std::endl;
      non_terminal_symbols_.push_back(line);
      std::cout << non_terminal_symbols_[0] << std::endl;
      for (int i = 0; i < num_non_terminal_symbols_ - 1; i++) {
        getline(grammar_file, line);
        non_terminal_symbols_.push_back(line);
        std::cout << non_terminal_symbols_[i + 1] << std::endl;
      }
    } else if (count == 4) {
      start_symbol_ = line;
      std::cout << "Simbolo inicial: " << start_symbol_ << std::endl;
    } else if (count == 5) {
      num_productions_ = std::stoi(line);
      std::cout << "Numero de producciones: " << num_productions_ << std::endl;
    } else if (count == 6) {
      std::string left_side = line.substr(0, line.find("->"));
      std::string right_side = line.substr(line.find("->") + 2);
      productions_.push_back(std::make_pair(left_side, right_side));
      std::cout << left_side << "->" << right_side << std::endl;
      for (int i = 0; i < num_productions_ - 1; i++) {
        getline(grammar_file, line);
        left_side = line.substr(0, line.find("->"));
        right_side = line.substr(line.find("->") + 2);
        productions_.push_back(std::make_pair(left_side, right_side));
        std::cout << left_side << "->" << right_side << std::endl;
      }
    }
    count++;
  }
}

/**
 * @brief Metodo para obtener el número de símbolos terminales de la gramática
 * en Forma Normal de Chomsky
 *
 */
void Grammar::ChomskyAlgorithm() {
  // convertir a -> C, b -> D
  // reemplazar a -> C, b -> D en las producciones y que siempre sea asi
  std::string no_terminal_symbols_aux = "SABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::vector<std::string> productions_aux;
  int count = num_non_terminal_symbols_;
  std::set<std::string> new_production_aux;

  for (size_t i = 0; i < productions_.size(); i++) {              // for all productions
    std::string aux = productions_[i].second;
    for (size_t j = 0; j < productions_[i].second.size(); j++) {         // for all Xi
      if (productions_[i].second.size() > 2) {                                          
        for (size_t k = 0; k < terminal_symbols_.size(); k++) {
          if (productions_[i].second[j] == terminal_symbols_[k][0]) {  // si Xi pertenece al alfabeto
            if (productions_[i].second[j] > 2) {
              char new_non_terminal_symbol = no_terminal_symbols_aux[count];
              std::string new_production = "";
              new_production += no_terminal_symbols_aux[count];
              new_production += " -> ";
              new_production += terminal_symbols_[k];
              productions_aux.push_back(new_production);
              new_production_aux.insert(new_production);
              aux[j] = new_non_terminal_symbol;
              std::cout << productions_[i].first << "->" << aux << std::endl;
            }
          }
        }
      }
    }
  }

  for (std::set<std::string>::iterator it = new_production_aux.begin(); it != new_production_aux.end(); ++it) {
    std::cout << *it << std::endl;
  }
}