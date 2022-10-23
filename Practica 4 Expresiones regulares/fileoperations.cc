/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file FileOperations.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "FileOperations.h"

bool FileOperations::GetMainExist() {
  return main_exist_;
}

void FileOperations::ReadFile(std::ifstream &file_in, Comments &description, Comments &comments, Variables &variables, Loops &loops) {
  std::regex SearchMain("int main.*\\(.*\\).*");

  while (getline(file_in, lines_)) {
    line_pos_++;
    description.SearchDescription(lines_, line_pos_);
    comments.SearchComments(lines_, line_pos_);
    loops.SearchFor(lines_, line_pos_);
    loops.SearchWhile(lines_, line_pos_);
    variables.SearchInt(lines_, line_pos_);
    variables.SearchDouble(lines_, line_pos_);
    if (regex_match(lines_, SearchMain)) {
      main_exist_ = true;
    }
  }
}

void FileOperations::WriteFile(std::ofstream &file_out) {
  // file_out << "PROGRAM: " << name_program << std::endl;
}