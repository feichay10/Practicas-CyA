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

unsigned Loops::GetSizeFor() {
  return var_for_vector_.size();
}

int Loops::GetFirstFor(int pos) {
  return var_for_vector_[pos].first;
}

std::string Loops::GetSecondFor(int pos) {
  return var_for_vector_[pos].second;
}

unsigned Loops::GetSizeWhile() {
  return var_while_vector_.size();
} 

int Loops::GetFirstWhile(int pos) {
  return var_while_vector_[pos].first;
}

std::string Loops::GetSecondWhile(int pos) {
  return var_while_vector_[pos].second;
} 

bool Loops::IsForEmpty() {
  if (var_for_vector_.empty()) {
    return true;
  } else {
    return false;
  }
}

bool Loops::IsWhileEmpty() {
  if (var_while_vector_.empty()) {
    return true;
  } else {
    return false;
  }
}

void Loops::SearchFor(std::string &line, int line_pos) {
  std::regex for_regex("( )*(for)(.)*\\((.)*\\)(.)*");
  if (regex_search(line, for_regex)) {
    var_for_vector_.push_back({line_pos, "for"});
    //std::cout << "[Line " << line_pos << "] " << "LOOP: for" << std::endl;
  }
}

void Loops::SearchWhile(std::string &line, int line_pos) {
  std::regex while_regex("( )*(while)(.)*\\((.)*\\)(.)*");
  if (regex_search(line, while_regex)) {
    var_while_vector_.push_back({line_pos, "while"});
    //std::cout << "[Line " << line_pos << "] " << "LOOP: while" << std::endl;
  }
}