/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file language.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/language.h"

Language::Language() {}

Language::Language(Alphabet& alphabet) {
  alphabet_ = alphabet;
}

void Language::set_language(Chain entry_chain) {
  language_.insert(entry_chain.get_chain());
}

std::set<Chain> Language::get_language() {
  return language_;
}

void Language::set_alphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}

Alphabet Language::get_alphabet() {
  return alphabet_;
}

void Language::insert_chain(Chain& entry_chain) {
  language_.insert(entry_chain);
}

void Language::insert_empty_chain() {
  Chain empty_chain("&");
  language_.insert(empty_chain);
}

// print the same as the input file: { 0 1 } (alphabet) { 0 1 10 11 } (language)
std::ostream& operator<<(std::ostream& os, Language& language) {
  os << "{ ";
  for (unsigned int i = 0; i < language.get_alphabet().get_alphabet().size(); i++) {
    os << language.get_alphabet().get_alphabet()[i].get_symbol() << " ";
  }
  os << "} { ";
  for (std::set<Chain>::iterator it = language.language_.begin(); it != language.language_.end(); ++it) {
    os << *it << " ";
  }
  os << "}";

  return os;
}

/**
 * @TODO: 
 */
Language operator+(const Language& language_1, const Language& language_2) {
  Language language_concatenation;

  if (language_1.language_.size() == 1) {
    for (std::set<Chain>::iterator it = language_1.language_.begin(); it != language_1.language_.end(); ++it) {
      if (*it == Chain("&")) {
        return language_2;
      }
    }
  }

  if (language_2.language_.size() == 1) {
    for (std::set<Chain>::iterator it = language_2.language_.begin(); it != language_2.language_.end(); ++it) {
      if (*it == Chain("&")) {
        return language_1;
      }
    }
  }
  
  for (std::set<Chain>::iterator it_1 = language_1.language_.begin(); it_1 != language_1.language_.end(); ++it_1) {
    for (std::set<Chain>::iterator it_2 = language_2.language_.begin(); it_2 != language_2.language_.end(); ++it_2) {
      if (*it_1 == Chain("&")) {
        language_concatenation.language_.insert(*it_2);
      } else if (*it_2 == Chain("&")) {
        language_concatenation.language_.insert(*it_1);
      } else {
        language_concatenation.language_.insert(*it_1 + *it_2);
      }
    }
  }

  return language_concatenation;
}

// Σ = {0, 1}, L1 = {&, 0, 1, 10, 11} y L2 = {&, 1, 0110, 11010}
// L1 ∪ L2 = {&, 0, 1, 10, 11, 0110, 11010}
Language operator|(const Language& language_1, const Language& language_2) {
  Language language_union;

  for (std::set<Chain>::iterator it_1 = language_1.language_.begin(); it_1 != language_1.language_.end(); ++it_1) {
    language_union.language_.insert(*it_1);
  }

  for (std::set<Chain>::iterator it_2 = language_2.language_.begin(); it_2 != language_2.language_.end(); ++it_2) {
    language_union.language_.insert(*it_2);
  }

  return language_union;
}

// Σ = {0, 1}, L1 = {&, 0, 1, 10, 11} y L2 = {&, 1, 0110, 11010},
// L1 ∩ L2 = {&, 1}
Language operator^(const Language& language_1, const Language& language_2) {
  Language language_intersection;

  for (std::set<Chain>::iterator it_1 = language_1.language_.begin(); it_1 != language_1.language_.end(); ++it_1) {
    for (std::set<Chain>::iterator it_2 = language_2.language_.begin(); it_2 != language_2.language_.end(); ++it_2) {
      if (*it_1 == *it_2) {
        language_intersection.language_.insert(*it_1);
      }
    }
  }

  return language_intersection;
}

/**
 * Σ = {0, 1}, L1 = {&, 0, 1, 10, 11} y L2 = {&, 1, 0110, 11010}
 * L1 - L2 = {0, 10, 11}
 * @TODO:
 */
Language operator-(const Language& language_1, const Language& language_2) {
  Language language_difference;

  for (std::set<Chain>::iterator it_1 = language_1.language_.begin(); it_1 != language_1.language_.end(); ++it_1) {
    for (std::set<Chain>::iterator it_2 = language_2.language_.begin(); it_2 != language_2.language_.end(); ++it_2) {
      if (*it_1 != *it_2) {
        language_difference.language_.insert(*it_1);
      }
    }
  }

  return language_difference;
}

Language operator!(const Language& language) {
  Language language_reverse;
  std::set<Chain> aux_language;
  Chain aux_str;

  for (std::set<Chain>::iterator it = language.language_.begin(); it != language.language_.end(); ++it) {
    aux_str = *it;
    aux_language.insert(aux_str.reverse());
  }

  language_reverse.language_ = aux_language;

  return language_reverse;
}

/**
 * L = {0, 1}
 * L^3 = {000, 001, 010, 011, 100, 101, 110, 111}
 * @TODO:
 */
Language operator*(const Language& language, int exponent) {
  Language language_power;
  std::set<Chain> aux_language;
  Chain aux_str;

  for (std::set<Chain>::iterator it = language.language_.begin(); it != language.language_.end(); ++it) {
    aux_str = *it;
    for (int i = 0; i < exponent; i++) {
      aux_language.insert(aux_str);
    }
  }

  language_power.language_ = aux_language;

  return language_power;
}