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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class String;

class Alphabet {
 private:
  std::vector<std::string> AlphaList;

 public:
  Alphabet() = default;   // Constructor
  ~Alphabet();            // Destructor

  // Setters (establecer a los atributos)
  void setAlphabet(std::vector<std::string>);

  // Getter (mostrar los atributos)
  std::vector<std::string> getAlphabet();

  void SearchAlphabet(std::string Strings_);
}; 