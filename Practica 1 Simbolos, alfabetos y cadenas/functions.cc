// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Cheuk Kelly Ng Pante
// Correo: alu0101364544@ull.es
// Fecha: 04/10/2022
// Archivo p01_strings.cc: programa cliente.
//          Contiene la función main del proyecto que usa las clases X e Y
//          que realizan el trabajo de leer el fichero de entrada
//          identificando patrones en el texto que dan lugar
//          al fichero de salida.
// Referencias:
//          https://stackoverflow.com/questions/29441675/splitting-strings-separately-by-line-and-by-blank-space-using-getline
//          http://www.cplusplus.com/forum/general/25076/
//          https://www.delftstack.com/howto/cpp/cpp-get-type/
//
// Historial de revisiones
//          04/10/2022 - Creación (primera versión) del código

#include "functions.h"

#define CADENA_VACIA "&"
#define INT "i"

Alphabet _alpha;  // Creando objeto de la clase Alphabet
Strings _str;     // Creando objeto de la clase String

void CheckParameters(int argc, char* argv[]) {
  std::string parameter1 = argv[1];

  if (argc == 2 && parameter1 == "--help") {
    std::cout
        << "Para ejecutar el programa debe introducir lo siguiente: "
           "./p01_strings filein.txt fileout.txt opcode\nLos opcodes son:\n 1. "
           "Longitud\n 2. Inversa\n 3. Prefijos\n 4. Sufijos\n 5. Subcadenas\n"
        << std::endl;
    exit(EXIT_SUCCESS);
  } else if (argc != 4) {
    std::cout << "Falta parametros, para saber el funcionamiento del programa: "
                 "\n./p01_strings --help"
              << std::endl;
    exit(EXIT_SUCCESS);
  }

  if (typeid(argv[3]).name() != INT) {
    std::cout
        << "Introduzca un opcode disponible en el programa. Utilice '--help' "
        << std::endl;
    exit(1);
  }

  int opcode = std::stoi(argv[3]);

  if (opcode < 1 || opcode > 5) {
    std::cout
        << "Introduzca un opcode disponible en el programa. Utilice '--help' "
        << std::endl;
    exit(EXIT_SUCCESS);
  }
}

std::string Menu(std::string cadena, int _opcode) {
  std::string result_operation;
  int operation = int(_opcode);

  switch (operation) {
    case 0:
      result_operation = _str.length(cadena);
      result_operation = _str.reverse(cadena);
      result_operation = _str.prefixes(cadena);
      result_operation = _str.suffixes(cadena);
      result_operation = _str.substrings(cadena);
      // return result_operation;
      break;
    case 1:
      result_operation = _str.length(cadena);
      return result_operation;
      break;
    case 2:
      result_operation = _str.reverse(cadena);
      return result_operation;
      break;
    case 3:
      result_operation = _str.prefixes(cadena);
      return result_operation;
      break;
    case 4:
      result_operation = _str.suffixes(cadena);
      return result_operation;
      break;
    case 5:
      result_operation = _str.substrings(cadena);
      return result_operation;
      break;
    default:
      break;
  }
  return result_operation;
}

void ReadWriteFile(std::string Input, std::string Output, int option) {
  std::ifstream FileIn;
  std::ofstream FileOut;
  std::string lines, str, result_operation;
  std::stringstream ss;
  std::vector<std::string> list;

  FileIn.open(Input, std::ios::in);
  FileOut.open(Output, std::ios::out | std::ios::ate);

  if (FileIn.fail() && FileOut.fail()) {
    std::cout << "Ficheros no abiertos" << std::endl;
    exit(1);
  }

  while (getline(FileIn, lines, '\n')) {
    ss.str(lines);
    while (ss >> str) {
      list.push_back(str);        // Cortamos la linea por palabras
      if (str == CADENA_VACIA) {  // Detectar un & en el fichero de entrada
        std::cout << "\nERROR. Ha introducido un & en el fichero de entrada."
                  << std::endl;
        FileOut << "No se puede utilizar el & en esta calculadora" << std::endl;
        exit(1);
      }
    }

    for (unsigned i = 0; i < list.size(); i++) {
      if (list[i].length() > 1) {
        std::cout << "\nLa cadena es: " << list[i] << std::endl;
        _alpha.SearchAlphabet(list[i]);
        result_operation = Menu(list[i], option);
        FileOut << result_operation << std::endl;
      } else {
        _alpha.ShowAlphabet(list[i]);
      }
    }

    list.clear();
    ss.clear();
  }

  FileIn.close();
  FileOut.close();
}
