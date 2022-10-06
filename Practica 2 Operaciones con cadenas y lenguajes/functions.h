/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes 
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.2
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "alphabet.h"
#include "strings.h"

void CheckParameters(int argc_, char *argv[]);
std::string Menu(int argc_, char *argv[]);
void ReadFile(std::string, std::string, int);
void WriteFile(std::string, int);