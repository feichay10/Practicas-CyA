/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file language.cc
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "language.h"

#include "strings.h"
#include "symbol.h"

// Constructor para sacar el alfabeto de las cadenas
language::language(std::set<strings> language) {
  language_ = language;

  for (std::set<strings>::iterator it = language_.begin(); it != language_.end(); ++it) { 
    for (size_t i = 0; i < it->get_string().size(); i++) {
      alphabet_.set_alphabet(it->get_string()[i]);
    }
  }
}

std::set<strings> language::get_Language() const { 
  return language_; 
}

void language::set_Language(std::set<strings> setlanguage) {
  language_ = setlanguage;
}

void language::set_Alphabet(alphabet alphabet) { 
  alphabet_ = alphabet;
}

alphabet language::get_Alphabet() const { 
  return alphabet_;
}

language::~language() {}

/**
 * @brief Concatenar dos lenguajes
 * 
 * @param language1 
 * @param language2 
 * @return language 
 */
language operator+(const language& language1, const language& language2) {
  language concatenation;
  std::set<strings> aux1 = language1.get_Language(), aux2 = language2.get_Language(), language_;

  if (aux1.size() == 1) {
    for (std::set<strings>::iterator it = aux1.begin(); it != aux1.end(); it++) {
      if (*it == strings("&")) {
        return language2; // Si concatenamos L1(&) con el lenguaje 2, el resultado es el lenguaje 2
      }
    }
  }

  if (aux2.size() == 1) {
    for (std::set<strings>::iterator it = aux2.begin(); it != aux2.end(); it++) {
      if (*it == strings("&")) {
        return language1; // Si concatenamos L2(&) con el lenguaje 1, el resultado es el lenguaje 1
      }
    }
  }

  for (std::set<strings>::iterator it1 = aux1.begin(); it1 != aux1.end(); it1++) { // Recorremos el lenguaje 1
    for (std::set<strings>::iterator it2 = aux2.begin(); it2 != aux2.end(); it2++) { // Recorremos el lenguage 2
      if (*it1 == strings("&")) {
        language_.insert(*it2); // Si la cadena es & solo insertamos la cadena del lenguaje 2
      } else if (*it2 == strings("&")) {
        language_.insert(*it1); // Si la cadena es & solo insertamos la cadena del lenguaje 1
      } else {
        language_.insert(*it1 + *it2); // si no es & concatenamos las cadenas de los dos lenguajes
      }
    }
  }
  concatenation.set_Language(language_); // Seteamos el lenguaje concatenado
  concatenation.set_Alphabet(language1.get_Alphabet()); // El alfabeto es el mismo que el del lenguaje 1
  return concatenation;
}

/**
 * @brief Union
 * 
 * @param language1 
 * @param language2 
 * @return language 
 */
language operator|(const language& language1, const language& language2) {
  language language_union;
  std::set<strings> strings_, aux1 = language1.get_Language(), aux2 = language2.get_Language();

  // Recorrer el lenguaje 1 y agregarlo al lenguaje union
  for (std::set<strings>::iterator it = aux1.begin(); it != aux1.end(); it++) {
    strings_.insert(*it);
  }

  // Recorrer el lenguaje 2 y agregarlo al lenguaje union
  for (std::set<strings>::iterator it = aux2.begin(); it != aux2.end(); it++) {
    strings_.insert(*it);
  }

  language_union.set_Language(strings_);  // Seteamos el lenguaje union
  language_union.set_Alphabet(language1.get_Alphabet()); // El alfabeto es el mismo que el del lenguaje 1
  return language_union;
}

/**
 * @brief Intersección de dos lenguajes
 * 
 * @param language1 
 * @param language2 
 * @return language 
 */
language operator^(const language& language1, const language& language2) {
  language intersection;
  std::set<strings> strings_, aux1 = language1.get_Language(), aux2 = language2.get_Language();
  for (std::set<strings>::iterator it1 = aux1.begin(); it1 != aux1.end(); it1++) {
    for (std::set<strings>::iterator it2 = aux2.begin(); it2 != aux2.end(); it2++) {
      if (*it1 == *it2) {
        strings_.insert(*it2);
      } 
    }
  }
  intersection.set_Language(strings_);
  intersection.set_Alphabet(language1.get_Alphabet());
  return intersection;
}

/**
 * @brief Diferencia de dos lenguajes 
 * 
 * @param language1 
 * @param language2 
 * @return language 
 */
language operator-(const language& language1, const language& language2) {
  size_t count = 0;
  language difference;
  std::set<strings> strings_, aux1 = language1.get_Language(), aux2 = language2.get_Language();

  for (std::set<strings>::iterator it1 = aux1.begin(); it1 != aux1.end(); it1++) {
    for (std::set<strings>::iterator it2 = aux2.begin(); it2 != aux2.end(); it2++) {
      if (*it1 == *it2) {
        ++count;
      }
    }
    if (count < 1) {
      strings_.insert(*it1);
    }
    count = 0;
  }

  count = 0;

  for (std::set<strings>::iterator it2 = aux2.begin(); it2 != aux2.end(); it2++) {
    for (std::set<strings>::iterator it1 = aux1.begin(); it1 != aux1.end(); it1++) {
      if (*it2 == *it1) {
        ++count;
      }
    }
    if (count < 1) {
      strings_.insert(*it2);
    }
    count = 0;
  }

  difference.set_Language(strings_);
  difference.set_Alphabet(language1.get_Alphabet());
  return difference;
}

/**
 * @brief Pow
 * 
 * @param language_ 
 * @return language 
 */
language operator!(const language& language_) {
  language reverse;
  strings aux_string;
  std::set<strings> strings_, copy_language = language_.get_Language();

  for (std::set<strings>::iterator it = copy_language.begin(); it != copy_language.end(); it++) {
    aux_string = *it;
    strings_.insert(aux_string.reverse());
  }

  reverse.set_Language(strings_);
  reverse.set_Alphabet(language_.get_Alphabet());
  return reverse;
}

language operator*(const language& language_, int exponent) {
  language pow;
  if (exponent == 0) {
    std::set<strings> empty_string;

    empty_string.insert(strings("&"));
    pow.set_Language(empty_string);
    return pow;
  }
  std::set<strings> aux_string = language_.get_Language(), pow_acum;
  for (int i = 1; i < exponent; i++) {
    for (std::set<strings>::iterator it1 = aux_string.begin(); it1 != aux_string.end(); it1++) {
      for (std::set<strings>::iterator it2 = aux_string.begin(); it2 != aux_string.end(); it2++) {
        if (*it1 == strings("&")) {
          pow_acum.insert(*it2);
        } else if (*it2 == strings("&")) {
          pow_acum.insert(*it1);
        } else {
          pow_acum.insert(*it1 + *it2);
        }
      }
    }
    aux_string = pow_acum;
    pow_acum.clear();
  }
  pow.set_Language(aux_string);
  pow.set_Alphabet(language_.get_Alphabet());
  return pow;
}

std::ostream& operator<<(std::ostream& os, const language& language_) {
  std::set<strings> strings_ = language_.get_Language();
  os << " Alfabeto: { ";
  std::set<symbol> aux = language_.get_Alphabet().get_alphabet();
  for (std::set<symbol>::iterator it = aux.begin(); it != aux.end(); it++) {
    os << *it << " ";
  }

  os << "} Lenguaje: { ";
  for (std::set<strings>::iterator it = strings_.begin(); it != strings_.end(); it++) {
    os << *it << " ";
  }
  
  os << "}";
  return os;
}
