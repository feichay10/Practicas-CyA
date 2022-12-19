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
const std::string COMPLEJIDAD = "-o";

void check_parameters(int argc, char* argv[]);
void print_money(Monedero&);

/**
 * @brief Funcion main que eiecuta el programa principal del cambio de monedas
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[]) {
  double n;
  Monedero monedero;

  check_parameters(argc, argv);

  std::cout << "Introduzca la cantidad a cambiar: ";
  std::cin >> n;

  if (argc == 1) {
    monedero.CambioMonedas(n);
    print_money(monedero);
    std::cout << "\nTotal de monedas: " << monedero.getSolucionSize() << std::endl;
  } else if (argv[1] == BILLETES) {
    monedero.CambioBilletes(n);
    print_money(monedero);
    std::cout << "\nTotal de billetes o monedas: " << monedero.getSolucionSize() << std::endl;
    exit(0);
  }
}

/**
 * @brief Funcion que comprueba los parametro de entrada
 * 
 * @param argc 
 * @param argv 
 */
void check_parameters(int argc, char* argv[]) {
  if (argc > 2) {
    std::cout << "Error: Numero de parametros incorrecto" << std::endl;
    exit(1);
  } else if (argc == 2 && argv[1] == HELP) {
    std::cout << "Uso: ./cambiomonedas [OPCION]" << std::endl;
    std::cout << "OPCIONES:" << std::endl;
    std::cout << "-b\t\tCambio de billetes" << std::endl;
    std::cout << "-o\t\tComplejidad" << std::endl;
    std::cout << "--help\t\tAyuda" << std::endl;
    exit(0);
  } else if (argc == 2 && argv[1] != BILLETES && argv[1] != COMPLEJIDAD) {
    std::cout << "Error: Parametro incorrecto" << std::endl;
    exit(1);
  }
}

/**
 * @brief Funcion que imprime el cambio de monedas
 * 
 * @param monedero 
 */
void print_money(Monedero& monedero) {
  int count = 1;
  int i = 0;
  bool print_comma = true;

  std::cout << "Solucion: ";
  while (i < monedero.getSolucionSize()) {
    if (monedero.getSolucion()[i] == monedero.getSolucion()[i + 1]) {
      count++;
    } else {
      if (monedero.getSolucion()[i] == 0.5) {
        std::cout << count << "x" << "50¢";
      } else if (monedero.getSolucion()[i] == 0.2) {
        std::cout << count << "x" << "20¢";
      } else if (monedero.getSolucion()[i] == 0.1) {
        std::cout << count << "x" << "10¢";
      } else if (monedero.getSolucion()[i] == 0.05) {
        std::cout << count << "x" << "5¢";
      } else if (monedero.getSolucion()[i] == 0.02) {
        std::cout << count << "x" << "2¢";
      } else if (monedero.getSolucion()[i] == 0.01) {
        std::cout << count << "x" << "1¢";
      } else {
        std::cout << count << "x" << monedero.getSolucion()[i] << "€";
      }
      count = 1;

      if (i == monedero.getSolucionSize() - 1) {
        print_comma = false;
      }

      if (print_comma) {
        std::cout << ", ";
      }
    }
    i++;
  }
}