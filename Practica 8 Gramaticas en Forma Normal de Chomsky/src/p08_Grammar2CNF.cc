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

#include "../include/automata.h"
#include "../include/grammar.h"
#include "../include/state.h"

const std::string HELP = "--help";

void check_parameters_automata(std::string &, std::string &, int, char **);
bool check_automata(std::ifstream &);

/**
 * @brief Programa principal
 *
 * @param argc Numero de argumentos
 * @param argv Posicion de los argumentos
 */
int main(int argc, char *argv[]) {
  std::string strings, automata_in, grammar_out, line;
  std::ifstream automata_file, automata_file_copy;
  std::ofstream grammar_file;
  int option = 0;
  Grammar grammar;

  switch(option) {
    case 1:
      check_parameters_automata(automata_in, grammar_out, argc, argv);

      automata_file.open(automata_in, std::ios::in);
      automata_file_copy.open(automata_in, std::ios::in);
      grammar_file.open(grammar_out, std::ios::out | std::ios::ate);

      if (automata_file.fail() || grammar_file.fail()) {
        std::cout << "Error en la apertura de los ficheros " << std::endl;
        exit(1);
      }

      if (check_automata(automata_file)) {
        Automata automata1(automata_file_copy);  // Construccion del DFA
        grammar = automata1.ConvertToGrammar();  // convert to grammar
        std::cout << std::endl;
        grammar.PrintOnScreen();
        grammar.PrintToFile(grammar_file);
      }

      automata_file.close();
      automata_file_copy.close();
      grammar_file.close();
      break;
    case 2:
      break;
    default:
      std::cout << "Opción no válida" << std::endl;
      exit(1);
  }
}

/**
 * @brief Comprueba que los parámetros introducidos son correctos
 *
 * @param input_fa Fichero de entrada
 * @param output_gra Fichero de salida
 * @param argc Numero de argumentos
 * @param argv Posicion de los argumentos
 */
void check_parameters_automata(std::string &input_fa, std::string &output_gra, int argc, char *argv[]) {
  std::regex fa_file("(.fa)$");
  std::regex gra_file("(.gra)$");

  if (argc == 3) {
    input_fa = argv[1];
    output_gra = argv[2];
    if (!(regex_search(argv[2], gra_file))) {
      std::cout << "El fichero de salida no es un fichero .gra" << std::endl;
      exit(1);
    }
  } else if (argc == 2) {
    if (argv[1] == HELP) {
      std::cout << " Para la correcta ejecución del programa, este debe invocarse";
      std::cout << " con dos parametros. Un fichero de entrada .fa y otro fichero de salida de tipo .gra." << std::endl;
      std::cout << " En el fichero de tipo .fa estará contenido el DFA, ";
      std::cout << " por ejemplo: input.fa" << std::endl;
      std::cout << " En el fichero de tipo .gra contendrá la especificación de una gramática regular sacado a partir del DFA introducido, ";
      std::cout << " por ejemplo: output.gra" << std::endl;
      std::cout << " La ejecución del programa es: " << argv[0] << " input.fa output.gra" << std::endl;
      std::cout << std::endl;
      exit(0);
    }
    if (!(regex_search(argv[1], fa_file))) {
      std::cout << "El primer fichero de entrada no es un fichero .fa" << std::endl;
      exit(1);
    }
  } else {
    std::cout << "Modo de empleo: ./p08_Grammar2CNF input.fa output.gra" << std::endl;
    std::cout << "Pruebe ’p08_Grammar2CNF --help’ para más información." << std::endl;
    exit(1);
  }
}

/**
 * @brief Comprueba si el autómata es un DFA
 *
 * @param automata Fichero de entrada, que es un automata
 * @return true 
 * @return false  
 */
bool check_automata(std::ifstream &automata) {
  std::string line, alpha, aux;
  int count = 0;
  unsigned transitions_num;
  int count_automata = 0;
  int count_states = 0;

  while (getline(automata, line)) {
    if (count == 0) {  // Coger el numero de simbolos en el alfabeto
      for (size_t i = 0; i < line.size() - 1; i++) {
        if (line[i] != ' ') {
          alpha += line[i];
        }
      }
    } else if (count > 2) {
      aux = line.at(4);  // Coge el numero de transiciones
      transitions_num = stoi(aux);
      if (alpha.size() == transitions_num) {
        count_automata++;
      }
      count_states++;
    }
    count++;
  }

  if (count_automata == count_states) {
    std::cout << "El automata es un DFA" << std::endl;
    return true;
  } else {
    std::cout << "ERROR. El automata introducido no es un DFA" << std::endl;
    exit(1);
  }
}