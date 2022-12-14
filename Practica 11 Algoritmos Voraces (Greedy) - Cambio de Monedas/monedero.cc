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

Monedero::Monedero() {
  monedas_ = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  billetes_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  solucion_ = {};
  suma_ = 0;
}

Monedero::~Monedero() {}

std::vector<double> Monedero::getSolucion() {
  return solucion_;
}

int Monedero::getSolucionSize() {
  return solucion_.size();
}

void Monedero::CambioMonedas(double n) {
  for (double i = 0; i < monedas_.size(); i++) {
    while (suma_ + monedas_[i] <= n) {
      suma_ += monedas_[i];
      solucion_.push_back(monedas_[i]);
    }
  }
  std::cout << "Suma: " << suma_ << std::endl;
}

void Monedero::CambioBilletes(double n) {
  for (double i = 0; i < billetes_.size(); i++) {
    while (suma_ + billetes_[i] <= n) {
      suma_ += billetes_[i];
      solucion_.push_back(billetes_[i]);
    }
  }
  std::cout << "Suma: " << suma_ << std::endl;
}