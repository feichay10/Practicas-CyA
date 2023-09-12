/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file p01_strings.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

#include "alphabet.h"
#include "chain.h"

#define CADENA_VACIA "&"
#define SPACE ' '
// const char SPACE = ' ';

// void check_parameters(int argc, char *argv[]);
// std::vector<std::string> read_file(char *argv[]);
// Chain entry_without_alphabet(std::string line);
// Chain entry_with_alphabet(std::string line);
// std::vector<Chain> check_entry_lines(std::vector<std::string> entry_lines);

void check_parameters(int argc, char *argv[]) {
  int opcode;

  if (argc != 4) {  
    if (argc < 4) {
      std::cout << "ERROR, Faltan argumentos ./p01_strings filein.txt fileout.txt opcode" << std::endl;
      exit(EXIT_FAILURE);
    } else {
      std::cout << "ERROR, Demasiados argumentos ./p01_strings filein.txt fileout.txt opcode" << std::endl;
      exit(EXIT_FAILURE);
    }
  } else {
    opcode = atoi(argv[3]);
    if (opcode < 0 || opcode > 5) {
      std::cout << "Opcode erroneo. Opcode = [1 - 5]" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

std::vector<std::string> read_file(char *argv[]) {
  std::ifstream input(argv[1]);
  std::vector<std::string> lines;
  std::string line;

  if (input.fail()) {
    std::cout << "Error al abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }

  while (getline(input, line)) {
    lines.push_back(line);
  }

  input.close();
  return lines;
}

std::string entry_with_alphabet(std::string& line) {
  Chain chain;
  Alphabet alphabet;
  Symbol symbol;

  // Recorre la linea de derecha a izquierda hasta encontrar un espacio, lo que hay antes del espacio es la cadena
  // Guardar esa cadena
  for (int i = line.size() - 1; i >= 0; i--) {
    if (line[i] == SPACE) {
      std::string entry_chain = line.substr(i + 1, line.size() - 1);
      std::cout << " Cadena original: " << entry_chain << std::endl;
      chain.set_chain(entry_chain);
      line = line.substr(0, i);
      break;
    }
  }

  std::cout << " Alfabeto: " << line << std::endl;

  for (unsigned int i = 0; i < line.size(); i++) {
    std::string entry_symbol = line.substr(i, 1);
    symbol.set_symbol(entry_symbol[0]);
    alphabet.set_alphabet(symbol);
  }
  
  // chain.set_alphabet(alphabet);

  std::cout << " Cadena: " << chain.get_chain() << std::endl;
  //std::cout << " Alfabeto: " << chain.get_alphabet() << std::endl;

  return chain.get_chain();
}

std::string entry_without_alphabet(std::string line) {
  Chain chain;
  Alphabet alphabet;
  Symbol symbol;
  std::vector<std::string> aux; // Vector auxiliar para guardar los simbolos y asi poder eliminar los repetidos
  
  std::cout << " Cadena original: " << line << std::endl;
  for (unsigned int i = 0; i < line.size(); i++) {
    std::string entry_symbol = line.substr(i, 1);
    if (entry_symbol == "") {
      continue;
    }
    aux.push_back(entry_symbol);
    // std::cout << " Simbolo: " << entry_symbol << std::endl;
    if (std::count(aux.begin(), aux.end(), entry_symbol) == 1) {
      symbol.set_symbol(entry_symbol[0]);
      alphabet.set_alphabet(symbol);
    }
  }
  // chain.set_alphabet(alphabet);
  // chain.set_chain(line);

  //std::cout << " Alfabeto: " << chain.get_alphabet() << std::endl;
  std::cout << " Cadena: " << chain.get_chain() << std::endl;
  
  return chain.get_chain();
}

void operations(std::string exit_file, int opcode, std::vector<Chain>& chain) {
  std::ofstream output(exit_file);

  if (output.fail()) {
    std::cout << "Error al abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }

  for (unsigned int i = 0; i < chain.size(); i++) {
    switch (opcode) {
      case 1:
        std::cout << " La longitud de la cadena es: " << chain[i].get_chain().size() - 1 << std::endl << std::endl;
        output  << "La longitud de la cadena " << chain[i].get_chain() << " es: " << chain[i].get_chain().size() << std::endl;
        break;
      case 2:

        break;
      case 3:

        break;
      case 4:

        break;
      case 5:

        break;
    }
  }

  output.close();
}

std::vector<Chain> check_entry(std::vector<std::string>& entry, std::string exit_file, int opcode) {
  std::vector<Chain> chains;

  for (unsigned int i = 0; i < entry.size(); i++) {
    std::string line = entry[i];
    std::size_t found = line.find(SPACE);
    if (found == std::string::npos) {
      std::cout << "Cadena sin alfabeto" << std::endl;
      std::string entry_chain = entry_without_alphabet(line);
      Chain chain(entry_chain);
      chains.push_back(chain);
      operations(exit_file, opcode, chains);
      chains.clear();
    } else {
      std::cout << "Cadena con alfabeto" << std::endl;
      std::string entry_chain = entry_with_alphabet(line);
      Chain chain(entry_chain);
      chains.push_back(chain);
      operations(exit_file, opcode, chains);
      chains.clear();
    }
  }

  return chains;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> entry_lines;
  std::vector<Chain> chains;

  check_parameters(argc, argv);
  entry_lines = read_file(argv);
  chains = check_entry(entry_lines, argv[2], atoi(argv[3]));
  // operations(argv[2], atoi(argv[3]), chains);

  return 0;
}