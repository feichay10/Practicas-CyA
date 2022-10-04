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
//          https://www.geeksforgeeks.org/string-at-in-cpp/
//
// Historial de revisiones
//          04/10/2022 - Creación (primera versión) del código

#include "alphabet.h"

#include "string.h"

Alphabet::~Alphabet() {}

// Setters
void Alphabet::SetAlphabet(std::vector<std::string> _AlphaList) {
  AlphaList = _AlphaList;
}

// Getters
std::vector<std::string> Alphabet::GetAlphabet() { return AlphaList; }

void Alphabet::SearchAlphabet(std::string String) {
  std::string Alpha;

  for (unsigned i = 0; i <= String.length(); i++) {
    std::size_t result = Alpha.find(String[i]);
    if (result == std::string::npos) {
      Alpha += " ";
      Alpha += String[i];
    }
  }
  std::cout << "El alfabeto de la cadena \"" << String << "\" es: ";
  std::cout << Alpha << " " << std::endl;
}