/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file fileoperations.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "fileoperations.h"

bool FileOperations::GetMainExist() {
  return main_exist_;
}

void FileOperations::ReadFile(std::ifstream &file_in, Comments &description, Comments &comments, Variables &variables, Loops &loops, Return &return_) {
void FileOperations::ReadFile(std::ifstream &file_in, Comments &description, Comments &comments, Variables &variables, Loops &loops) {

  std::regex SearchMain("^int main");
  std::smatch match_main;

  while (getline(file_in, lines_)) {
    line_pos_++;
    description.SearchDescription(lines_, line_pos_);
    comments.SearchComments(lines_, line_pos_);
    loops.SearchFor(lines_, line_pos_);
    loops.SearchWhile(lines_, line_pos_);
    variables.SearchInt(lines_, line_pos_);
    variables.SearchDouble(lines_, line_pos_);
    if (regex_search(lines_, match_main, SearchMain)) {
      main_exist_ = true;
    }
    return_.SearchReturn(lines_, line_pos_);
  }
}

void FileOperations::WriteFile(std::string name_program, std::ofstream &file_out, Comments &description, Comments &comments, Variables &variables, Loops &loops, Return &return_) {
  }
}

void FileOperations::WriteFile(std::string name_program, std::ofstream &file_out, Comments &description, Comments &comments, Variables &variables, Loops &loops) {
  file_out << "PROGRAM: " << name_program << std::endl;
  file_out << "DESCRIPTION: " << std::endl;
  if(!description.IsDescriptionEmpty()) {
    for (unsigned i = 0; i < description.GetSizeDescription(); i++) {
      file_out << description.GetSecondDescription(i) << std::endl;
    }
  }
  file_out << std::endl;
  file_out << "VARIABLES: " << std::endl;
  if (!variables.IsIntEmpty() || !variables.IsDoubleEmpty()) {
    for (unsigned i = 0; i < variables.GetSizeInt(); i++) {
      file_out << "[Line " << variables.GetFirstInt(i) << "]: INT ";
      file_out << variables.GetSecondInt(i) << std::endl;
    }

    for (unsigned i = 0; i < variables.GetSizeDouble(); i++) {
      file_out << "[Line " << variables.GetFirstDouble(i) << "]: DOUBLE ";
      file_out << variables.GetSecondDouble(i) << std::endl;
    }
  }
  file_out << std::endl;
  file_out << "STATEMENTS: " << std::endl;
  if (!loops.IsForEmpty() || !loops.IsWhileEmpty()) {
    for (unsigned i = 0; i < loops.GetSizeFor(); i++) {
      file_out << "[Line " << loops.GetFirstFor(i) << "]: LOOP " << loops.GetSecondFor(i) << std::endl;
    }

    for (unsigned i = 0; i < loops.GetSizeWhile(); i++) {
      file_out << "[Line " << loops.GetFirstWhile(i) << "]: LOOP " << loops.GetSecondWhile(i) << std::endl;
    }
  }
  file_out << std::endl;
  file_out << "MAIN: " << std::endl;
  if(main_exist_) {
    file_out << "True" << std::endl << std::endl;
  } else {
    file_out << "False" << std::endl << std::endl;;
  }
  file_out << "COMMENTS: " << std::endl;
  file_out << "[Line 1 - " << description.GetLineDescription() << "] DESCRIPTION"<< std::endl;
  if(!comments.IsCommentsEmpty()) {
    for (unsigned i = 0; i < comments.GetSizeComments(); i++) {
      file_out << "[Line " << comments.GetFirstComments(i) << "]: " << comments.GetSecondComments(i) << std::endl;
    }
  }
  file_out << std::endl;
  file_out << "RETURNS: " << std::endl;
  if (!return_.IsReturnEmpty()) {
    for (unsigned i = 0; i < return_.GetSizeReturn(); i++) {
      file_out << "[Line " << return_.GetFirstReturn(i) << "]: RETURN " << return_.GetSecondReturn(i) << std::endl;
    }
  }

}
