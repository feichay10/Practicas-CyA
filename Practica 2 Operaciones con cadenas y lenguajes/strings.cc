/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes 
 * @file strings.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.2
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "strings.h"

Strings::~Strings() {}

void Strings::SetOpcode(int _opcode) { opcode = _opcode; }

void Strings::SetString(std::vector<std::string> _string_list) {
  string_list = _string_list;
}

int Strings::GetOpcode() { return opcode; }

std::vector<std::string> Strings::GetString() { return string_list; }

void Strings::SaveStrings(std::string strings){
  string_list.push_back(strings);
}