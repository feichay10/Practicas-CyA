/**
 * @file p04_code_analyzer.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <iostream>
#include <string>

const std::string HELP = "--help";

int main(int argc, char* argv[]) {
  std::string input, output;
  //Fichero file;

  if (argc == 3) {
    input = argv[1];
    output = argv[2];
  } else if (argc == 2) {
    if (argv[1] == HELP) {
      std::cout << "Para la correcta ejecución del programa, este debe invocarse";
      std::cout << " con dos parametros. Un fichero de entrada, y otro de salida.";
      std::cout << " Por ejemplo: ./p04_code_analyzer code.cc codescheme.txt" << std::endl;
      exit(0);
    }
  } else {
    std::cout << "Parametros erroneos, para ver el funcionamiento del programa,";
    std::cout << " ejecute ./p04_code_analyzer --help" << std::endl;
    exit(1);
  }
}
