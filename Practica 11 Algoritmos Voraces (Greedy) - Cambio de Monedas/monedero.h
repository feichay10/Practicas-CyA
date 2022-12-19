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
 * @brief Clase Monedero que contiene los métodos para calcular el cambio de monedas y billetes
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief Clase Monedero que contiene los métodos para calcular el cambio de monedas y billetes
 * 
 */
class Monedero {
 public:
  Monedero();
  ~Monedero();

  std::vector<double> getSolucion();
  int getSolucionSize();

  void CambioMonedas(double n);
  std::vector<double> AlgoritmoAlternativo(double n);
  void CambioBilletes(double n);
  std::vector<double> AlgoritmoAlternativoBilletes(double n);
  
 private:
  std::vector<double> monedas_;
  std::vector<double> billetes_;
  std::vector<double> solucion_;
  double suma_;
};