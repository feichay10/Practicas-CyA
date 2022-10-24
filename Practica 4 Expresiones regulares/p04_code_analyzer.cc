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

#include "FileOperations.h"
#include "Comments.h"
#include "Variables.h"
#include "Loops.h"

const std::string HELP = "--help";

void printAll(std::string, FileOperations &, Comments &, Comments &, Variables &, Loops &);

int main(int argc, char* argv[]) {
  std::string input, output;
  FileOperations file;
  Comments description;
  Comments comments;
  Variables variables;
  Loops loops;

  if (argc == 3) {
    input = argv[1];
    output = argv[2];
  } else if (argc == 2) {
    if (argv[1] == HELP) {
      std::cout << "Para la correcta ejecución del programa, este debe invocarse";
      std::cout << " con dos parametros. Un fichero de entrada, y otro de salida.";
      std::cout << " Por ejemplo: ./p04_code_analyzer code.cc codescheme.txt" << std::endl;
      exit(0);
    }
  } else {
    std::cout << "Parametros erroneos, para ver el funcionamiento del programa,";
    std::cout << " ejecute ./p04_code_analyzer --help" << std::endl;
    exit(1);
  }

  std::ifstream file_in;
  std::ofstream file_out;

  file_in.open(input, std::ios::in);
  file_out.open(output, std::ios::out | std::ios::ate);


  if (file_in.fail() && file_out.fail()){
    std::cout << "Error en la apertura de los ficheros" << std::endl;
  }

  file.ReadFile(file_in, description, comments, variables, loops);
  printAll(input, file, description, comments, variables, loops);
  file.WriteFile(file_out, description, comments, variables, loops);

  file_in.close();
  file_out.close();
}

void printAll(std::string name_program, FileOperations &main, Comments &description, Comments &comments, Variables &variables, Loops &loops) {
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
      std::cout << "[Line " << loops.GetFirstFor(i) << "]: " << loops.GetSecondFor(i) << std::endl;
    }

    for (unsigned i = 0; i < loops.GetSizeWhile(); i++) {
      std::cout << "[Line " << loops.GetFirstWhile(i) << "]: " << loops.GetSecondWhile(i) << std::endl;
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
  if(!comments.IsCommentsEmpty()) {
    for (unsigned i = 0; i < comments.GetSizeComments(); i++) {
      std::cout << "[Line " << comments.GetFirstComments(i) << "]: " << comments.GetSecondComments(i) << std::endl;
    }
  }
}