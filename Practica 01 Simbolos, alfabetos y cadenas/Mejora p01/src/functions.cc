/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 01: Símbolos, alfabetos y cadenas
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/functions.h"

std::vector<Chain> chains_operation;

bool check_parameters(int argc, char* argv[]) {
  try {
    if (argc != 4) {
      if (argc == 2 &&
          (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
        std::cout << kHelp << std::endl;
        return false;
      } else if (argc == 2 && (std::string(argv[1]) != "--help" || std::string(argv[1]) != "-h")) {
        std::cout << "Opción " << argv[1] << " no válida. Use --help || -h" << std::endl;
        return false;
      } else if (argc < 4) {
        throw std::runtime_error(
            "ERROR, pocos argumentos. Use \"./p01_strings --help || -h\" para "
            "ver el funcionamiento del programa");
        return false;
      } else {
        throw std::runtime_error("ERROR, demasiados argumentos. Use \"./p01_strings --help || -h\" para ver el funcionamiento del programa");
        return false;
      }
    }

    int opcode = atoi(argv[3]);
    std::ifstream input(argv[1]);
    std::ifstream output(argv[2]);

    if (input.fail()) {
      throw std::runtime_error("ERROR, fichero de entrada no encontrado");
    } else if (output.fail()) {
      throw std::runtime_error("ERROR, fichero de salida no encontrado");
    } else if ((opcode < 1 || opcode > 5)) {
      throw std::runtime_error("ERROR, opcode erroneo. Opcode = [1 - 5]");
    }
    return true;

  } catch (const std::exception& error) {
    std::cerr << error.what() << std::endl;
    return false;
  }
}

std::vector<std::string> read_file(char* argv[]) {
  std::ifstream input(argv[1]);
  std::vector<std::string> lines;
  std::string line;

  while (getline(input, line)) {
    lines.push_back(line);
  }

  input.close();
  return lines;
}

void write_file(std::string exit_file, std::vector<Chain> operation_chains) {
  std::ofstream output;
  output.open(exit_file, std::ios::out | std::ios::ate);

  for (unsigned int i = 0; i < operation_chains.size(); i++) {
    output << operation_chains[i];
  }

  output.close();
}

std::pair<Chain, Alphabet> entry_with_alphabet(std::string& line) {
  Chain chain;
  Alphabet alphabet;
  Symbol symbol;

  // Recorre la linea de derecha a izquierda hasta encontrar un espacio, lo que
  // hay antes del espacio es la cadena
  for (int i = line.size() - 1; i >= 0; i--) {
    if (line[i] == SPACE) {
      std::string entry_chain = line.substr(i + 1, line.size() - 1);
      chain.set_chain(entry_chain);
      line = line.substr(0, i);
      break;
    }
  }

  std::cout << "\tAlfabeto: ";
  for (unsigned int i = 0; i < line.size(); i++) {
    // Todo lo que hay antes de un espacio es un alfabeto
    if (line[i] != SPACE) {
      symbol.set_symbol(line[i]);
      alphabet.set_alphabet(symbol);
    } else {
      alphabet.set_alphabet(' ');
    }
    std::cout << alphabet.get_alphabet()[i].get_symbol();
  }

  std::cout << "\n\tCadena: " << chain << std::endl;

  return std::make_pair(chain, alphabet);
}

Chain entry_without_alphabet(std::string& line) {
  Chain chain;
  Alphabet alphabet;
  Symbol symbol;
  std::vector<Symbol> aux;  // Vector auxiliar para guardar los simbolos y asi poder eliminar los repetidos

  for (unsigned int i = 0; i < line.size(); i++) {
    std::string entry_symbol = line.substr(i, 1);
    aux.push_back(entry_symbol);
    if (std::count(aux.begin(), aux.end(), entry_symbol) == 1) {
      symbol.set_symbol(entry_symbol[0]);
      alphabet.set_alphabet(symbol);
    }
  }
  chain.set_chain(line);

  std::cout << "\tAlfabeto: ";
  for (unsigned int i = 0; i < alphabet.get_alphabet().size(); i++) {
    std::cout << alphabet.get_alphabet()[i].get_symbol() << " ";
  }

  std::cout << "\n\tCadena: " << chain << std::endl;

  return chain;
}

void menu_operations(std::string exit_file, int opcode, Chain& entry_chain) {
  Chain endl("\n");
  Chain space(" ");

  switch (opcode) {
    case 1: {  // length
      int length = entry_chain.length();
      std::cout << "\tLa longitud de la cadena es: " << length << std::endl << std::endl;
      chains_operation.push_back(endl);
      chains_operation.push_back(std::to_string(length));
    } break;
    case 2: {
      std::cout << "\tLa cadena invertida es: ";
      Chain reverse_chain = entry_chain.reverse();
      std::cout << reverse_chain << std::endl << std::endl;
      chains_operation.push_back(reverse_chain);
    } break;
    case 3: {  // prefixes
      std::cout << "\tLos prefijos de la cadena son: ";
      std::vector<Chain> prefixes = entry_chain.prefixes();
      for (unsigned int i = 0; i < prefixes.size(); i++) {
        std::cout << prefixes[i] << " ";
        chains_operation.push_back(space);
        chains_operation.push_back(prefixes[i]);
      }
      chains_operation.push_back(endl);
      std::cout << std::endl << std::endl;
    } break;
    case 4: {  // suffixes
      std::cout << "\tLos sufijos de la cadena son: ";
      std::vector<Chain> suffixes = entry_chain.suffixes();
      for (unsigned int i = 0; i < suffixes.size(); i++) {
        std::cout << "\t" << suffixes[i] << std::endl;
        chains_operation.push_back(space);
        chains_operation.push_back(suffixes[i]);
      }
      chains_operation.push_back(endl);
      std::cout << std::endl << std::endl;
    } break;
    case 5: {  // substring
      std::vector<Chain> substrings = entry_chain.substrings();
      std::cout << "\tLas subcadenas de la cadena son: " << std::endl;
      for (unsigned int i = 0; i < substrings.size(); i++) {
        std::cout << "\t" << substrings[i] << std::endl;
        chains_operation.push_back(endl);
        chains_operation.push_back(substrings[i]);
      }
      std::cout << std::endl << std::endl;
    } break;
    default:
      std::cout << "ERROR, Opcode erroneo. Opcode = [1 - 5]" << std::endl;
      exit(EXIT_FAILURE);
  }

  write_file(exit_file, chains_operation);
}

void check_entry(std::vector<std::string>& entry, std::string exit_file, int opcode) {
  Chain entry_chain;
  std::pair<Chain, Alphabet> entry_pair;
  Alphabet alphabet;

  for (unsigned int i = 0; i < entry.size(); i++) {
    std::string line = entry[i];
    std::size_t found = line.find(SPACE);
    if (found == std::string::npos) {
      std::cout << "- Cadena sin alfabeto" << std::endl;
      entry_chain = entry_without_alphabet(line);
      menu_operations(exit_file, opcode, entry_chain);
    } else {
      std::cout << "- Cadena con alfabeto" << std::endl;
      entry_pair = entry_with_alphabet(line);
      // if (alphabet.check_chain_belong_alphabet(entry_pair)) {
      //   std::cout << "\tLa cadena pertenece al alfabeto" << std::endl;
      //   menu_operations(exit_file, opcode, entry_pair.first);
      // } else {
      //   std::cout << "\tLa cadena no pertenece al alfabeto" << std::endl;
      //   std::cout << std::endl;
      // }
      menu_operations(exit_file, opcode, entry_pair.first);
    }
  }
}