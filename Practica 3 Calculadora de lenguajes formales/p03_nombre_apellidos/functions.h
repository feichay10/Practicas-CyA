/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 3: Calculadora de lenguajes formales
 * @file functions.h
 * @author Cheuk Kelly Ng Pante
 * @brief Declaracion de la clase functions
 * @version 0.1
 * @date 2022-10-18
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
#include <stack>

#include "language.h"

const char EQUAL = '=';
const char BEGIN_BRACE = '{';
const char END_BRACE = '}';

void CheckParameters(int num_parameters);
void ReadFile(std::string input, std::vector<std::string>& operations, std::vector<language>& languages, std::vector<std::string>& vec_tags);
void MenuOperations(std::vector<std::string>& operations, std::vector<language>& languages, std::vector<std::string>& vec_tags);