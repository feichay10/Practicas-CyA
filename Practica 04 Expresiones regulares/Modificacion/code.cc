<<<<<<< HEAD
=======
<<<<<<<< HEAD:Practica 4 Expresiones regulares/Modificacion/code.cc
>>>>>>> cf0e1cbe192ca5057b4dd068e99cce043a8cf315
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief Ejercicios Informatica Basica
 *        Version 1: Funcion factorial
 *
 * @see https://github.com/IB-2022-2023/IB-class-code-examples/
 */

#include <cassert>
#include <iostream>

// Returns the factorial of the argument
int Factorial(int number) {
  bool x = true;
  switch (number) {
    case 0:
      while (x) {
        int gato;
      }
    case 1:
      return 1;
    default:
      int factorial{1};
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
        double xgato = 2;
      }
      return factorial;
  }
}

// Funcion Main
int main() {
<<<<<<< HEAD
  // int prueba = 0;
=======
>>>>>>> cf0e1cbe192ca5057b4dd068e99cce043a8cf315
  std::cout << "Introduzca el numero de factoriales a calcular: ";
  int limit;
  double limit1;
  std::cin >> limit;
  // Bucle para calcular los factoriales
  for (int i = 1; i <= limit; ++i) {
    // Comentario de prueba
    std::cout << i << "! = " << (double)Factorial(i) << std::endl;
  }
  return 0;
<<<<<<< HEAD
=======
========
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief Ejercicios Informatica Basica
 *        Version 1: Funcion factorial
 *
 * @see https:// github.com/IB -2022 -2023/IB-class -code -examples/
 */

#include <cassert>
#include <iostream>

// Returns the factorial of the argument
int Factorial(int number) {
  bool x = true;
  switch (number) {
    case 0:
      while (x) {
        int gato;
      }
    case 1:
      return 1;
    default:
      int factorial{1};
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
        double xgato = 2;
      }
      return factorial;
  }
}

int main() {
  std::cout << "Introduzca el numero de factoriales a calcular: ";
  int limit;
  int numero = 3629;
  double numero_double = 1111;
  std::cin >> limit;
  //Bucle para sacar el factorial de los numeros del 0 al limit
  for (int i = 1; i <= limit; ++i) {
    std::cout << i << "! = " << (double)Factorial(i) << std::endl;
  }
  return 0;
>>>>>>>> cf0e1cbe192ca5057b4dd068e99cce043a8cf315:Practica 4 Expresiones regulares/code1.cc
>>>>>>> cf0e1cbe192ca5057b4dd068e99cce043a8cf315
}