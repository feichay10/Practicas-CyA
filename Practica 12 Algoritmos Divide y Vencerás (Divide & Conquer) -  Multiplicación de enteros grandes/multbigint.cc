/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: Algoritmos Divide y Vencerás (Divide & Conquer) - Multiplicación
 * de enteros grandes
 * @file multbigint.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "bigint.h"

const std::string HELP = "--help";

void check_parameters(int argc, char* argv[]);

int main(int argc, char* argv[]) {
  std::ifstream file_1, file_2;

  check_parameters(argc, argv);
  
  file_1.open(argv[1]);
  file_2.open(argv[2]);

  if (!file_1.is_open() || !file_2.is_open()) {
    std::cout << "Error: No se ha podido abrir el fichero" << std::endl;
    exit(1);
  }

  std::string line_1, line_2;
  while (getline(file_1, line_1) && getline(file_2, line_2)) {
    BigInt x(line_1);
    BigInt y(line_2);
    BigInt z = x * y;
    std::cout << x << " * " << y << " = " << z << std::endl;
  }
}

void check_parameters(int argc, char* argv[]) {
  if (argc > 3 || argc == 1) {
    std::cout << "Error: Numero de parametros incorrecto" << std::endl;
    exit(1);
  } else if (argc == 2 && argv[1] == HELP) {
    std::cout << "Uso: ./multbigint [OPCION]" << std::endl;
    std::cout << "OPCIONES:" << std::endl;
    std::cout << "--help\t\tAyuda" << std::endl;
    std::cout << "-k\t\tAlgoritmo Karatsuba" << std::endl;
    std::cout << "-m\t\tOperador * de la clase BigInt" << std::endl;
    std::cout << "-n <cota>\t\t Cota es el valor de la cota del cambio"
              << std::endl;
    std::cout << "-r <digitos>\t\tGeneracion aleatoria de los numeros 'x' e "
                 "'y' enteros a multiplicar. Además, <digitos> es el numero de "
                 "digitos que tiene que tener cada numero"
              << std::endl;
    exit(0);
  }
}