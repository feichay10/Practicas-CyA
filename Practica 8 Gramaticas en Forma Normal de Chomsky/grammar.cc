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
  std::string no_terminal_symbols_aux = "SABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::vector<std::string> productions_aux;
  std::pair<std::string, std::string> new_production;
  std::vector<std::pair<std::string, std::string>> terminal_symbols_productions;
  bool flag = false;
  int count = 1;

  // Primera parte del algoritmo FNC
  for (size_t i = 0; i < productions_.size(); i++) {                      // Recorre las producciones
    std::string aux = productions_[i].second;                             // Guarda la parte derecha de la produccion
    for (size_t j = 1; j < productions_[i].second.size(); j++) {          // Recorre la parte derecha de la produccion
      if (productions_[i].second.size() > 2) {                            // Si la parte derecha de la produccion es mayor que 2
        for (size_t k = 0; k < terminal_symbols_.size(); k++) {           // Recorre los simbolos terminales
          if (productions_[i].second[j] == terminal_symbols_[k][0]) {     // Si el simbolo terminal es igual al simbolo de la parte derecha de la produccion
            for (size_t l = 0; l < productions_.size(); l++) {            // Recorre las producciones
              if (productions_[l].second == terminal_symbols_[k]) {       // Si la parte derecha de la produccion es igual al simbolo terminal
                flag = true;
              }
            }
            char new_non_terminal_symbol = no_terminal_symbols_aux[count];
            if (flag == false) {
              std::string aux;
              new_production.first = no_terminal_symbols_aux[count];
              new_production.second = terminal_symbols_[k];
              non_terminal_symbols_.push_back(new_production.first);
              productions_.push_back(new_production);
              aux = productions_[i].second;
              aux[j] = new_non_terminal_symbol;
              productions_[i].second = aux;
              terminal_symbols_productions.push_back(new_production);
              count++;
            }
          }
        }
        // Busca en todas las producciones los simbolos terminales y los sustituye por un nuevo simbolo no terminal 
        for (size_t l = 0; l < terminal_symbols_productions.size(); l++) {
          if (productions_[i].second[j] == terminal_symbols_productions[l].second[0] && productions_[i].second.size() > 2) {
            productions_[i].second.replace(j, 1, terminal_symbols_productions[l].first);
          }
        } 
      }
    }
  }

  // std::cout << "Contador: " << count << std::endl;

  // Segunda parte del algoritmo FNC
  std::vector<std::pair<std::string, std::string>> new_productions;
  std::pair<std::string, std::string> new_production_copy;

  for (size_t i = 0; i < productions_.size(); i++) {
    std::string aux = productions_[i].second;
    if (productions_[i].second.size() > 2) {
      int count_aux = 2;
      for (size_t j = 1; j < productions_[i].second.size(); j++) {
        std::string new_production_aux;
        for (int k = 0; k < count_aux; k++) {
          new_production_aux.push_back(aux[j]);
          if (k == 0) {
            j++;
          }
        }
        for (size_t l = count; l < no_terminal_symbols_aux.size(); l++) {
          if (no_terminal_symbols_aux[l] == non_terminal_symbols_[count][0]) {
            count++;
          } else {
            new_production_copy.first = no_terminal_symbols_aux[l];
            non_terminal_symbols_.push_back(new_production_copy.first);
            num_non_terminal_symbols_++;
            no_terminal_symbols_aux.erase(l, 1);
            new_production_copy.second = new_production_aux;
            new_productions.push_back(std::make_pair(new_production_copy.first, new_production_copy.second));
            productions_.push_back(new_production_copy);
            bool flag = false;
            for (size_t m = 0; m < productions_.size(); m++) {
              if (productions_[m].second == new_production_copy.second) {
                flag = true;
              }
            }
            if (flag == false) {
              productions_.push_back(new_production_copy);
              num_productions_++;
            }
            break;
          }
        }
      }
    }
  }

  // for (size_t i = 0; i < productions_.size(); i++) {
  //   for (size_t j = 0; j < productions_[i].second.size(); j++) {
  //     for (size_t k = 0; k < new_productions.size(); k++) {
  //       if (productions_[i].second[j] == new_productions[k].second[0]) {
  //         productions_[i].second.replace(j, 3, new_productions[k].first);
  //         // productions_[i].second.erase(j, 2);
  //       }
  //     }
  //   }
  // }
}


void Grammar::PrintOnScreen() {
  std::cout << "Gramatica en Forma Normal de Chomsky" << std::endl;
  std::cout << "Numero de simbolos terminales: " << num_terminal_symbols_
            << std::endl;
  std::cout << "Simbolos terminales: " << std::endl;
  for (int i = 0; i < num_terminal_symbols_; i++) {
    std::cout << terminal_symbols_[i] << std::endl;
  }
  std::cout << "Numero de simbolos no terminales: "
            << non_terminal_symbols_.size() << std::endl;
  std::cout << "Simbolos no terminales: " << std::endl;
  for (size_t i = 0; i < non_terminal_symbols_.size(); i++) {
    std::cout << non_terminal_symbols_[i] << std::endl;
  }
  std::cout << "Simbolo inicial: " << start_symbol_ << std::endl;
  std::cout << "Producciones: " << std::endl;
  for (size_t i = 0; i < productions_.size(); i++) {
    std::cout << productions_[i].first << " -> " << productions_[i].second
              << std::endl;
  }
}

void Grammar::PrintToFile(std::ofstream & grammar_file_out) {
  grammar_file_out << num_terminal_symbols_ << std::endl;
  for (int i = 0; i < num_terminal_symbols_; i++) {
    grammar_file_out << terminal_symbols_[i] << std::endl;
  }
  grammar_file_out << non_terminal_symbols_.size() << std::endl;
  for (size_t i = 0; i < non_terminal_symbols_.size(); i++) {
    grammar_file_out << non_terminal_symbols_[i] << std::endl;
  }
  grammar_file_out << start_symbol_ << std::endl;
  for (size_t i = 0; i < productions_.size(); i++) {
    grammar_file_out << productions_[i].first << " -> " << productions_[i].second << std::endl;
  }
}