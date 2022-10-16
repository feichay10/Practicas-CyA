/**
 * @file alphabet.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <set>
#include <string>

#include "symbol.h"

class alphabet {
 public:
  alphabet() = default;
  //~alphabet();

  void set_alphabet(symbol letter);

 private:
  std::set<symbol> alphabet_;
  
};
