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
 * @brief 
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "monedero.h"

/**
 * @brief Constructor de la clase Monedero que inicializa los atributos de la clase
 * 
 */
Monedero::Monedero() {
  monedas_ = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  billetes_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  solucion_ = {};
  suma_ = 0;
}

/**
 * @brief Destructor de la clase Monedero
 * 
 */
Monedero::~Monedero() {}

/**
 * @brief Método que asigna un valor al vector solucion_
 * 
 * @param monedas 
 */
std::vector<double> Monedero::getSolucion() {
  return solucion_;
}

/**
 * @brief Método que asigna el tamaño del vector solucion_ 
 * 
 * @return int 
 */
int Monedero::getSolucionSize() {
  return solucion_.size();
}

/**
 * @brief Algoritmo voraz para calcular el cambio de monedas
 * 
 * @param n 
 */
void Monedero::CambioMonedas(double n) {
  for (double i = 0; i < monedas_.size(); i++) {
    while (suma_ + monedas_[i] <= n) {
      suma_ += monedas_[i];
      solucion_.push_back(monedas_[i]);
    }
  }
}

/**
 * @brief Algoritmo voraz para calcular el cambio de billetes y monedas
 * 
 * @param n 
 */
void Monedero::CambioBilletes(double n) {
  for (double i = 0; i < billetes_.size(); i++) {
    while (suma_ + billetes_[i] <= n) {
      suma_ += billetes_[i];
      solucion_.push_back(billetes_[i]);
    }
  }
}