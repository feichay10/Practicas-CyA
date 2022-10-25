/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones regulares
 * @file return.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Modificacion
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Modificacion

#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Return {
 public:
  unsigned GetSizeReturn();
  int GetFirstReturn(int);
  std::string GetSecondReturn(int);
  bool IsReturnEmpty();

  void SearchReturn(std::string &, int);

 private:
  std::vector<std::pair<int, std::string>> var_return_vector_;
};