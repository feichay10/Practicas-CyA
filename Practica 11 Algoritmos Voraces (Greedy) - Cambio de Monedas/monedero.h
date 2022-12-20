/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy) - Cambio de Monedas
 * @file monedero.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Clase Monedero que contiene los métodos para calcular el cambio de
 * monedas y billetes
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <cmath>
#include <iostream>
#include <vector>

/**
 * @brief Clase Monedero que contiene los métodos para calcular el cambio de
 * monedas y billetes
 *
 */
class Monedero {
 public:
  Monedero();

  std::vector<double> getSolucion();
  int getSolucionSize();

  void CambioDinero(double n);
  void AlgoritmoAlternativo(double n);

 protected:
  std::vector<double> dinero_;
  std::vector<double> solucion_;
  double suma_;
};