/**
 * @file language.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "language.h"
#include "strings.h"
#include "symbol.h"

language::language(std::set<strings> language) {
  language_ = language;
  
  for(std::set<strings>::iterator it = language_.begin(); it != language_.end(); ++it) {
    for (size_t i = 0; i < it->getstring().size(); i++) {
      alphabet_.set_alphabet(it->getstring()[i]);
    }
  }
}

std::set<strings> language::getLanguage() const {
  return language_;
}

language::~language() {}

language operator+(const language& language1, const language& language2) {
  language concatenados;
  std::set<strings> copia1 = language1.getLanguage(), copia2 = language2.getLanguage(), language;
  if (copia1.size() == 1) {
    for (std::set<strings>::iterator it{copia1.begin()}; it != copia1.end(); it++) {
      if (*it == strings("&")) {
        return language2;
      }
    }
  }
  if (copia2.size() == 1) {
    for (std::set<strings>::iterator it{copia2.begin()}; it != copia2.end(); it++) {
    if (*it == strings("&")) {
      return language1;
    }
  }
  }
  for (std::set<strings>::iterator it1{copia1.begin()}; it1 != copia1.end(); it1++) {
    for (std::set<strings>::iterator it2{copia2.begin()}; it2 != copia2.end(); it2++) {
      if (*it1 == strings("&")) {
          language.insert(*it2);
        } else if (*it2 == strings("&")) {
          language.insert(*it1);
        } else {
          language.insert(*it1 + *it2);
        }
    }
  }
  concatenados.setLanguage(language);
  concatenados.setAlfabeto(Union(language1, language2));
  return concatenados;
}

language operator|(const language& language1, const language& language2) {
  language lenguaje_union;
  std::set<strings> cadenas, copia1 = language1.getLanguage(), copia2 = language2.getLanguage();
  for (std::set<strings>::iterator it{copia1.begin()}; it != copia1.end(); it++) {
    cadenas.insert(*it);
  }
  for (std::set<strings>::iterator it{copia2.begin()}; it != copia2.end(); it++) {
    cadenas.insert(*it);
  }
  lenguaje_union.setLanguage(cadenas);
  lenguaje_union.setAlfabeto(Union(language1, language2));
  return lenguaje_union;
}

language operator^(const language& language1, const language& language2) {
  language intersection;
  std::set<strings> cadenas, copia1 = language1.getLanguage(), copia2 = language2.getLanguage();
  for (std::set<strings>::iterator it1{copia1.begin()}; it1 != copia1.end(); it1++) {
    for (std::set<strings>::iterator it2{copia2.begin()}; it2 != copia2.end(); it2++) {
      if (*it1 == *it2) {
        cadenas.insert(*it1);
      }
    }
  }
  intersection.setLanguage(cadenas);
  intersection.setAlfabeto(Intersection(language1, language2));
  return intersection;
}

language operator-(const language& language1, const language& language2) {
  size_t contador{0};
  language diferencia;
  std::set<strings> cadenas, copia1 = language1.getLanguage(), copia2 = language2.getLanguage();
  for (std::set<strings>::iterator it1{copia1.begin()}; it1 != copia1.end(); it1++) {
    for (std::set<strings>::iterator it2{copia2.begin()}; it2 != copia2.end(); it2++) {
      if (*it1 == *it2) {
        ++contador;
      }
    }
    if (contador < 1) {
      cadenas.insert(*it1);
    }
    contador = 0;
  }
  contador = 0;
  for (std::set<strings>::iterator it2{copia2.begin()}; it2 != copia2.end(); it2++) {
    for (std::set<strings>::iterator it1{copia1.begin()}; it1 != copia1.end(); it1++) {
      if (*it2 == *it1) {
        ++contador;
      }
    }
    if (contador < 1) {
      cadenas.insert(*it2);
    }
    contador = 0;
  }
  diferencia.setLanguage(cadenas);
  diferencia.setAlfabeto(Union(language1, language2));
  return diferencia;
}

language operator!(const language& language) {
  language invertido;
  strings copia_cadena;
  std::set<strings> cadenas, copia_lenguaje{language.getLanguage()};
  for (std::set<strings>::iterator it{copia_lenguaje.begin()}; it != copia_lenguaje.end(); it++) {
    copia_cadena = *it;
    cadenas.insert(copia_cadena.Inverted());
  }
  invertido.setLanguage(cadenas);
  invertido.setAlfabeto(language.getAlfabeto());
  return invertido;
}

language operator*(const language& language_, int exponent) {
  language potencia;
  if (exponent == 0) {
    std::set<strings> vacia;
    vacia.insert(strings("&"));
    potencia.setAlfabeto(language_.getAlfabeto());
    potencia.setLanguage(vacia);
    return potencia;
  }
  std::set<strings> cadena_copia = language_.getLanguage(), potencia_acum;
  for (int i{1}; i < exponent; i++) {
    for (std::set<strings>::iterator it1{cadena_copia.begin()}; it1 != cadena_copia.end(); it1++) {
      for (std::set<strings>::iterator it2{cadena_copia.begin()}; it2 != cadena_copia.end(); it2++) {
        if (*it1 == strings("&")) {
          potencia_acum.insert(*it2);
        } else if (*it2 == strings("&")) {
          potencia_acum.insert(*it1);
        } else {
          potencia_acum.insert(*it1 + *it2);
        }
      }
    }
    cadena_copia = potencia_acum;
    potencia_acum.clear();
  }
  potencia.setLanguage(cadena_copia);
  potencia.setAlfabeto(language_.getAlfabeto());
  return potencia;
}