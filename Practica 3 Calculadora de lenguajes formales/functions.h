/**
 * @file functions.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-14
 *
 * @copyright Copyright (c) 2022
 *
 */


#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "language.h"

const char EQUAL = '=';
const char BEGIN_BRACE = '{';
const char END_BRACE = '}';

void CheckParameters(int num_parameters);
void ReadFile(std::string input, std::vector<std::string>& operations, std::vector<language>& languages, std::vector<std::string>& vec_tags);