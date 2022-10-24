/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file fileoperations.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "Variables.h"
#include "Loops.h"
#include "Comments.h"

class FileOperations {
 public:
  bool GetMainExist();
  void ReadFile(std::ifstream&, Comments&, Comments&, Variables&, Loops&);
  void WriteFile(std::string, std::ofstream&, Comments&, Comments&, Variables&, Loops&);

 private:
  std::string lines_;
  int line_pos_ = 0;
  bool main_exist_ = false;
};