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

void FileOperations::WriteFile(std::ofstream &file_out, Comments &description, Comments &comments, Variables &variables, Loops &loops) {
  // file_out << "PROGRAM: " << name_program << std::endl;
  //std::cout << "PROGRAM: " << name_program << std::endl;
  // std::cout << "DESCRIPTION: " << std::endl;
  // std::cout << std::endl;
  // std::cout << "VARIABLES: " << std::endl;
  // if (!variables.IsIntEmpty() || !variables.IsDoubleEmpty()) {
  //   for (unsigned i = 0; i < variables.GetSizeInt(); i++) {
  //     std::cout << "[Line " << variables.GetFirstInt(i) << "]: INT ";
  //     std::cout << variables.GetSecondInt(i) << std::endl;
  //   }

  //   for (unsigned i = 0; i < variables.GetSizeDouble(); i++) {
  //     std::cout << "[Line " << variables.GetFirstDouble(i) << "]: DOUBLE ";
  //     std::cout << variables.GetSecondDouble(i) << std::endl;
  //   }
  // }
  // std::cout << std::endl;
  // std::cout << "STATEMENTS: " << std::endl;
  // if (!loops.IsForEmpty() || !loops.IsWhileEmpty()) {
  //   for (unsigned i = 0; i < loops.GetSizeFor(); i++) {
  //     std::cout << "[Line " << loops.GetFirstFor(i) << "]: " << loops.GetSecondFor(i) << std::endl;
  //   }

  //   for (unsigned i = 0; i < loops.GetSizeWhile(); i++) {
  //     std::cout << "[Line " << loops.GetFirstWhile(i) << "]: " << loops.GetSecondWhile(i) << std::endl;
  //   }
  // }
  // std::cout << std::endl;
  // std::cout << "MAIN: " << std::endl;
  // if(main_exist_) {
  //   std::cout << "True" << std::endl << std::endl;
  // } else {
  //   std::cout << "False" << std::endl << std::endl;;
  // }
  // std::cout << "COMMENTS: " << std::endl;
  // if(!comments.IsCommentsEmpty()) {
  //   for (unsigned i = 0; i < comments.GetSizeComments(); i++) {
  //     std::cout << "[Line " << comments.GetFirstComments(i) << "]: " << comments.GetSecondComments(i) << std::endl;
  //   }
  // }
}