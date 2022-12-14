/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy) - Cambio de Monedas
 * @file cambiomonedas.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Programa que calcula el cambio de monedas de una cantidad dada
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "monedero.h"

const std::string HELP = "--help";
const std::string BILLETES = "-b";

void check_parameters(int argc, char* argv[]);

int main(int argc, char* argv[]) {
  double n, aux;
  int count = 1;
  Monedero monedero;

  check_parameters(argc, argv);

  std::cout << "Introduzca la cantidad a cambiar: ";
  std::cin >> n;

  monedero.CambioMonedas(n);

  std::cout << "El cambio de monedas es: ";
  for (double i = 0; i < monedero.getSolucionSize(); i++) {
    std::cout << monedero.getSolucion()[i] << "€, ";
  }
  std::cout << std::endl;
  std::cout << "El cambio de moneda es: ";
  int j = 0;
  while (j < monedero.getSolucionSize()) {
    if (monedero.getSolucion()[j] == monedero.getSolucion()[j + 1]) {
      count++;

    } else {
      std::cout << count << "x" << monedero.getSolucion()[j] << "€, ";
      count = 1;
    }
    j++;
  }
}

void check_parameters(int argc, char* argv[]) {
  std::cout << "Entro a check" << std::endl;
}