/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file p06_automata_simulator.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "../include/dfa.h"
#include "../include/state.h"

const std::string HELP = "--help";

void check_parameters(std::string &, std::string &, int, char**);

int main(int argc, char* argv[]) { 
  std::string strings, dfa_in, strings_in;
  std::ifstream dfa_file, strings_file;

  check_parameters(dfa_in, strings_in, argc, argv); 
  
  dfa_file.open(dfa_in, std::ios::in);
  strings_file.open(strings_in, std::ios::in);

  if (dfa_file.fail() || strings_file.fail()) {
    std::cout << "Error en la apertura de los ficheros " << std::endl;
    exit(1);
  }

  Dfa dfa(dfa_file);

  dfa_file.close();
  strings_file.close();
}

void check_parameters(std::string &input_fa, std::string &input_txt, int argc, char *argv[]) {
  std::regex fa_file("(.fa)$");
  std::regex txt_file("(.txt)$");

  if (argc == 3) {
    input_fa = argv[1];
    input_txt = argv[2];

    if (!(regex_search(argv[2], txt_file))) {
      std::cout << "El segundo fichero de entrada no es un fichero .txt" << std::endl;
      exit(1);
    }
  } else if (argc == 2) {
    if (argv[1] == HELP) {
      std::cout << "Para la correcta ejecución del programa, este debe invocarse";
      std::cout << " con dos parametros. Un fichero de entrada .fa y otro fichero de tipo .txt.";
      std::cout << " Por ejemplo: ./p06_automata_simulator input.fa input.txt" << std::endl;
      exit(0);
    }
    if (!(regex_search(argv[1], fa_file))) {
      std::cout << "El primer fichero de entrada no es un fichero .fa" << std::endl;
      exit(1);
    }
  } else {
    std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "Pruebe ’p06_automata_simulator --help’ para más información." << std::endl;
    exit(1);
  }
}