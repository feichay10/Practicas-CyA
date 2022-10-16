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

language::language() {
  tag_language = {};
  contain_language = {};
}

language::~language() {
  tag_language.clear();
  contain_language.clear();
}

void language::set_tag_language(std::string tag) {
  tag_language.push_back(tag);
}

void language::set_contain_language(std::string contain) {
  contain_language.push_back(contain);
}

std::string language::get_tag_language(int i) {
  return tag_language[i];
}

std::string language::get_contain_language(int i) {
  return contain_language[i];
}
