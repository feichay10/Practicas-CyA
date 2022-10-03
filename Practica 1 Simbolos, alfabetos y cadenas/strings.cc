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

#include "strings.h"

Strings::~Strings() {}

void Strings::SetOpcode(int _opcode) { opcode = _opcode; }

void Strings::SetString(std::vector<std::string> _StringList) {
  StringList = _StringList;
}

int Strings::GetOpcode() { return opcode; }

std::vector<std::string> Strings::GetString() { return StringList; }

std::string Strings::longitud(std::string strings) {
  std::stringstream ss;
  std::string resultado_longitud;

  std::cout << "\nLa cadena es: " << strings << std::endl;
  //std::cout << "Su longitud es: " << strings.size() << std::endl;

  ss << strings.size();      // convertir un int a stream
  ss >> resultado_longitud;  // convertir stream a string

  return resultado_longitud;
}

std::string Strings::inversa(std::string strings) {
  std::string aux_inversa = " ";

  for (int i = strings.size(); i >= 0; i--) {
    aux_inversa += strings[i];
  }

  std::cout << "\nInversa: " << aux_inversa << std::endl;

  return aux_inversa;
}

std::string Strings::prefijos(std::string strings) {
  std::string aux_prefijo = " ";
  std::string prefijos = " & ";
  std::vector<std::string> vector;

  std::cout << "\nPrefijos: ";

  for (unsigned i = 0; i <= strings.size(); i++) {
    aux_prefijo += strings[i];
    std::cout << aux_prefijo << " ";
    prefijos += aux_prefijo + " ";
  }
  return prefijos;
}

std::string Strings::sufijos(std::string strings) {
  std::string aux_sufijo = " ";
  std::string sufijos = " & ";

  std::cout << "\nSufijos: ";
  for (int i = strings.size(); i >= 0; i--) {
    aux_sufijo = strings[i] + aux_sufijo;
    std::cout << aux_sufijo << " ";
    sufijos += aux_sufijo + " ";
  }
  return sufijos;
}

std::string Strings::subcadenas(std::string strings) {
  std::string subcadenas = " ";

  std::cout << "\nSubcadenas: " << std::endl;

  for (unsigned i = 0; i < strings.size(); i++) {
    for (unsigned j = i; j < strings.size(); j++) {
      for (unsigned k = i; k <= j; k++) {
        std::cout << strings[k];
        subcadenas += strings[k];
      }
      subcadenas += "\n";
      std::cout << std::endl;
    }
  }
  return subcadenas;
}