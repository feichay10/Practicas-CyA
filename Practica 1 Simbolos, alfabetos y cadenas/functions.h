// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Cheuk Kelly Ng Pante
// Correo: alu0101364544@ull.es
// Fecha: 04/10/2022
// Archivo p01_strings.cc: programa cliente.
//          Contiene la función main del proyecto que usa las clases X e Y
//          que realizan el trabajo de leer el fichero de entrada
//          identificando patrones en el texto que dan lugar
//          al fichero de salida.
// Referencias:
//          https://stackoverflow.com/questions/29441675/splitting-strings-separately-by-line-and-by-blank-space-using-getline
//          http://www.cplusplus.com/forum/general/25076/
//
// Historial de revisiones
//          04/10/2022 - Creación (primera versión) del código

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//#include "symbol.h"
#include "alphabet.h"
#include "strings.h"

void CheckParameters(int argc, char *argv[]);
std::string Menu(std::string string_, int opcode);
void ReadWriteFile(std::string FileIn, std::string FileOut, int option);