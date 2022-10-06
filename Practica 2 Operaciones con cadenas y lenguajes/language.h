/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes
 * @file language.h
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

class Language {
 private:
  // Atributos
  int pow_num;

 public:
  // Constructor
  // Destructor

  // Setters
  void SetPowNum(int); 

  // Getters
  int GetPowNum();

  // Metodos de la clase
  std::string concatenation(std::string);
  std::string lunion(std::string);
  std::string intersection(std::string);
  std::string difference(std::string);
  std::string reverse(std::string);
  std::string pow(std::string);
};