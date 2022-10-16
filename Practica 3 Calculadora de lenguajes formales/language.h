/**
 * @file language.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-16
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
  std::set<strings> getLanguage() const;
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