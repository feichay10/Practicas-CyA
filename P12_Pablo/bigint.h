/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: Algoritmos Divide y Vencerás (Divide & Conquer) - Multiplicación
 * de enteros grandes
 * @file bigint.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Definición de la clase BigInt y sus metodos
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class BigInt {
 public:
  // Constructors:
  BigInt(unsigned long long n = 0);
  BigInt(std::string &);
  BigInt(const char *);
  BigInt(const BigInt &);

  // Helper Functions:
  friend void divide_by_2(BigInt &a);
  friend bool Null(const BigInt &);
  friend int Length(const BigInt &);
  int operator[](const int) const;

  /* * * * Operator Overloading * * * */

  // Direct assignment
  BigInt &operator=(const BigInt &);

  // Post/Pre - Incrementation
  BigInt &operator++();
  BigInt operator++(int temp);
  BigInt &operator--();
  BigInt operator--(int temp);

  // Addition and Subtraction
  friend BigInt &operator+=(BigInt &, const BigInt &);
  friend BigInt operator+(const BigInt &, const BigInt &);
  friend BigInt operator-(const BigInt &, const BigInt &);
  friend BigInt &operator-=(BigInt &, const BigInt &);

  // Comparison operators
  friend bool operator==(const BigInt &, const BigInt &);
  friend bool operator!=(const BigInt &, const BigInt &);

  friend bool operator>(const BigInt &, const BigInt &);
  friend bool operator>=(const BigInt &, const BigInt &);
  friend bool operator<(const BigInt &, const BigInt &);
  friend bool operator<=(const BigInt &, const BigInt &);

  // Multiplication and Division
  friend BigInt &operator*=(BigInt &, const BigInt &);
  friend BigInt operator*(const BigInt &, const BigInt &);
  friend BigInt &operator/=(BigInt &, const BigInt &);
  friend BigInt operator/(const BigInt &, const BigInt &);

  // Modulo
  friend BigInt operator%(const BigInt &, const BigInt &);
  friend BigInt &operator%=(BigInt &, const BigInt &);

  // Power Function
  friend BigInt &operator^=(BigInt &, const BigInt &);
  friend BigInt operator^(BigInt &, const BigInt &);

  // Square Root Function
  friend BigInt sqrt(BigInt &a);

  // Read and Write
  friend std::ostream &operator<<(std::ostream &, const BigInt &);
  friend std::istream &operator>>(std::istream &, BigInt &);

  // Others
  friend BigInt NthCatalan(int n);
  friend BigInt NthFibonacci(int n);
  friend BigInt Factorial(int n);

  BigInt Karatsuba(BigInt num1, BigInt num2, int cota);

 private:
  std::string digits;
};