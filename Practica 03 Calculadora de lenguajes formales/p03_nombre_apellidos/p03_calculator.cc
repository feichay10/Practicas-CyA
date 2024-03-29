/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file p03_calculator.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "functions.h"

int main (int argc, char* argv[]){
  CheckParameters(argc);
  std::string in_file = argv[1];
  std::vector<std::string> operations, vec_tags;
  std::vector<language> languages;
  ReadFile(in_file, operations, languages, vec_tags);
  MenuOperations(operations, languages, vec_tags);
}