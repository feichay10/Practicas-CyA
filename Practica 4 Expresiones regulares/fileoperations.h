/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file File_operations.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Variables.h"
#include "Loops.h"

class FileOperations {
 public:
  void ReadFile(std::ifstream&);
  void WriteFile(std::ofstream&);

  private:
    std::string lines_;
    int line_pos_ = 0;
    Variables variables_;
    Loops loops_;
    bool main_exist_;

    std::string name_program_;
    std::vector<std::string> lines_program_;
};