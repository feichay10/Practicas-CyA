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

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "functions.h"

int main(int argc, char *argv[]) {
  CheckParameters(argc, argv);

  int option = atoi(argv[3]);

  ReadWriteFile(argv[1], argv[2], option);  //./p01_strings filein.txt fileout.txt 1
}
