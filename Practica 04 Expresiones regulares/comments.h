/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file comments.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Comments {
 public:
  unsigned GetSizeDescription();
  int GetFirstDescription(int);
  std::string GetSecondDescription(int);
  unsigned GetSizeComments();
  int GetFirstComments(int);
  std::string GetSecondComments(int);
  void SearchDescription(std::string &, int);
  void SearchComments(std::string &, int);
  bool IsDescriptionEmpty();
  bool IsCommentsEmpty();
  void SetLineDescription(int);
  int GetLineDescription();

 private:
  std::vector<std::pair<int, std::string>> var_description_vector_;
  std::vector<std::pair<int, std::string>> var_comments_vector_;
  int line_description_;
};