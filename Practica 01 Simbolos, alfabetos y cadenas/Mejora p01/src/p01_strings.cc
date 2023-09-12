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
#include <string>
#include <vector>

#include "../include/functions.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> entry_lines;

  if (check_parameters(argc, argv)) {
    entry_lines = read_file(argv);;
    check_entry(entry_lines, argv[2], atoi(argv[3]));
  } else {
    exit(EXIT_FAILURE);
  }

  return 0;
}