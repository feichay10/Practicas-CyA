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

#include "language.h"
#include "strings.h"
#include "symbol.h"

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

void ReadFile(std::string input, std::vector<std::string>& operations, std::vector<language>& languages, std::vector<std::string>& vec_tags) {
  std::ifstream file_in;
  std::string line, entry, copy;
  std::stringstream ss;
  std::set<strings> language_set;
  file_in.open(input);
  if (file_in.is_open()) {
    while (getline(file_in, line)) {
      ss << line;  // Separar LX del = al lenguage {a,b}
      while (getline(ss, entry, EQUAL)) {
        if (entry[0] != ' ') {
          if (entry[entry.size() - 1] == ' ') {
            for (size_t i = 0; i < entry.size(); i++) {
              if (entry[i] != ' ') {
                copy.push_back(entry[i]);
              }
            }
            vec_tags.push_back(copy);
            copy.clear();
          } else {
            operations.emplace_back(entry);
          }
        } else {
          int i = 2;
          copy.clear();
          while (entry[i] != END_BRACE) {
            if ((entry[i] != ',') && (entry[i] != ' ')) {
              copy.push_back(entry[i]);
            } else {
              if (copy != "") {
                language_set.emplace(copy);
                copy.clear();
              }
            }
            ++i;
          }
          if (copy != "") {
            language_set.insert(strings(copy));  // Insertar el ultimo elemento
            copy.clear();
          }
        }
      }
      languages.emplace_back(language(language_set));
      language_set.clear();
      ss.clear();
    }
    for (size_t i = 0; i < vec_tags.size(); i++) {
      std::cout << "Tag: " << vec_tags[i] << std::endl;
    }
    for (size_t i = 0; i < operations.size(); i++) {
      std::cout << "Operacion: " << operations[i] << std::endl;
    }
    for (size_t i = 0; i < languages.size(); i++) {
      std::set<strings> copia = languages[i].getLanguage();
      for (auto it = copia.begin(); it != copia.end(); ++it) {
        std::cout << "Lenguaje " << i + 1 << ": " << *it << std::endl;
      }
    }
  } else {
    std::cout << "Error: No se ha podido abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
}

void menuOperations() {
  
}