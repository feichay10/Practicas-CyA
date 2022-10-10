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

Strings::Strings(std::string strings) { string_list.emplace_back(strings); }

Strings::~Strings() {}

void Strings::setOpcode(int _opcode) { opcode = _opcode; }

void Strings::setStringList(std::vector<std::string> _string_list) {
  string_list = _string_list;
}

int Strings::getOpcode() { return opcode; }

std::vector<std::string> Strings::getStringList() { return string_list; }

Strings operator+(Strings& strings1, Strings& strings2) {
  return Strings(strings1.getStringList()[0] + strings2.getStringList()[0]);
}

bool operator==(Strings& strings1, Strings& strings2) {
  if (strings1.getStringList()[0] != strings2.getStringList()[0]) {
    return false;
  } else {
    return true;
  }
}

bool operator==(Strings& strings1, std::string strings2) {
  if (strings1.getStringList()[0] != strings2) {
    return false;
  } else {
    return true;
  }
}

void Strings::saveStrings(std::string strings) {
  string_list.push_back(strings);
  for (unsigned i = 0; i < string_list.size(); i++) {
    std::cout << string_list[i] << " ";
  }
}

Strings& Strings::operator=(const Strings& strings) {
  if (this->string_list[0] == strings.string_list[0]) {
    return *this;
  }
  this->string_list[0] = strings.string_list[0];
  return *this;
}

std::ostream& operator<<(std::ostream& os, Strings& strings) {
  os << strings.getStringList()[0];
  return os;
}