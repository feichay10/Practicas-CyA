/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file symbol.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <string>

class Symbol {
 public:
  Symbol();
  Symbol(std::string symbol);

  void SetSymbol(std::string);
  std::string GetSymbol();
  unsigned GetSize();

 private:
  std::string symbol_;
};