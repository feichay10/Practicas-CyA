/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file dfa.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once  

#include <iostream>
#include <vector>
#include <fstream>

#include "../include/state.h"
#include "../include/alphabet.h"

class Dfa{
  public: 
    Dfa(std::ifstream &);
  private:
};