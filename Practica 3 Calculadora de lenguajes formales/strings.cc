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

strings::strings(std::string str) {
  strings_.clear();
  for (size_t i = 0; i < str.size(); i++) {
    strings_.emplace_back(symbol(str[i]));
  }
}

std::vector<symbol> strings::getstring() const {
  return strings_;
}

bool operator<(const strings& strings1, const strings& strings2) {
  return (strings1.getstring() < strings2.getstring());
}

bool operator==(const strings& strings1, const strings& strings2) {
  if (strings1.getstring().size() != strings2.getstring().size()) {
    return false;
  } else {
    unsigned long int contador{0};
    for (size_t i{0}; i < strings1.getstring().size(); i++) {
      if (strings1.getstring()[i] == strings2.getstring()[i]) {
        ++contador;
      }
    }
    if (contador == strings1.getstring().size()) {
      return true;
    } else {
      return false;
    }
  }
}

std::ostream& operator<<(std::ostream& out, const strings& strings) {
  for (size_t i = 0; i < strings.getstring().size(); i++) {
    out << strings.getstring()[i].getsymbol();
  }
  return out;
}