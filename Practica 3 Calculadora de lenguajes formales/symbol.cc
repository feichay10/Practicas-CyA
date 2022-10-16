/**
 * @file symbol.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "symbol.h"

symbol::symbol(char symbol) {
  symbol_.clear();
  symbol_.push_back(symbol);
}

bool symbol::operator<(const symbol& symbol) {
  return (symbol_.size() < symbol.getsymbol().size());
}

std::string symbol::getsymbol() const {
  return symbol_;
}

bool operator<(const symbol& symbol1, const symbol& symbol2) {
  return (symbol1.getsymbol() < symbol2.getsymbol());
}

bool operator==(const symbol& symbol1, const symbol& symbol2) {
  return (symbol1.getsymbol()[0] == symbol2.getsymbol()[0]);
}

std::ostream& operator<<(std::ostream& out, const symbol& symbol) {
  out << symbol.getsymbol()[0];
  return out;
}