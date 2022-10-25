/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file variables.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "variables.h"

unsigned Variables::GetSizeInt() {
  return var_int_vector_.size();
}

int Variables::GetFirstInt(int pos) {
  return var_int_vector_.at(pos).first;
}

std::string Variables::GetSecondInt(int pos) {
  return var_int_vector_.at(pos).second;
}

unsigned Variables::GetSizeDouble() {
  return var_double_vector_.size();
}

int Variables::GetFirstDouble(int pos) {
  return var_double_vector_.at(pos).first;
}

std::string Variables::GetSecondDouble(int pos) {
  return var_double_vector_.at(pos).second;
}

bool Variables::IsIntEmpty() {
  if (var_int_vector_.empty()) {
    return true;
  } else {
    return false;
  }
}

bool Variables::IsDoubleEmpty() {
  if (var_double_vector_.empty()) {
    return true;
  } else {
    return false;
  }
}

void Variables::SearchInt(std::string &line, int line_pos) {
  std::string var_int;
  size_t pos, pos_final;
  std::regex int_regex("( )*(int)(.)*(;|\\w)");

  if (regex_match(line, int_regex)) {
    pos = line.find("int");
    pos_final = (line.find(";") - pos - 3);
    var_int += line.substr(pos + 3, pos_final);

    var_int_vector_.push_back({line_pos, var_int});
  }
}

void Variables::SearchDouble(std::string &line, int line_pos) {
  std::string var_double;
  size_t pos, pos_final;
  std::regex double_regex("( )*(double)(.)*(;|\\w)");

  if (regex_match(line, double_regex)) {
    pos = line.find("double");                          
    pos_final = (line.find(";") - pos - 6);    
    var_double += line.substr(pos + 6, pos_final);

    var_double_vector_.push_back({line_pos, var_double});
  }
}

