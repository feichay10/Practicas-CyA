/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "chain.h"

const std::string kHelp =  "Modo de empleo: ./p01_strings [filein.txt] [fileout.txt] [opcode]\n"
    "Los Opcodes son:\n"
    "  1. Longitud\n"
    "  2. Inversa\n"
    "  3. Prefijos\n"
    "  4. Sufijos\n"
    "  5. Subcadenas\n";

const char SPACE = ' ';

bool check_parameters(int argc, char* argv[]);
std::vector<std::string> read_file(char* argv[]);
void write_file(std::string exit_file, std::string operation_chain);
std::pair<Chain, Alphabet> entry_with_alphabet(std::string& line);
Chain entry_without_alphabet(std::string& line);
void menu_operations(std::string exit_file, int opcode, Chain& chain);
void check_entry(std::vector<std::string>& entry, std::string exit_file, int opcode);

#endif  // FUNCTIONS_H_