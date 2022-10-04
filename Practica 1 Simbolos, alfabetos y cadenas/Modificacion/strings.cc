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

#include "strings.h"

Strings::~Strings() {}

void Strings::setString(std::vector<std::string> _StringList) {
  StringList = _StringList;
}

std::vector<std::string> Strings::getString() { return StringList; }

std::string Strings::length(std::string strings) {
  std::stringstream ss;
  std::string result_length;

  std::cout << "- Su longitud es: " << strings.size() << std::endl;

  ss << strings.size();  // convertir un int a stream
  ss >> result_length;   // convertir stream a string

  return result_length;
}

std::string Strings::reverse(std::string strings) {
  std::string aux_reverse = " ";

  for (int i = strings.size(); i >= 0; i--) {
    aux_reverse += strings[i];
  }

  std::cout << "- Su inversa es: " << aux_reverse << std::endl;

  return aux_reverse;
}

std::string Strings::prefixes(std::string strings) {
  std::string aux_prefixes = " ";
  std::string prefixes = " & ";
  std::vector<std::string> vector;

  std::cout << "- Prefijos: &";

  for (unsigned i = 0; i <= strings.size(); i++) {
    aux_prefixes += strings[i];
    std::cout << aux_prefixes;
    prefixes += aux_prefixes + " ";
  }
  std::cout << std::endl;
  return prefixes;
}

std::string Strings::suffixes(std::string strings) {
  std::string aux_suffixes = " ";
  std::string suffixes = " & ";

  std::cout << "- Sufijos: &";
  for (int i = strings.size(); i >= 0; i--) {
    aux_suffixes = strings[i] + aux_suffixes;
    std::cout << aux_suffixes;
    suffixes += aux_suffixes + " ";
  }
  std::cout << std::endl;
  return suffixes;
}

std::string Strings::substrings(std::string strings) {
  std::string substrings = " ";

  std::cout << "- Subcadenas: " << std::endl;

  for (unsigned i = 0; i < strings.size(); i++) {
    for (unsigned j = i; j < strings.size(); j++) {
      for (unsigned k = i; k <= j; k++) {
        std::cout << strings[k];
        substrings += strings[k];
      }
      substrings += "\n";
      std::cout << std::endl;
    }
  }
  return substrings;
}

// Modificacion: buscar el numero de simbolos diferentes en una cadena --> aba = 2/3, aaaa = 1/4 (numero simbolos diferentes/numero de simbolos de la cadena)
std::string Strings::simbolo(std::string strings) {
  std::string Alpha;
  std::stringstream ss;
  std::string result;
  int count = 0;

  for (unsigned i = 0; i < strings.length(); i++) {     // Recorro el string 
    std::size_t result = Alpha.find(strings[i]);        // Utilizo el metodo find() para buscar un simbolo
    if (result == std::string::npos) {                  // Comparo si el resultado cogido de find es igual al de npos
      Alpha += " ";
      Alpha += strings[i];
      count++;
    }
  }

  ss << count;   // convertir un int a stream
  ss >> result;  // convertir stream a string
  Alpha.erase();

  return result;
}