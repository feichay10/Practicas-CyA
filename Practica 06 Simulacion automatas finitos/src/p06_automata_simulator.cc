/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file p06_dfa_simulator.cc
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <fstream>
#include <regex>
#include <cstring>

#include "../include/dfa.h"
#include "../include/nfa.h"

const std::string HELP = "--help";

void check_parameters(std::string &, std::string &, int, char**);
bool check_automata(std::ifstream &);

int main(int argc, char* argv[]) { 
  std::string strings, automata_in, strings_in, line;
  std::ifstream automata_file, automata_file_copy, strings_file;

  check_parameters(automata_in, strings_in, argc, argv); 
  
  automata_file.open(automata_in, std::ios::in);
  automata_file_copy.open(automata_in, std::ios::in);
  strings_file.open(strings_in, std::ios::in);

  if (automata_file.fail() || strings_file.fail()) {
    std::cout << "Error en la apertura de los ficheros " << std::endl;
    exit(1);
  }

  /**
   * @brief Si es un DFA hace operaciones de DFA y si es un NFA hace operaciones de NFA
   * 
   */
  if(!check_automata(automata_file)) {
    std::cout << "Es un DFA" << std::endl;
    Dfa dfa(automata_file_copy);
    std::cout << std::endl;
    while(getline(strings_file, line)) {
      std::cout << line << std::endl;
      if (dfa.Read(line)) {
        std::cout << "Accepted" << std::endl << std::endl;
      } else {
        std::cout << "Rejected" << std::endl << std::endl;
      }
    }
  } else {
    std::cout << "Es un NFA" << std::endl;
    Nfa nfa(automata_file_copy);
    std::cout << std::endl;
    while(getline(strings_file, line)) {
      std::cout << line << std::endl;
      if (nfa.Read(line)) {
        std::cout << "Accepted" << std::endl << std::endl;
      } else {
        std::cout << "Rejected" << std::endl << std::endl;
      }
    }
  }

  strings.clear();
  automata_file.close();
  automata_file_copy.close();
  strings_file.close();
}

/**
 * @brief Comprueba que los parámetros introducidos son correctos
 * 
 * @param input_fa 
 * @param input_txt 
 * @param argc 
 * @param argv 
 */
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
      std::cout << " Por ejemplo: ./p06_dfa_simulator input.fa input.txt" << std::endl;
      exit(0);
    }
    if (!(regex_search(argv[1], fa_file))) {
      std::cout << "El primer fichero de entrada no es un fichero .fa" << std::endl;
      exit(1);
    }
  } else {
    std::cout << "Modo de empleo: ./p06_dfa_simulator input.fa input.txt" << std::endl;
    std::cout << "Pruebe ’p06_dfa_simulator --help’ para más información." << std::endl;
    exit(1);
  }
}

/**
 * @brief Comprueba si el autómata es un DFA o un NFA
 * 
 * @param automata 
 * @return true 
 * @return false 
 */
bool check_automata(std::ifstream& automata) {
  std::string line, alpha, aux;
  int count = 0;
  unsigned transitions_num;
  int count_dfa = 0;
  int count_states = 0;
  
  while(getline(automata, line)){
    if(count == 0){                       // Coger el numero de simbolos en el alfabeto
      for (size_t i = 0; i < line.size() - 1; i++) {
        if(line[i] != ' '){
          alpha += line[i];
        }
      }
    } 
    else if(count > 2){
      aux = line.at(4);                   // Coge el numero de transiciones
      transitions_num = stoi(aux);
      if(alpha.size() == transitions_num) {
        count_dfa++;
      } 
      count_states++;
    }
    count++;
  }

  if (count_dfa == count_states) {
    std::cout << "El automata es un DFA" << std::endl;
    return false;
  } else {
    std::cout << "El automata es un NFA" << std::endl;
    return true;
  }
}