/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file Loops.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Loops.h"

void Loops::SearchFor(std::string &line, int line_pos) {
  std::regex for_regex("( )*(for)(.)*\\((.)*\\)(.)*");
  if (regex_search(line, for_regex)) {
    std::cout << "[Line " << line_pos << "] " << "LOOP: for" << std::endl;
  }
}

void Loops::SearchWhile(std::string &line, int line_pos) {
  std::regex while_regex("( )*(while)(.)*\\((.)*\\)(.)*");
  if (regex_search(line, while_regex)) {
    std::cout << "[Line " << line_pos << "] " << "LOOP: while" << std::endl;
  }
}