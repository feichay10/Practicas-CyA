/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file return.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Modificacion
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//Modificacion

#include "return.h"

unsigned Return::GetSizeReturn() {
  return var_return_vector_.size();
}

int Return::GetFirstReturn(int pos) {
  return var_return_vector_.at(pos).first;
}

std::string Return::GetSecondReturn(int pos) {
  return var_return_vector_.at(pos).second;
}

bool Return::IsReturnEmpty() {
  if (var_return_vector_.empty()){
    return true;
  } else {
    return false;
  }
}

void Return::SearchReturn(std::string &line, int line_pos) {
  std::string var_return;
  size_t pos, pos_final;
  std::regex return_regex("( )*(return)(.)*(;|\\w)");

  if (regex_search(line, return_regex)) {
    pos = line.find("return");
    pos_final = (line.find(";") - pos - 6);
    var_return += line.substr(pos + 6, pos_final);

    var_return_vector_.push_back({line_pos, var_return});
  }
}