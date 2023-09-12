/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
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

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "chain.h"
#include "language.h"

const std::string kHelp =  "Modo de empleo: ./p02_languages [filein1.txt] [filein2.txt] [fileout.txt] [opcode].\n"
    "En caso de usar los opcode 5 o 6, solo se necesita un fichero de entrada, el modo de empleo sería: ./p02_languages [filein.txt] [fileout.txt] [opcode]\n"
    "Los Opcodes son:\n"
    "  1. Concatenación\n"
    "  2. Unión\n"
    "  3. Intersección\n"
    "  4. Diferencia\n"
    "  5. Inversa\n"
    "  6. Potencia\n"
    "\nLa entrada de los ficheros deben seguir el siguiente formato, aqui un ejemplo:\n"
    "{ a b c } { a abc cab bbcc }"
    "\n{ a } { a aa aaa }"
    "\n{ a b } { }\n"
    "\nEn cada línea encontraremos la especificación de un lenguaje: primero el alfabeto y luego "
    "el conjunto de cadenas que conforman el lenguaje. Esto es, cada línea del fichero de entrada "
    "contiene, entre llaves, los símbolos que conforman un alfabeto y, a continuación, y también "
    "entre llaves, las cadenas que conforman un lenguaje.\n";

const std::string HELP = "--help";
const std::string HELP_SHORT = "-h";
const char SPACE = ' ';
const char BEGIN_BRACE = '{';
const char END_BRACE = '}';

bool check_parameters(int argc, char* argv[]);
std::vector<std::string> read_file(std::string file_in);
void write_file(std::string exit_file, std::string operation_chain);
Language get_alphabet_language(std::string entry_language);
void menu_operations(std::string exit_file, int opcode, std::vector<Language> languages_1, std::vector<Language> languages_2);
std::vector<Language> extract_entry(std::vector<std::string> entry);

#endif  // FUNCTIONS_H_