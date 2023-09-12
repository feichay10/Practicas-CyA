/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file language.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LANGUAGE_H_
#define LANGUAGE_H_
#pragma once

#include <iostream>
#include <set>
#include <string>

#include "alphabet.h"
#include "chain.h"
#include "symbol.h"

class Chain;

class Language {
 public:
  // Constructor
  Language();
  Language(Alphabet& alphabet);
  Language(std::string entry_string);

  // Getters and Setters
  void set_language(Chain entry_chain);
  std::set<Chain> get_language();
  void set_alphabet(Alphabet alphabet);
  Alphabet get_alphabet();

  // Methods
  void insert_chain(Chain& entry_chain);
  void insert_empty_chain();

  // Overload Operators
  friend std::ostream& operator<<(std::ostream& os, Language& language);
  friend Language operator+(const Language& language1, const Language& language2); // Concatenation
  friend Language operator|(const Language& language1, const Language& language2); // Union
  friend Language operator^(const Language& language1, const Language& language2); // Intersection
  friend Language operator-(const Language& language1, const Language& language2); // Difference
  friend Language operator!(const Language& language);                             // Reverse
  friend Language operator*(const Language& language, int exponent);              // Power

 private:
  std::set<Chain> language_;
  Alphabet alphabet_;
};

#endif  // LANGUAGE_H_