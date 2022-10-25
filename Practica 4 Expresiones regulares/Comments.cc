/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file comments.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Comments.h"

/**
 * @brief Getter para el tamaño del vector de descripcion
 * 
 * @return el tamaño del vector de pair de descripcion
 */
unsigned Comments::GetSizeDescription() {
  return var_description_vector_.size();
}

/**
 * @brief Getter para el primer elemento del pair en la posición i
 * 
 * @param pos 
 * @return un entero que es la primera posicion del pair
 */
int Comments::GetFirstDescription(int pos) {
  return var_description_vector_.at(pos).first;
}

/**
 * @brief Getter para el segundo elemento del pair en la posición i
 * 
 * @param pos 
 * @return un string que es la segunda posicion del pair
 */
std::string Comments::GetSecondDescription(int pos) {
  return var_description_vector_.at(pos).second;
}

/**
 * @brief Getter para el tamaño del vector de comentarios
 * 
 * @return el tamaño del vector de pair de comentarios
 */
unsigned Comments::GetSizeComments() {
  return var_comments_vector_.size();
}

/**
 * @brief Getter para el primer elemento del pair en la posición i
 * 
 * @param pos 
 * @return un entero que es la primera posicion del pair
 */
int Comments::GetFirstComments(int pos) {
  return var_comments_vector_.at(pos).first;
}

/**
 * @brief Getter para el segundo elemento del pair en la posición i
 * 
 * @param pos 
 * @return un std::string que es la segunda posicion del pair
 */
std::string Comments::GetSecondComments(int pos) {
  return var_comments_vector_.at(pos).second;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
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

void Comments::SetLineDescription(int line) {
  line_description_ = line;
}

int Comments::GetLineDescription() {
  return line_description_;
}


void Comments::SearchDescription(std::string &line, int line_pos) {
  std::regex description_regex1("^(\\s*)?\\/\\*");
  std::regex description_regex2("^(\\s*)?\\*");    
  std::regex description_regex3("^(\\s*)?\\*\\/");

  if (regex_search(line, description_regex1) || regex_search(line, description_regex2) || regex_search(line, description_regex3)) {
    var_description_vector_.push_back({line_pos, line});
  }

  if (regex_search(line, description_regex3)) {
    line_description_ = line_pos;
  }
}

void Comments::SearchComments(std::string &line, int line_pos) {
  std::regex comments_regex("^(\t)+(.)*|^//(.)*");   

  if (regex_search(line, comments_regex)) {
    var_comments_vector_.push_back({line_pos, line});
  }
}