/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file p03_calculator.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "functions.h"

int main (int argc, char* argv[]){
  CheckParameters(argc);
  std::string in_file = argv[1];
  ReadFile(in_file);
}