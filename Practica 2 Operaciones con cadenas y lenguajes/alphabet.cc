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

Alphabet::~Alphabet() {}

// Setters
void Alphabet::SetAlphabet(std::vector<std::string> _alpha_list) {
  alpha_list = _alpha_list;
}

// Getters
std::vector<std::string> Alphabet::GetAlphabet() { return alpha_list; }

// Metodos de la clase Alphabet
void Alphabet::SearchAlphabet(std::string string) {
  std::string alpha;

  for (unsigned i = 0; i <= string.length(); i++) {
    std::size_t result = alpha.find(string[i]);
    if (result == std::string::npos) {
      alpha += " ";
      alpha += string[i];
    }
  }
  std::cout << "El alfabeto de la cadena " << string << " es: ";
  std::cout << alpha << " " << std::endl;
}

void Alphabet::SaveAlphabet(std::string strings){
  alpha_list.push_back(strings);
}