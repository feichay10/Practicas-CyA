/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file loops.h
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

class Loops {
 public:
  unsigned GetSizeFor();
  int GetFirstFor(int);
  std::string GetSecondFor(int);
  unsigned GetSizeWhile();
  int GetFirstWhile(int);
  std::string GetSecondWhile(int);
  void SearchFor(std::string &, int);
  void SearchWhile(std::string &, int);
  bool IsForEmpty();
  bool IsWhileEmpty();

 private:
  std::vector<std::pair<int, std::string>> var_for_vector_;
  std::vector<std::pair<int, std::string>> var_while_vector_;
};