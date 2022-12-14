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
 * @brief
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <list>
#include <vector>

class Monedero {
 public:
  Monedero();
  ~Monedero();

  void setMonedas(std::vector<double> monedas);
  void setSolucion(std::vector<double> solucion);
  void setSuma(double suma);

  std::vector<double> getMonedas();
  std::vector<double> getSolucion();
  double getSuma();
  int getSolucionSize();

  void CambioMonedas(double n);
  void CambioBilletes(double n);
  
 private:
  std::vector<double> monedas_;
  std::vector<double> billetes_;
  std::vector<double> solucion_;
  double suma_;
};