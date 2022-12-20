/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy) - Cambio de Monedas
 * @file prueba.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Programa para comprobar que el algoritmo voraz alternativo es más eficiente que el original
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */


#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>

void AlgoritmoVoraz(double n) {
  std::vector<double> dinero_ = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  std::vector<double> solucion_;
  double suma_ = 0;
  std::cout << "Algoritmo voraz original" << std::endl;

  for (double i = 0; i < dinero_.size(); i++) {
    while (suma_ + dinero_[i] <= n) {
      suma_ += dinero_[i];
      solucion_.push_back(dinero_[i]);
    }
  }
  std::cout << std::endl;
}

std::vector<double> AlgoritmoAlternativo(double n) {
  std::vector<double> dinero_ = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  std::vector<double> solucion_;
  double suma_ = 0;
  std::cout << "Algoritmo voraz alternativo" << std::endl;
  for (double i = 0; i < dinero_.size(); i++) {
    int c = floor(n / dinero_[i]);
    if (c > 0) {
      solucion_.insert(solucion_.end(), c, dinero_[i]);
      suma_ += c * dinero_[i];
      n -= c * dinero_[i];
    }
  }
  return solucion_;
}

int main() {
  double n = 234.56;

  clock_t t1 = clock();
  AlgoritmoVoraz(n);
  clock_t t2 = clock();

  double tiempo1 = double(t2 - t1) / CLOCKS_PER_SEC;

  t1 = clock();
  AlgoritmoAlternativo(n);
  t2 = clock();
  double tiempo2 = double(t2 - t1) / CLOCKS_PER_SEC;

  std::cout << "Tiempo del algoritmo voraz original: " << tiempo1 << std::endl;
  std::cout << "Tiempo del algoritmo voraz alternativo: " << tiempo2 << std::endl;

  return 0;
}