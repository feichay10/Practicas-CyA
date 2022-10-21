/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file fileoperations.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "fileoperations.h"

void fileoperations::ReadFile(std::ifstream &file_in) {
  std::stringstream ss;
  std::string lines, str;

  while (getline(file_in, lines, '\n')) {
    ss.str(lines);
    while (ss >> str) {
      std::cout << str << std::endl;
    }
  }
}

void fileoperations::WriteFile(std::ofstream &) {}