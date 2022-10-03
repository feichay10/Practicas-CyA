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
#include <vector>

class Strings {
 private:
  //Atributos
  int opcode;
  std::vector<std::string> StringList;

 public:
  Strings() = default;   // Constructor
  ~Strings();  // Destructor

  // Setters
  void SetOpcode(int);  
  void SetString(std::vector<std::string>);

  // Getters
  int GetOpcode();
  std::vector<std::string> GetString();   

  //Metodos de la clase
  void ShowStrings(std::vector<std::string>);

  std::string length(std::string);
  std::string reverse(std::string);
  std::string prefixes(std::string);
  std::string suffixes(std::string);
  std::string substrings(std::string);
};

