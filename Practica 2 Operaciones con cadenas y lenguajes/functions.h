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

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "language.h"
#include "strings.h"

#define CADENA_VACIA "&"

const std::string FILE_OUT = "fileout.txt";
const std::string BEGIN_BRACE = "{";
const std::string END_BRACE = "}";

void CheckParameters(int argc, char *argv[]);
void ReadFile(std::string, std::string, int);
void WriteFile(std::string, int);
void IterateFile(std::ifstream, std::vector<std::string>);
std::string Menu(int argc, char *argv[]);
