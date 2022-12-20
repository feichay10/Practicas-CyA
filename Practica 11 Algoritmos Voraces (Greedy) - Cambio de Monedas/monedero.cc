/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy) - Cambio de Monedas
 * @file monedero.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los métodos de la clase Monedero
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "monedero.h"

/**
 * @brief Constructor de la clase Monedero que inicializa los atributos de la
 * clase
 *
 */
Monedero::Monedero() {
  dinero_ = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  solucion_ = {};
  suma_ = 0;
}

/**
 * @brief Método que asigna un valor al vector solucion_
 *
 * @param monedas
 */
std::vector<double> Monedero::getSolucion() { return solucion_; }

/**
 * @brief Método que asigna el tamaño del vector solucion_
 *
 * @return int
 */
int Monedero::getSolucionSize() { return solucion_.size(); }

/**
 * @brief Algoritmo voraz para calcular el cambio de monedas
 *
 * @param n
 */
void Monedero::CambioDinero(double n) {
  std::cout << "Algoritmo voraz original" << std::endl;
  for (double i = 0; i < dinero_.size(); i++) {
    while (suma_ + dinero_[i] <= n) {
      suma_ += dinero_[i];
      solucion_.push_back(dinero_[i]);
    }
  }
}

/**
 * @brief Método del nuevo algoritmo más eficiente para calcular el cambio de monedas
 * 
 * @param n 
 * @return std::vector<double> 
 */
std::vector<double> Monedero::AlgoritmoAlternativo(double n) {
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