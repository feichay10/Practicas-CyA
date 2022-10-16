/**
 * @file functions.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "functions.h"

void CheckParameters(int num_parameters) {
  if (num_parameters != 2) {
    if (num_parameters > 2) {
      std::cout << "Ha introducido mas parametros" << std::endl;
    } else {
      std::cout << "Ha introducido pocos parametros" << std::endl;
    }
    std::cout
        << "Error: Para ejecutar el programa use ./p03_calculator filein.txt"
        << std::endl;
    exit(EXIT_FAILURE);
  }
}

void ReadFile(std::string input) {
  std::ifstream file_in;
  std::string line, language_tag, language_contain;
  std::stringstream ss;
  int i = 0;
  language tag;


  file_in.open(input);
  if (file_in.is_open()) {
    while (getline(file_in, line, '\n')) {
      ss << line;
      while (getline(ss, language_tag, EQUAL)) {
        if (i == 0) {
          std::cout << "Tag: " << language_tag << std::endl;
          tag.set_contain_language(language_tag);
          i++;
        } else {
          UN DESCANSO
          language_contain = language_tag;
          std::cout << "Contenido: " << language_contain << std::endl;
          i = 0;
        }
      }
      ss.clear();
    }
  } else {
    std::cout << "Error: No se ha podido abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
}