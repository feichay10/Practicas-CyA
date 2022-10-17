/**
 * @file strings.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "strings.h"
#include "symbol.h"
#include <iostream>

strings::strings(std::string str) {
  strings_.clear();
  for (size_t i = 0; i < str.size(); i++) {
    strings_.emplace_back(symbol(str[i]));
  }
}

std::vector<symbol> strings::get_string() const {
  return strings_;
}

// Calcular la inversa de una cadena 
strings strings::reverse(){
  strings reverse;
  std::string str;
  for (int i = strings_.size() - 1; i > -1; i--) {
    str.push_back(strings_[i].getsymbol()[0]);
  }
  reverse = strings(str);
  return reverse;
}

// Este operador es para el insert del set, es para el language
bool operator<(const strings& strings1, const strings& strings2) {
  return (strings1.get_string() < strings2.get_string());
}

bool operator==(const strings& strings1, const strings& strings2) {
  if (strings1.get_string().size() != strings2.get_string().size()) {
    return false;
  } else {
    unsigned long int contador{0};
    for (size_t i = 0; i < strings1.get_string().size(); i++) {
      if (strings1.get_string()[i] == strings2.get_string()[i]) {
        ++contador;
      }
    }
    if (contador == strings1.get_string().size()) {
      return true;
    } else {
      return false;
    }
  }
}

std::ostream& operator<<(std::ostream& out, const strings& strings) {
  for (size_t i = 0; i < strings.get_string().size(); i++) {
    out << strings.get_string()[i].getsymbol();
  }
  return out;
}

// Concatenar dos cadenas 
strings operator+(const strings& strings1, const strings& strings2) {
  strings concatenation;
  std::string str;
  std::vector<symbol> aux1 = strings1.get_string(), aux2 = strings2.get_string();

  for (size_t i = 0; i < aux1.size(); i++) {
    str.push_back(aux1[i].getsymbol()[0]);
  }
  for (size_t i = 0; i < aux2.size(); i++) {
    str.push_back(aux2[i].getsymbol()[0]);
  }

  concatenation = strings(str);
  return concatenation;
}