/**
 * @file alphabet.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "alphabet.h"
#include "symbol.h"

void alphabet::set_alphabet(symbol letter) {
  alphabet_.insert(letter);
}

