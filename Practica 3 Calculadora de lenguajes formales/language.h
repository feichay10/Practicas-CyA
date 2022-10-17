/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file language.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <set>
#include <string>

#include "alphabet.h"

class strings;

class language {
 public:
  language() = default;
  language(std::set<strings> language);
  void set_Language(std::set<strings>);
  void set_Alphabet(alphabet);
  alphabet get_Alphabet() const;
  std::set<strings> get_Language() const;
  ~language();

 private:
  std::set<strings> language_;
  alphabet alphabet_;
};

language operator+(const language& language1, const language& language2);
language operator|(const language& language1, const language& language2);
language operator^(const language& language1, const language& language2);
language operator-(const language& language1, const language& language2);
language operator!(const language& language);
language operator*(const language& language1, int exponent);

std::ostream& operator<<(std::ostream& out, const language& language);