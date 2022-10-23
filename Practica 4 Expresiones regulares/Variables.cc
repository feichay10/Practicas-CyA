/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file Cont_variables.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Variables.h"

void Variables::SearchInt(std::string &line, int line_pos) {
  std::string var_int;
  size_t pos, pos_final;
  std::regex int_regex("( )*(int)(.)*(;|\\w)");

  if (regex_match(line, int_regex)) {
    pos = line.find("int");
    pos_final = (line.find(";") - pos - 3);
    var_int += line.substr(pos + 3, pos_final);

    std::cout << "[Line " << line_pos << "] " << "INT: " << var_int << std::endl;
  }
}

void Variables::SearchDouble(std::string &line, int line_pos) {
  std::string var_double;
  size_t pos, pos_final;
  std::regex double_rex("( )*(double)(.)*(;|\\w)");

  if (regex_match(line, double_rex)) {
    pos = line.find("double");
    pos_final = (line.find(";") - pos - 6);
    var_double += line.substr(pos + 6, pos_final);

    std::cout << "[Line " << line_pos << "] " << "DOUBLE: " << var_double << std::endl;
  }
}

