/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file p08_Grammar2CNF.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Programa principal que lee un fichero de entrada y genera un fichero
 * de salida con la gramática regular equivalente a la dada el DFA.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "grammar.h"

const std::string HELP = "--help";

void check_parameters(std::string &, std::string &, int, char **);
bool check_automata(std::ifstream &);

/**
 * @brief Programa principal
 *
 * @param argc Numero de argumentos
 * @param argv Posicion de los argumentos
 */
int main(int argc, char *argv[]) {
  std::string grammar_in, grammar_out;
  std::ifstream grammar_file_in;
  std::ofstream grammar_file_out;
  Grammar grammar;

  check_parameters(grammar_in, grammar_out, argc, argv);
  
  grammar_file_in.open(grammar_in, std::ios::in);
  grammar_file_out.open(grammar_out, std::ios::out | std::ios::ate);

  if (grammar_file_in.fail() || grammar_file_out.fail()) {
    std::cout << "Error en la apertura de los ficheros " << std::endl;
    exit(1);
  }

  grammar = Grammar(grammar_file_in);

  grammar_file_in.close();
  grammar_file_out.close();
}

/**
 * @brief Comprueba que los parámetros introducidos son correctos 
 * 
 * @param input_gra 
 * @param output_cnf 
 * @param argc 
 * @param argv 
 */
void check_parameters(std::string &input_gra, std::string &output_gra, int argc, char *argv[]) {
  std::regex gra_file("(.gra)$");
  
  if (argc == 3) {
    input_gra = argv[1];
    output_gra = argv[2];
    if (!(regex_search(argv[1], gra_file))) {
      std::cout << "El fichero de entra no es un fichero .gra" << std::endl;
      exit(1);
    }
    if (!(regex_search(argv[2], gra_file))) {
      std::cout << "El fichero de salida no es un fichero .gra" << std::endl;
      exit(1);
    }
  } else if (argc == 2) {
    if (argv[1] == HELP) {
      std::cout << " Para la correcta ejecución del programa, este debe invocarse";
      std::cout << " con dos parametros. Un fichero de entrada .gra y otro fichero de salida de tipo .gra." << std::endl;
      std::cout << " En el fichero de tipo .gra estará contenido la gramática regular, ";
      std::cout << " por ejemplo: input.gra" << std::endl;
      std::cout << " En el fichero de tipo .gra contendrá la especificación de una gramática en forma normal de Chomsky, ";
      std::cout << " por ejemplo: output.gra" << std::endl;
      std::cout << " La ejecución del programa es: " << argv[0] << " input.gra output.gra" << std::endl;
      std::cout << std::endl;
      exit(0);
    }
    if (!(regex_search(argv[1], gra_file))) {
      std::cout << "El primer fichero de entrada no es un fichero .gra" << std::endl;
      exit(1);
    }
  } else {
    std::cout << "Modo de empleo: ./p08_Grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "Pruebe ’p08_Grammar2CNF --help’ para más información." << std::endl;
    exit(1);
  }
}