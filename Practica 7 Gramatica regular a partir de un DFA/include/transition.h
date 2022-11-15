/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file transition.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de la clase 'Transition'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Clase 'Transition' que representa una transición
 * 
 */
class Transition {
 public:
  Transition();
  Transition(std::string, std::string);

  void setSymbol(const std::string);
  void setStateTo(const std::string);
  void setPos(std::string);

  std::string getSymbol() const;
  std::string getStateTo() const;
  std::string getPos() const;

 private:
  std::string symbol_;
  std::string state_to_;
  std::string pos_;
};