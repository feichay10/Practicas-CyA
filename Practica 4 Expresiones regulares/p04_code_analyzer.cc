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

const std::string HELP = "--help";

int main(int argc, char* argv[]) {
  std::string input, output;
  fileoperations file;

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

  file.ReadFile(file_in);
  file.WriteFile(file_out);
}
