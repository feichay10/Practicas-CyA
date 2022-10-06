/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Operaciones con cadenas y lenguajes
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "functions.h"

#define CADENA_VACIA "&"

const std::string FILE_OUT = "fileout.txt"; 

Alphabet _alpha;  // Creando objeto de la clase Alphabet
Strings _str;     // Creando objeto de la clase String

void CheckParameters(int argc, char* argv[]) {
  int opcode;

  if (argv[1] == FILE_OUT || argv[2] == FILE_OUT) {
    std::cout << "Introduzca en orden los parametros ./p02_languages "
                 "filein1.txt filein2.txt fileout.txt opcode"
              << std::endl;
    exit(1);
  }

  if (argc != 5) {
    if (argc < 5) {
      std::cout << "Error. Faltan argumentos ./p02_languages filein1.txt "
                   "filein2.txt fileout.txt opcode"
                << std::endl;
      exit(1);
    } else {
      std::cout << "Error. Demasiados argumentos ./p02_languages filein1.txt "
                   "filein2.txt fileout.txt opcode"
                << std::endl;
      exit(1);
    }
  } else {
    opcode = std::stoi(argv[4]);
    if (opcode < 1 || opcode > 6) {
      std::cout << "Opcode Erroneo, Opcode = [1 - 5]" << std::endl;
      exit(1);
    }
  }
}


void ReadFile(std::string Input1, std::string Input2, int option) {
  std::ifstream FileIn1, FileIn2;
  std::string lines, str, result_operation;
  std::stringstream ss;
  std::vector<std::string> list;

  FileIn1.open(Input1, std::ios::in);
  FileIn2.open(Input2, std::ios::in);

  if (FileIn1.fail() || FileIn2.fail()) {
    std::cout << "Ficheros de entrada no abiertos" << std::endl;
    exit(1);
  }

  while (getline(FileIn1, lines, '\n')) {
    ss.str(lines);
    while (ss >> str) {
      list.push_back(str);        // Cortamos la linea por palabras
      if (str == CADENA_VACIA) {  // Detectar un & en el fichero de entrada
        std::cout << "\nERROR. Ha introducido un & en el fichero de entrada."
                  << std::endl;
        // FileOut << "No se puede utilizar el & en esta calculadora" <<
        // std::endl;
        exit(1);
      }
    }

    for (unsigned i = 0; i < list.size(); i++) {
      if (list[i].length() > 1) {
        std::cout << "\nLa cadena es: " << list[i] << std::endl;
        _alpha.SearchAlphabet(list[i]);
        result_operation = Menu(list[i], option);
        // FileOut << result_operation << std::endl;
      }
    }

    list.clear();
    ss.clear();
  }

  FileIn1.close();
  FileIn2.close();
}

void WriteFile(std::string Output, int option) {
  std::ofstream FileOut;
  std::string result_operation;

  FileOut.open(Output, std::ios::out | std::ios::ate);

  if (FileOut.fail()) {
    std::cout << "Ficheros no abiertos" << std::endl;
    exit(1);
  }

  FileOut.close();
}

std::string Menu(std::string cadena, int _opcode) {
  std::string result_operation;
  int operation = int(_opcode);

  switch (operation) {
    case 1:
      
      return result_operation;
      break;
    case 2:

      return result_operation;
      break;
    case 3:

      return result_operation;
      break;
    case 4:

      return result_operation;
      break;
    case 5:

      return result_operation;
      break;
    default:
      break;
  }
  return result_operation;
}