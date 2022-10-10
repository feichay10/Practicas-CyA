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

#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Strings;
class Language {
 private:
  // Atributos
  int pow_num;
  std::set<Strings> language;
  
 public:
  Language() = default;  // Constructor
  ~Language();           // Destructor

  // Setters
  void setPowNum(int);
  //void setLanguage(std::string);

  // Getters
  int getPowNum();
  //std::string getLanguage();

  // Metodos de la clase
  std::string concatenation(Strings, Strings);
  std::string l_union(std::string);
  std::string intersection(std::string);
  std::string difference(std::string);
  std::string reverse(Strings);
  std::string pow(std::string);
};


