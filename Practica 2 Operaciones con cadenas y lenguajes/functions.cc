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

Alphabet alphabet;  // Creando objeto de la clase Alphabet
Strings strings1;   // Creando objeto de la clase Strings
Strings strings2;   // Creando objeto de la clase Strings
Language language;  // Creando objeto de la clase Language

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
      std::cout << "Opcode Erroneo, Opcode = [1 - 6]" << std::endl;
      exit(1);
    }
  }
}

void ReadFile(std::string input_1, std::string input_2, int option,
              std::vector<Alphabet>& alpha_list,
              std::vector<Strings>& string_list) {
  std::ifstream file_in_1, file_in_2;
  std::string lines, str;
  std::stringstream ss;

  if (option == 1 || option == 2 || option == 3 ||
      option == 4) {  // En caso de operaciones que hacen falta la entrada de
                      // dos ficheros
    file_in_1.open(input_1, std::ios::in);
    file_in_2.open(input_2, std::ios::in);

    if (file_in_1.fail() || file_in_2.fail()) {
      std::cout << "Ficheros de entrada no abiertos" << std::endl;
      exit(1);
    }

    IterateFile(file_in_1, strings1, alpha_list, string_list);
    std::cout << std::endl;
    // IterateFile(file_in_2, strings2, alpha_list, string_list);

    file_in_1.close();
    file_in_2.close();
  } else {
    file_in_1.open(input_1, std::ios::in);

    if (file_in_1.fail()) {
      std::cout << "Fichero de entrada filein1.txt no abierto" << std::endl;
      exit(1);
    }

    IterateFile(file_in_1, strings1, alpha_list, string_list);

    file_in_1.close();
  }

  ss.clear();
}

void WriteFile(std::string output, int option) {
  std::ofstream file_out;
  std::string result_operation;

  file_out.open(output, std::ios::out | std::ios::ate);

  if (file_out.fail()) {
    std::cout << "Ficheros no abiertos" << std::endl;
    exit(1);
  }

  file_out.close();
}

void IterateFile(std::ifstream& file_in, Strings& string,
                 std::vector<Alphabet>& alpha_list,
                 std::vector<Strings>& string_list) {
  std::string lines, str, result_operation;
  std::stringstream ss;
  int count = 0;

  while (getline(file_in, lines, '\n')) {
    ss.str(lines);
    while (ss >> str) {  // Cortamos la linea por palabras
      if (str == BEGIN_BRACE || str == END_BRACE) {
        if (str == END_BRACE) {
          std::cout << "El contador: " << count << std::endl;
          count++;
        }
        continue;
      } else {
        if (count == 0) {
          std::cout << "El alfabeto: " << str << std::endl;
          alpha_list.emplace_back(Alphabet(str));
        } else if (count == 1) {
          std::cout << "La cadena: " << str << std::endl;
          string_list.emplace_back(Strings(str));
          for (unsigned i = 0; i < string_list.size(); i++){
            std::cout << string_list[i] << " ";
          }
        } else if (count == 2) {
          alpha_list.clear();
          string_list.clear();
          count = 0;
        }
      }
    }
    ss.clear();
  }
}

std::string Menu(int argc, char* argv[]) {
  std::string result_operation;
  int operation = atoi(argv[4]);
  std::vector<Alphabet> alpha;
  std::vector<Strings> string;

  switch (operation) {
    case 1:
      ReadFile(argv[1], argv[2], operation, alpha, string);

      for (unsigned i = 0; i < (string.size() / 2); i++) {
        language.concatenation(string[i], string[i + 1]);
        std::cout << std::endl;
      }
      //  return result_operation;
      break;
    case 2:
      // language.l_union();
      // return result_operation;
      break;
    case 3:
      // language.intersection();
      // return result_operation;
      break;
    case 4:
      // language.difference();
      // return result_operation;
      break;
    case 5:
      std::cout << operation << std::endl;
      // ReadFile(argv[1], argv[2], operation);
      //  language.reverse(strings1);
      //   return result_operation;
      break;
    case 6:
      // language.pow();
      // return result_operation;
      break;
    default:
      std::cout << "Opcode Erroneo, Opcode = [1 - 6]" << std::endl;
      exit(1);
      break;
  }
  return result_operation;
}