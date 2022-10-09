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
#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Strings {
 private:
  // Atributos
  int opcode;
  std::vector<std::string> string_list;

 public:
  Strings() = default;  // Constructor
  Strings(std::string);
  ~Strings();           // Destructor

  // Setters
  void setOpcode(int);
  void setStringList(std::vector<std::string>);

  // Getters
  int getOpcode();
  std::vector<std::string> getStringList();

  // Metodos de la clase
  void saveStrings(std::string);
  Strings& operator=(const Strings& strings);
};

// Definicion de la sobrecarga de operadores
Strings operator+(Strings& strings1, Strings& strings2);
bool operator==(Strings& strings1, Strings& strings2);
bool operator==(Strings& strings1, std::string strings2);
