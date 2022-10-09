/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes
 * @file language.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "language.h"
#include "string.h"

Language::~Language() {}

void Language::setPowNum(int _pow_num) { pow_num = _pow_num; }

int Language::getPowNum() { return pow_num; }

// std::string Language::concatenation(std::string) {
  
// }

// std::string Language::l_union(std::string) {}

// std::string Language::intersection(std::string) {}

// std::string Language::difference(std::string) {}

// std::string Language::reverse(std::string) {}

// std::string Language::pow(std::string) {}