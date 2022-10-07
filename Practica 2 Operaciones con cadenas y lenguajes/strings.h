/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes 
 * @file strings.h
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

class Strings {
 private:
  //Atributos
  int opcode;
  std::vector<std::string> string_list;

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
  //std::string Take
};

