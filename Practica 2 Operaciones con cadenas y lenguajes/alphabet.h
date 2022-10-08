/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes 
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.2
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class String;

class Alphabet {
 private:
  std::vector<std::string> alpha_list;

 public:
  Alphabet() = default;   // Constructor
  ~Alphabet();            // Destructor

  // Setters (establecer a los atributos)
  void SetAlphabet(std::vector<std::string>);

  // Getter (mostrar los atributos)
  std::vector<std::string> GetAlphabet();

  // Metodos de la clase Alphabet
  void SearchAlphabet(std::string);
  void SaveAlphabet(std::string);
}; 