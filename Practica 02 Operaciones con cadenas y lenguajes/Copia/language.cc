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

#include "strings.h"

Language::~Language() {}

void Language::setPowNum(int _pow_num) { pow_num = _pow_num; }
//void Language::setLanguage(std::string _language) { language = _language; }

int Language::getPowNum() { return pow_num; }
//std::set<std::string> Language::getLanguage() { return language; }

std::string Language::concatenation(Strings string1, Strings string2) {
  std::set<std::string> result_concatenation;
  // for (unsigned i = 0; i < string1.getStringList().size(); i++) {
  //   for (unsigned j = 0; j < string2.getStringList().size(); j++) {
      result_concatenation.insert(string1.getString() + string2.getString());
  //   }
  // }

  std::cout << "Concatenacion: " << std::endl;
  for(auto strings : result_concatenation) {
    std::cout << strings << std::endl;
  }
}

// std::string Language::l_union(std::string) {}

// std::string Language::intersection(std::string) {}

// std::string Language::difference(std::string) {}

// std::string Language::reverse(Strings string1) {}

// std::string Language::pow(std::string) {}