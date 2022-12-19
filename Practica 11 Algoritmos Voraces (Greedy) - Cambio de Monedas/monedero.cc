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
  monedas_ = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  billetes_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.50,  0.20,  0.10, 0.05, 0.02, 0.01};
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
void Monedero::CambioMonedas(double n) {
  for (double i = 0; i < monedas_.size(); i++) {
    while (suma_ + monedas_[i] <= n) {
      suma_ += monedas_[i];
      solucion_.push_back(monedas_[i]);
    }
  }
  std::cout << "Suma: " << suma_ << std::endl;
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

/**
 * @brief Método del nuevo algoritmo más eficiente para calcular el cambio de monedas
 * 
 * @param n 
 * @return std::vector<double> 
 */
std::vector<double> Monedero::AlgoritmoAlternativo(double n) {
  for (double i = 0; i < monedas_.size(); i++) {
    int c = floor(n / monedas_[i]);
    if (c > 0) {
      solucion_.insert(solucion_.end(), c, monedas_[i]);
      suma_ += c * monedas_[i];
      n -= c * monedas_[i];
    }
  }
  std::cout << "Suma algoritmo alternativo: " << suma_ << std::endl;
  return solucion_;
}

std::vector<double> Monedero::AlgoritmoAlternativoBilletes(double n) {
  std::cout << "Bosko" << std::endl;
  for (double i = 0; i < billetes_.size(); i++) {
    int c = floor(n / billetes_[i]);
    if (c > 0) {
      solucion_.insert(solucion_.end(), c, billetes_[i]);
      suma_ += c * billetes_[i];
      n -= c * billetes_[i];
    }
  }
  return solucion_;
}