/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 02: Operaciones con lenguajes
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
* @TODO: 
* - Fix operator+, operator- and operator*
* - Fix on the results of the operations create the alphabet
* - Fix check_parameters when the user introduce 5 or 6 opcode and he introduce 5 parameters
*/

#include "../include/functions.h"

bool check_parameters(int argc, char* argv[]) {
  try {
    if (argc == 4 && (atoi(argv[3]) == 5 || atoi(argv[3]) == 6)) {
      int opcode = atoi(argv[3]);
      std::ifstream input_1(argv[1]);
      std::ifstream output(argv[2]);
      if (input_1.fail()) {
        throw std::runtime_error("ERROR, fichero de entrada 1 no encontrado");
      } else if (output.fail()) {
        throw std::runtime_error("ERROR, fichero de salida no encontrado");
      } else if ((opcode < 5 || opcode > 6)) {
        throw std::runtime_error("ERROR, opcode erroneo. Opcode = [1 - 6]");
      }
      return true;
    } else if (argc == 5) {
      int opcode = atoi(argv[4]);
      std::ifstream input_1(argv[1]);
      std::ifstream input_2(argv[2]);
      std::ifstream output(argv[3]);
      if (input_1.fail()) {
        throw std::runtime_error("ERROR, fichero de entrada 1 no encontrado");
      } else if (input_2.fail()) {
        throw std::runtime_error("ERROR, fichero de entrada 2 no encontrado");
      } else if (output.fail()) {
        throw std::runtime_error("ERROR, fichero de salida no encontrado");
      } else if ((opcode < 1 || opcode > 6)) {
        throw std::runtime_error("ERROR, opcode erroneo. Opcode = [1 - 6]");
      }
      return true;
    } else if (argc != 4 || argc != 5) {
      if (argc == 2 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
        std::cout << kHelp << std::endl;
        return false;
      } else if (argc < 4) {
        throw std::runtime_error("ERROR, pocos argumentos. Use \"./p02_languages --help || -h\" para ver el funcionamiento del programa");
        return false;
      } else {
        throw std::runtime_error("ERROR, demasiados argumentos. Use \"./p02_languages --help || -h\" para ver el funcionamiento del programa");
        return false;
      }
    }
  } catch (const std::exception& error) {
    std::cerr << error.what() << std::endl;
    return false;
  }
  return false;
}

std::vector<std::string> read_file(std::string file_in) {
  std::ifstream input(file_in);
  std::vector<std::string> lines;
  std::string line;

  while (getline(input, line)) {
    lines.push_back(line);
  }

  input.close();
  return lines;
}

void write_file(std::string exit_file, std::vector<Language> language_results) {
  std::ofstream output;
  output.open(exit_file, std::ios::out | std::ios::ate);

  for (unsigned int i = 0; i < language_results.size(); i++) {
    output << language_results[i] << std::endl;
  }

  output.close();
}

Language get_alphabet_and_language(std::string entry_alphabet, std::string entry_language) {
  Language alphabet_language, language;
  Alphabet alphabet;
  Chain chain;
  std::string str_chain;

  // Get the alphabet
  for (unsigned int i = 0; i < entry_alphabet.size(); i++) {
    if (entry_alphabet[i] != BEGIN_BRACE && entry_alphabet[i] != END_BRACE && entry_alphabet[i] != SPACE) {
      alphabet.set_alphabet(entry_alphabet[i]);
      alphabet_language.set_alphabet(alphabet);
    }
  }

  // Get the language
  for (unsigned int i = 2; i < entry_language.size(); i++) {
    if (entry_language[i] != BEGIN_BRACE && entry_language[i] != END_BRACE && entry_language[i] != SPACE ) {
      str_chain += entry_language[i];
    } else if (entry_language[i] == SPACE) { 
      chain.set_chain(str_chain);
      alphabet_language.set_language(chain);
      str_chain = "";
      chain.clear_chain();
    }
  }

  std::cout << alphabet_language << std::endl;

  return alphabet_language;
}

std::vector<Language> extract_entry(std::vector<std::string> entry) {
  std::string line, str_alphabet, str_language;
  Alphabet alphabet;
  std::vector<Language> languages;

  for (unsigned int i = 0; i < entry.size(); i++) {
    line = entry[i]; // line by line
    for (unsigned int j = 0; j < line.size(); j++) {
      str_alphabet = line.substr(line.find(BEGIN_BRACE), line.find(END_BRACE) + 1); // Extract the alphabet of the line
      str_language = line.substr(line.rfind(BEGIN_BRACE), line.rfind(END_BRACE));   // Extract the language of the line
    }
    languages.push_back(get_alphabet_and_language(str_alphabet, str_language));
  }

  std::cout << std::endl;

  return languages;
}

void menu_operations(std::string exit_file, int opcode, std::vector<Language> languages_1, std::vector<Language> languages_2) {
  std::vector<Language> language_result;
  int exponent;

  switch (opcode) {
    case 1:
      std::cout << "Concatenación" << std::endl;
      for (unsigned int i = 0; i < languages_1.size(); i++) {
        for (unsigned int j = 0; j < languages_2.size(); j++) {
          language_result.push_back(languages_1[i] + languages_2[j]);
        }
      }
      break;
    case 2:
      std::cout << "Unión" << std::endl;
      for (unsigned int i = 0; i < languages_1.size(); i++) {
        for (unsigned int j = 0; j < languages_2.size(); j++) {
          language_result.push_back(languages_1[i] | languages_2[j]);
        }
      }
      break;
    case 3:
      std::cout << "Intersección" << std::endl;
      for (unsigned int i = 0; i < languages_1.size(); i++) {
        for (unsigned int j = 0; j < languages_2.size(); j++) {
          language_result.push_back(languages_1[i] ^ languages_2[j]);
        }
      }
      break;
    case 4:
      std::cout << "Diferencia" << std::endl;
      for (unsigned int i = 0; i < languages_1.size(); i++) {
        for (unsigned int j = 0; j < languages_2.size(); j++) {
          language_result.push_back(languages_1[i] - languages_2[j]);
        }
      }
      break;
    case 5:
      std::cout << "Inversa" << std::endl;
      for (unsigned int i = 0; i < languages_1.size(); i++) {
        language_result.push_back(!languages_1[i]);
      }
      break;
    case 6:
      std::cout << "Potencia" << std::endl;
      std::cout << "Introduzca el exponente: ";
      std::cin >> exponent;
      for (unsigned int i = 0; i < languages_1.size(); i++) {
        language_result.push_back(languages_1[i] * exponent);
      }
      break;
    default:
      std::cout << "ERROR, opcode erroneo. Opcode = [1 - 6]" << std::endl;
      exit(EXIT_FAILURE);
      break;
  }
  std::cout << "Resultado de la operación: " << std::endl;
  for (unsigned int i = 0; i < language_result.size(); i++) {
    std::cout << language_result[i] << std::endl;
  }
  write_file(exit_file, language_result);
}