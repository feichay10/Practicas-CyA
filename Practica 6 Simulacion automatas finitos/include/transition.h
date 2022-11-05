/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file transition.h
 * @author Cheuk Kelly Ng Pante
 * @brief
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Transition {
 public:
  Transition();
  Transition(std::string, std::string);

  void SetSymbol(const std::string);
  void SetStateTo(const std::string);
  void SetPos(int);

  std::string GetSymbol() const;
  std::string GetStateTo() const;
  int GetPos() const;

 private:
  std::string symbol_;
  std::string state_to_;
  int pos_;
};