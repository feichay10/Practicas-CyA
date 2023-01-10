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

// clang-format -style=google -i *.h *.cc

#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "bigint.h"

const std::string HELP1 = "-h";
const std::string HELP2 = "--help";
const std::string KARATSUBA = "-k";
const std::string OPERATOR = "-m";
const std::string COTA = "-n";
const std::string RANDOM = "-r";

void check_parameters(int argc, char* argv[]);

int main(int argc, char* argv[]) {
  BigInt karatsubaOperation;
  long long result;
  std::string number1, number2, line;
  std::vector<std::string> aux;
  
  check_parameters(argc, argv);

  if(argc == 1 || argv[1] == KARATSUBA) {
    while(getline(std::cin, line)){
      aux.push_back(line);
    }

    std::cout << "Primer numero = " << aux[0] << std::endl;
    std::cout << "Segundo numero = " << aux[1] << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    result = karatsubaOperation.Karatsuba(std::stoi(aux[0]), std::stoi(aux[1]), 0);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "La solución de la operación con el algoritmo Karatsuba es: " << result << std::endl;
    std::cout << "El tiempo de ejecución del algoritmo de Karatsuba: " << time << " nanosegundos" << std::endl;
    exit(0);
  } else if (argv[1] == OPERATOR) {
    while(getline(std::cin, line)){
      aux.push_back(line);
    }

    std::cout << "Primer numero = " << aux[0] << std::endl;
    std::cout << "Segundo numero = " << aux[1] << std::endl;

    BigInt num1(std::stoi(aux[0])); 
    BigInt num2(std::stoi(aux[1]));
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "La solución de la operación con el operador * es: " << num1 * num2 << std::endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "El tiempo de ejecución del operador *: " << time << " nanosegundos" << std::endl;
    exit(0);
  } else if (argv[1] == COTA) {
    while(getline(std::cin, line)){
      aux.push_back(line);
    }

    std::cout << "Primer numero = " << aux[0] << std::endl;
    std::cout << "Segundo numero = " << aux[1] << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    result = karatsubaOperation.Karatsuba(std::stoi(aux[0]), std::stoi(aux[1]), std::stoi(argv[2]));
    auto t2 = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "La solución de la operación con el algoritmo Karatsuba es: " << result << std::endl;
    std::cout << "El tiempo de ejecución del algoritmo de Karatsuba: " << time << " nanosegundos" << std::endl;
    exit(0);
  } 
  
  if (argv[1] == RANDOM) {
    srand(time(NULL));
    int size = std::stoi(argv[2]);
    for (int i = 0; i < size; i++) {
      number1 += std::to_string(rand() % 10);
      number2 += std::to_string(rand() % 10);
    }
    aux.push_back(number1);
    aux.push_back(number2);

    std::cout << "Primer numero aleatorio generado = " << aux[0] << std::endl;
    std::cout << "Segundo numero aleatorio generado = " << aux[1] << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    result = karatsubaOperation.Karatsuba(std::stoi(aux[0]), std::stoi(aux[1]), 0);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "La solución de la operación con el algoritmo Karatsuba con numeros aleatorios es: " << result << std::endl;
    std::cout << "El tiempo de ejecución del algoritmo de Karatsuba: " << time << " nanosegundos" << std::endl;
    exit(0);
  }
  return 0;
}

void check_parameters(int argc, char* argv[]) {
  if (argc == 2) {
    std::string parameter = argv[1];
    if (parameter == HELP1 || parameter == HELP2) {
      std::cout << "Uso: " << argv[0] << " [OPCION]" << std::endl;
      std::cout << "OPCION:" << std::endl;
      std::cout << "  -h, --help\t\tAyuda del programa." << std::endl;
      std::cout << "  -k\t\t\tUsa el algoritmo Karatsuba." << std::endl;
      std::cout << "  -m\t\t\tUsa el operador * de la clase BigInt." << std::endl;
      exit(0);
    } 
    if (parameter != KARATSUBA && parameter != OPERATOR && parameter != COTA) {
      std::cout << "Error: argumento no válido. Use la opcion -h o --help para saber el funcionamiento del programa." << std::endl;
      exit(1);
    }
  } else if (argc == 4) {
    std::cout << "Error: demasiados argumentos. Use la opcion -h o --help para saber el funcionamiento del programa." << std::endl;
    exit(1);
  } else if (argc == 1) {
    std::cout << "Se usará el algoritmo Karatsuba por defecto." << std::endl;
  }
}