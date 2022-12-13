/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file p04_code_analyzer.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Programa main del proyecto
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <iostream>
#include <string>

#include "fileoperations.h"
#include "comments.h"
#include "variables.h"
#include "loops.h"
#include "return.h"

const std::string HELP = "--help";

void check_parameters(std::string &, std::string &, int, char**);
void print_all(std::string, FileOperations &, Comments &, Comments &, Variables &, Loops &, Return &);

int main(int argc, char* argv[]) {
  std::string input, output;
  FileOperations file;
  Comments description;
  Comments comments;
  Variables variables;
  Loops loops;
  Return return_;

  check_parameters(input, output, argc, argv);

  std::ifstream file_in;
  std::ofstream file_out;

  file_in.open(input, std::ios::in);
  file_out.open(output, std::ios::out | std::ios::ate);


  if (file_in.fail() && file_out.fail()){
    std::cout << "Error en la apertura de los ficheros" << std::endl;
    exit(1);
  }

  file.ReadFile(file_in, description, comments, variables, loops, return_);
  print_all(input, file, description, comments, variables, loops, return_);
  file.WriteFile(input, file_out, description, comments, variables, loops, return_);

  file_in.close();
  file_out.close();
}

void check_parameters(std::string &input, std::string &output, int argc, char *argv[]) {
  std::regex cpp_file("(.cc)$");

  if (argc == 3) {
    input = argv[1];
    output = argv[2];
    if (!(regex_search(argv[1], cpp_file))) {
      std::cout << "El fichero de entrada no es un fichero.cc" << std::endl;
      exit(1);
    }
  } else if (argc == 2) {
    if (argv[1] == HELP) {
      std::cout << "Para la correcta ejecución del programa, este debe invocarse";
      std::cout << " con dos parametros. Un fichero de entrada (codigo en c++), y otro de salida.";
      std::cout << " Por ejemplo: ./p04_code_analyzer code.cc codescheme.txt" << std::endl;
      exit(0);
    }
    if (!(regex_search(argv[1], cpp_file))) {
      std::cout << "El fichero de entrada no es un fichero.cc" << std::endl;
      exit(1);
    }
  } else {
    std::cout << "Parametros erroneos, para ver el funcionamiento del programa,";
    std::cout << " ejecute ./p04_code_analyzer --help" << std::endl;
    exit(1);
  }
}


void print_all(std::string name_program, FileOperations &main, Comments &description, Comments &comments, Variables &variables, Loops &loops, Return &return_) {
  std::cout << "PROGRAM: " << name_program << std::endl;
  std::cout << "DESCRIPTION: " << std::endl;
  if(!description.IsDescriptionEmpty()) {
    for (unsigned i = 0; i < description.GetSizeDescription(); i++) {
      std::cout << description.GetSecondDescription(i) << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "VARIABLES: " << std::endl;
  if (!variables.IsIntEmpty() || !variables.IsDoubleEmpty()) {
    for (unsigned i = 0; i < variables.GetSizeInt(); i++) {
      std::cout << "[Line " << variables.GetFirstInt(i) << "]: INT ";
      std::cout << variables.GetSecondInt(i) << std::endl;
    }

    for (unsigned i = 0; i < variables.GetSizeDouble(); i++) {
      std::cout << "[Line " << variables.GetFirstDouble(i) << "]: DOUBLE ";
      std::cout << variables.GetSecondDouble(i) << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "STATEMENTS: " << std::endl;
  if (!loops.IsForEmpty() || !loops.IsWhileEmpty()) {
    for (unsigned i = 0; i < loops.GetSizeFor(); i++) {
      std::cout << "[Line " << loops.GetFirstFor(i) << "]: LOOP " << loops.GetSecondFor(i) << std::endl;
    }

    for (unsigned i = 0; i < loops.GetSizeWhile(); i++) {
      std::cout << "[Line " << loops.GetFirstWhile(i) << "]: LOOP " << loops.GetSecondWhile(i) << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "MAIN: " << std::endl;
  if(main.GetMainExist()) {
    std::cout << "True" << std::endl << std::endl;
  } else {
    std::cout << "False" << std::endl << std::endl;;
  }
  std::cout << "COMMENTS: " << std::endl;
  std::cout << "[Line 1 - " << description.GetLineDescription() << "] DESCRIPTION"<< std::endl;
  if(!comments.IsCommentsEmpty()) {
    for (unsigned i = 0; i < comments.GetSizeComments(); i++) {
      std::cout << "[Line " << comments.GetFirstComments(i) << "]: " << comments.GetSecondComments(i) << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "RETURNS: " << std::endl;
  if (!return_.IsReturnEmpty()) {
    for (unsigned i = 0; i < return_.GetSizeReturn(); i++) {
      std::cout << "[Line " << return_.GetFirstReturn(i) << "]: RETURN " << return_.GetSecondReturn(i) << std::endl;
    }
  }
}
