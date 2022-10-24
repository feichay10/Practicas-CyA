/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file Comments.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Comments.h"

unsigned Comments::GetSizeDescription() {
  return var_description_vector_.size();
}

int Comments::GetFirstDescription(int pos) {
  return var_description_vector_.at(pos).first;
}

std::string Comments::GetSecondDescription(int pos) {
  return var_description_vector_.at(pos).second;
}

unsigned Comments::GetSizeComments() {
  return var_comments_vector_.size();
}

int Comments::GetFirstComments(int pos) {
  return var_comments_vector_.at(pos).first;
}

std::string Comments::GetSecondComments(int pos) {
  return var_comments_vector_.at(pos).second;
}

bool Comments::IsDescriptionEmpty() {
  if (var_description_vector_.empty()) {
    return true;
  } else {
    return false;
  }
}

bool Comments::IsCommentsEmpty() {
  if (var_comments_vector_.empty()) {
    return true;
  } else {
    return false;
  }
}

void Comments::SearchDescription(std::string &line, int line_pos) {
  std::regex description_regex1("\\/\\*+|\\*+\\/");
  std::regex description_regex2("[*]\\*?\\*(.)*"); // ^(\*)\\*?\\*(.)*
  std::regex description_regex3("\\*/\\w");
  std::regex description_regex_prueba("\/[*](?:.|\n)*?[*]\/"); //^(\*)\\*?\\*(.)*

  // if (regex_search(line, description_regex1) || regex_search(line, description_regex2) || regex_search(line, description_regex3)) {
  //   var_description_vector_.push_back({line_pos, line});
  //   //std::cout << "[Line " << line_pos << "] " << "COMMENT: Description" << line << std::endl;
  // }

  if (regex_search(line, description_regex_prueba)) {
    var_description_vector_.push_back({line_pos, line});
    //std::cout << "[Line " << line_pos << "] " << "COMMENT: Description" << line << std::endl;
  }
}

void Comments::SearchComments(std::string &line, int line_pos) {
  std::regex comments_regex("^(//)(.)*");

  if (regex_search(line, comments_regex)) {
    var_comments_vector_.push_back({line_pos, line});
    //std::cout << "[Line " << line_pos << "] " << line << std::endl;
  }
}