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
        if (entry[0] != ' ') {                          // LX' ' = ' ' {a,b}
          if (entry[entry.size() - 1] == ' ') {         // entry[entry.size() - 1] --> si el ultimo elemento del LX' ' es un espacio, es una etiqueta
            for (size_t i = 0; i < entry.size(); i++) { // Hasta que no encuentre ese espacio voy almacenando todas las etiquetas
              if (entry[i] != ' ') {
                copy.push_back(entry[i]);               // Meto en un string "copy" L, 1, L, 2, ...
              }
            }
            vec_tags.push_back(copy);                   // Directamente seria la etiqueta L1, L2, L3, ...
            copy.clear();                               
          } else {
            operations.emplace_back(entry);             // Almacena las operaciones
          }
        } else {
          int i = 2;                                    // El i + 2 es para avanzar el ' ' y el { 
          copy.clear();                                 // Para que no se junte con las etiquetas elimino el contenido de copy
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
  } else {
    std::cout << "Error: No se ha podido abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
}

void MenuOperations(std::vector<std::string>& operations,
                    std::vector<language>& languages,
                    std::vector<std::string>& vec_tags) {
  std::string aux_separation;
  std::vector<std::string> separation_operation;

  std::stack<language> stack_language;

  for (size_t i = 0; i < operations.size(); i++) {
    for (size_t j = 0; j < operations[i].size(); j++) {
      while (operations[i][j] != ' ') {
        aux_separation.push_back(operations[i][j]);
        j++;
      }
      if (aux_separation.size() > 2) {  // Me metia caracteres basura e hice esto
        std::string copy;
        copy.push_back(aux_separation[0]);
        separation_operation.emplace_back(copy);
        copy.clear();
        aux_separation.clear();
      } else {
        separation_operation.emplace_back(aux_separation);
        aux_separation.clear();
      }
    }
    for (size_t j = 0; j < separation_operation.size(); j++) {
      if ((separation_operation[j] == "+") || (separation_operation[j] == "|") || (separation_operation[j] == "^") || (separation_operation[j] == "-") || (separation_operation[j] == "!") || (separation_operation[j] == "*")){
        language aux_language1, aux_language2;
        switch(separation_operation[j][0]){
          case '+':
            aux_language2 = stack_language.top();
            stack_language.pop();
            aux_language1 = stack_language.top();
            stack_language.pop();
            stack_language.push(aux_language1 + aux_language2);
            break;
          case '|':
            aux_language2 = stack_language.top();
            stack_language.pop();
            aux_language1 = stack_language.top();
            stack_language.pop();
            stack_language.push(aux_language1 | aux_language2);
            break;
          case '^':
            aux_language2 = stack_language.top();
            stack_language.pop();
            aux_language1 = stack_language.top();
            stack_language.pop();
            stack_language.push(aux_language1 ^ aux_language2);
            break;
          case '-':
            aux_language2 = stack_language.top();
            stack_language.pop();
            aux_language1 = stack_language.top();
            stack_language.pop();
            stack_language.push(aux_language1 - aux_language2);
            break;
          case '!':
            aux_language1 = stack_language.top();
            stack_language.pop();
            stack_language.push(!aux_language1);
            break;
          case '*':
            aux_language1 = stack_language.top();
            stack_language.pop();
            int pow = std::stoi(separation_operation[j - 1]);
            stack_language.push(aux_language1 * pow);
            break;
        }
      } else {
        for (size_t k = 0; k < vec_tags.size(); k++) {
          if (separation_operation[j] == vec_tags[k]) {
            stack_language.push(languages[k]);
          }
        }
      }
    }
    std::cout << "La operacion: " << operations[i] << " --> " << stack_language.top() << std::endl;
  }
}