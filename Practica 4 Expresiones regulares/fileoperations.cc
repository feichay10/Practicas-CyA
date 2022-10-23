/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file File_operations.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "FileOperations.h"

void FileOperations::ReadFile(std::ifstream &file_in) {
  std::regex SearchMain("int main.*\\(.*\\).*");
  
  while (getline(file_in, lines_)) {
    line_pos_++;
    loops_.SearchFor(lines_, line_pos_);
    loops_.SearchWhile(lines_, line_pos_);
    variables_.SearchInt(lines_, line_pos_);
    variables_.SearchDouble(lines_, line_pos_);
    if (regex_match(lines_, SearchMain)) {
      main_exist_ = true;
    }

  }
}

void FileOperations::WriteFile(std::ofstream &) {}