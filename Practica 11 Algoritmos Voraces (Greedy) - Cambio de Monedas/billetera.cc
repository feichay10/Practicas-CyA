/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy) - Cambio de Monedas
 * @file billetera.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Clase Monedero que contiene los métodos para calcular el cambio de
 * monedas y billetes
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "billetera.h"

/**
 * @brief Constructor de la clase Billetera que inicializa el vector dinero_
 * 
 */
Billetera::Billetera() {
  dinero_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
}