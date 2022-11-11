/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file p07_dfa2grammar.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>

#include "../include/automata.h"

const std::string HELP = "--help";

void check_parameters(std::string &, std::string &, int, char **);
bool check_automata(std::ifstream &);

int main(int argc, char *argv[]) {
  std::string strings, automata_in, strings_in, line;
  std::ifstream automata_file, strings_file;

  check_parameters(automata_in, strings_in, argc, argv);

  automata_file.open(automata_in, std::ios::in);
  strings_file.open(strings_in, std::ios::in);

  if (automata_file.fail() || strings_file.fail()) {
    std::cout << "Error en la apertura de los ficheros " << std::endl;
    exit(1);
  }

  Automata automata(automata_file);
  std::cout << std::endl;
  while (getline(strings_file, line)) {
    std::cout << line << std::endl;
    if (automata.Read(line)) {
      std::cout << "Accepted" << std::endl << std::endl;
    } else {
      std::cout << "Rejected" << std::endl << std::endl;
    }
  }

  strings.clear();
  automata_file.close();
  strings_file.close();
}

/**
 * @brief Comprueba que los parámetros introducidos son correctos
 *
 * @param input_fa
 * @param input_gra
 * @param argc
 * @param argv
 */
void check_parameters(std::string &input_fa, std::string &input_gra, int argc, char *argv[]) {
  std::regex fa_file("(.fa)$");
  std::regex gra_file("(.gra)$");

  if (argc == 3) {
    input_fa = argv[1];
    input_gra = argv[2];

    if (!(regex_search(argv[2], gra_file))) {
      std::cout << "El fichero de salida no es un fichero .gra" << std::endl;
      exit(1);
    }
  } else if (argc == 2) {
    if (argv[1] == HELP) {
      std::cout << " Para la correcta ejecución del programa, este debe invocarse";
      std::cout << " con dos parametros. Un fichero de entrada .fa y otro fichero de salida de tipo .gra." << std::endl;
      std::cout << " En el fichero de tipo .fa estará contenido el DFA que va a contener la especificacion de una gramatica regular, ";
      std::cout << " por ejemplo: input.fa" << std::endl;
      std::cout << " En el fichero de tipo .gra contendrá la especificación de una gramática regular, ";
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
    std::cout << "Modo de empleo: ./p07_dfa2grammar input.fa output.gra" << std::endl;
    std::cout << "Pruebe ’p07_dfa2grammar --help’ para más información." << std::endl;
    exit(1);
  }
}

/**
 * @brief Comprueba si el autómata es un automata o un NFA
 *
 * @param automata
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
    std::cout << "El automata es un automata" << std::endl;
    return false;
  } else {
    std::cout << "El automata es un NFA" << std::endl;
    return true;
  }
}