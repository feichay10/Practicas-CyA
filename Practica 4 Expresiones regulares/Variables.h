/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file Cont_variables.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Variables {
 public:
  void SearchInt(std::string &, int);
  void SearchDouble(std::string &, int);

 private:
  std::string variable_int_;
  std::string variable_double_;
  //std::vector<std::pair<int, std::string>> variables_;
};