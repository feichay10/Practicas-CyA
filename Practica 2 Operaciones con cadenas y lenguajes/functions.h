/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "language.h"
#include "strings.h"

class Functions {
 private:
  std::vector<std::string> list_input_1;
  std::vector<std::string> list_input_2;

 public:
  

  //Metodos de la clase Functions
  void CheckParameters(int argc, char *argv[]);
  void ReadFile(std::string, std::string, int);
  void WriteFile(std::string, int);
  void IterateFile(std::string, std::vector<std::string>);
  std::string Menu(int argc, char *argv[]);
}