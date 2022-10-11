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

void ReadFile(std::string input_1, std::string input_2, int option) {
  std::ifstream file_in_1, file_in_2;
  std::string lines, str;
  std::stringstream ss;
  std::vector<Alphabet> alpha1;
  std::vector<Alphabet> alpha2;
  std::vector<Language> language1;
  std::vector<Language> language2;

  if (option == 1 || option == 2 || option == 3 ||
      option == 4) {  // En caso de operaciones que hacen falta la entrada de
                      // dos ficheros
    file_in_1.open(input_1, std::ios::in);
    file_in_2.open(input_2, std::ios::in);

    if (file_in_1.fail() || file_in_2.fail()) {
      std::cout << "Ficheros de entrada no abiertos" << std::endl;
      exit(1);
    }

    IterateFile(file_in_1, file_in_2, strings1, alpha1, alpha2, language1,
                language2, option);

    file_in_1.close();
    file_in_2.close();
  } else if (option == 5 || option == 6) {
    file_in_1.open(input_1, std::ios::in);

    if (file_in_1.fail()) {
      std::cout << "Fichero de entrada filein1.txt no abierto" << std::endl;
      exit(1);
    }

    IterateFile(file_in_1, file_in_2, strings1, alpha1, alpha2, language1,
                language2, option);

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

void IterateFile(std::ifstream& file_in1, std::ifstream& file_in2,
                 Strings& string, std::vector<Alphabet>& alpha_list1,
                 std::vector<Alphabet>& alpha_list2,
                 std::vector<Language>& language_list1,
                 std::vector<Language>& language_list2, int option) {
  std::string lines1, lines2, str1, str2, result_operation;
  std::stringstream ss1, ss2;
  int count = 0;

  if (option == 1 || option == 2 || option == 3 || option == 4) {
    while (getline(file_in1, lines1)) {
      while (getline(file_in2, lines2)) {
        ss1.str(lines1);
        ss2.str(lines2);
        while ((ss1 >> str1) &&
               (ss2 >> str2)) {  // Cortamos la linea por palabra
          if ((str1 == BEGIN_BRACE || str1 == END_BRACE) &&
              (str2 == BEGIN_BRACE || str2 == END_BRACE)) {
            if ((str1 == END_BRACE) && (str2 == END_BRACE)) {
              count++;
              std::cout << "El contador: " << count << std::endl;
            }
          } else {
            if (count == 0) {
              std::cout << "El alfabeto1 : " << str1 << std::endl;
              alpha_list1.emplace_back(Alphabet(str1));

              std::cout << "El alfabeto2 : " << str2 << std::endl;
              alpha_list2.emplace_back(Alphabet(str2));
            } else if (count == 1) {
              std::cout << "La cadena1: " << str1 << std::endl;
              language_list1.emplace_back(Strings(str1));

              std::cout << "La cadena2 : " << str2 << std::endl;
              language_list2.emplace_back(Strings(str2));
            }
          }
          if (count == 2) {
            for (unsigned i = 0; i < language_list1.size(); i++) {
              std::cout << language_list1[i] << " ";
            }
            std::cout << std::endl;
            for (unsigned i = 0; i < language_list1.size(); i++) {
              std::cout << language_list2[i] << " ";
            }
            std::cout << std::endl;
            alpha_list1.clear();
            alpha_list2.clear();
            language_list1.clear();
            language_list2.clear();
            count = 0;
          }
        }
        ss1.clear();
        ss2.clear();
      }
    }
  } else if (option == 5 || option == 6) {
    while (getline(file_in1, lines1)) {
      ss1.str(lines1);
      while (ss1 >> str1) {  // Cortamos la linea por palabra
        if (str1 == BEGIN_BRACE || str1 == END_BRACE) {
          if (str1 == END_BRACE) {
            count++;
          }
        } else {
          if (count == 0) {
            std::cout << "El alfabeto: " << str1 << std::endl;
            alpha_list1.emplace_back(Alphabet(str1));
          } else if (count == 1) {
            std::cout << "El lenguaje: " << str1<< std::endl;
            language_list1.insert(Strings(str));
          }
        }
      //   if (count == 2) {
      //     for (unsigned i = 0; i < language_list1.size(); i++) {
      //       std::cout << language_list1[i] << " ";
      //     }
      //     std::cout << std::endl;
      //     //Menu(language_list1, option);
      //     alpha_list1.clear();
      //     language_list1.clear();
      //     count = 0;
      //   }
      // }
      count = 0;
      ss1.clear();
    }
  }
}

void Menu(std::vector<Language>& language_list1, int option) {
  switch (option) {
    case 1:
      // language.concatenation();
      // return result_operation;
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
      language.reverse();
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
}