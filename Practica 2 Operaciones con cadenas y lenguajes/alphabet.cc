/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes 
 * @file alphabet.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.2
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "alphabet.h"

#include "string.h"

Alphabet::~Alphabet() {}

// Setters
void Alphabet::SetAlphabet(std::vector<std::string> _AlphaList) {
  AlphaList = _AlphaList;
}

// Getters
std::vector<std::string> Alphabet::GetAlphabet() { return AlphaList; }

void Alphabet::SearchAlphabet(std::string String) {
  std::string Alpha;

  for (unsigned i = 0; i <= String.length(); i++) {
    std::size_t result = Alpha.find(String[i]);
    if (result == std::string::npos) {
      Alpha += " ";
      Alpha += String[i];
    }
  }
  std::cout << "El alfabeto de la cadena \"" << String << "\" es: ";
  std::cout << Alpha << " " << std::endl;
}