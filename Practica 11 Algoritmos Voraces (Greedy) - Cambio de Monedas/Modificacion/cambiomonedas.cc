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
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>

#include "billetera.h"
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
  Billetera billetera;
  std::vector<double> resultado;

  check_parameters(argc, argv);

  if (argv[1] == BILLETES) {
    n = argv[1] == BILLETES ? std::stod(argv[2]) : std::stod(argv[1]);
  } else if (argv[1] == COMPLEJIDAD) {
    n = argv[1] == COMPLEJIDAD ? std::stod(argv[2]) : std::stod(argv[1]);
  } else {
    n = std::stod(argv[1]);
  }

  if (argc == 2) {
    monedero.CambioDinero(n);
    print_money(monedero);
    std::cout << "Total de monedas: " << monedero.getSolucionSize() << std::endl;
  } else if (argv[1] == BILLETES) {
    billetera.CambioDinero(n);
    print_money(billetera);
    std::cout << "Total de billetes o monedas: " << billetera.getSolucionSize() << std::endl;
    exit(0);
  } else if (argv[1] == COMPLEJIDAD) {
    monedero.AlgoritmoAlternativo(n);
    print_money(monedero);
    std::cout << "Total de monedas: " << monedero.getSolucionSize() << std::endl << std::endl;
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
  if (argc > 3 || argc == 1) {
    std::cout << "Error: Numero de parametros incorrecto" << std::endl;
    exit(1);
  } else if (argc == 2 && argv[1] == HELP) {
    std::cout << "Uso: ./cambiomonedas [OPCION] [DINERO]" << std::endl;
    std::cout << "OPCIONES:" << std::endl;
    std::cout << "-b\t\tCambio de billetes" << std::endl;
    std::cout << "-o\t\tComplejidad" << std::endl;
    std::cout << "--help\t\tAyuda" << std::endl;
    exit(0);
  } else if (argc == 3 && argv[1] != BILLETES && argv[1] != COMPLEJIDAD) {
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

  double mas_frecuente = 0;

  std::cout << "Solucion basica: ";
  for (int i = 0; i < monedero.getSolucionSize(); i++) {
    if (monedero.getSolucion()[i] == 0.5) {
      std::cout << "50¢";
    } else if (monedero.getSolucion()[i] == 0.2) {
      std::cout << "20¢";
    } else if (monedero.getSolucion()[i] == 0.1) {
      std::cout << "10¢";
    } else if (monedero.getSolucion()[i] == 0.05) {
      std::cout << "5¢";
    } else if (monedero.getSolucion()[i] == 0.02) {
      std::cout << "2¢";
    } else if (monedero.getSolucion()[i] == 0.01) {
      std::cout << "1¢";
    } else {
      std::cout << monedero.getSolucion()[i] << "€";
    }

    if (i == monedero.getSolucionSize() - 1) {
      print_comma = false;
    }

    if (print_comma) {
      std::cout << ", ";
    }
  }

  print_comma = true;

  std::cout << "\nSolucion elaborada: ";
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

  std::vector<double> aux_frecuentes;

  // MODIFICACION - Coger la moneda que sea mas frecuente
  for (int i = 0; i < monedero.getSolucionSize(); i++) {
    if (monedero.getSolucion()[i] == monedero.getSolucion()[i + 1]) {
      mas_frecuente = monedero.getSolucion()[i];
      aux_frecuentes.push_back(mas_frecuente); 
    }
    // Si hay mas de una moneda mas frecuente, coger la mas grande
    if (aux_frecuentes.size() > 1) {
      mas_frecuente = aux_frecuentes[0];
      for (double i = 0; i < aux_frecuentes.size(); i++) {
        if (aux_frecuentes[i] > mas_frecuente) {
          mas_frecuente = aux_frecuentes[i];
        }
      }
    }
  }

  std::cout << "\nMoneda mas frecuente: " << mas_frecuente << std::endl;
}