/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file p02_languages.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../include/language.h"
#include "../include/functions.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> entry_lines_file_1;
  std::vector<std::string> entry_lines_file_2;
  std::vector<Language> language_1; 
  std::vector<Language> language_2;
  int opcode;

  if (check_parameters(argc, argv)) {
    if (argc == 4) {
      opcode = atoi(argv[3]);
      std::cout << "Fichero de entrada: " << argv[1] << std::endl;
      entry_lines_file_1 = read_file(argv[1]);
      language_1 = extract_entry(entry_lines_file_1);
      menu_operations(argv[2], opcode, language_1, language_2);
    } else if (argc == 5) {
      opcode = atoi(argv[4]);
      std::cout << "Fichero de entrada: " << argv[1] << std::endl;
      entry_lines_file_1 = read_file(argv[1]);
      language_1 = extract_entry(entry_lines_file_1);
      std::cout << "-------------------------------------------------------" << std::endl << std::endl;
      std::cout << "Fichero de entrada: " << argv[2] << std::endl;
      entry_lines_file_2 = read_file(argv[2]);
      language_2 = extract_entry(entry_lines_file_2);
      std::cout << "-------------------------------------------------------" << std::endl << std::endl;
      menu_operations(argv[3], opcode, language_1, language_2);
    }
  } else {
    exit(EXIT_FAILURE);
  }

  return 0;
}