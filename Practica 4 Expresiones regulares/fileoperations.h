/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file fileoperations.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <iostream>

class fileoperations {
 public:
  void ReadFile(std::ifstream&);
  void WriteFile(std::ofstream&);
};