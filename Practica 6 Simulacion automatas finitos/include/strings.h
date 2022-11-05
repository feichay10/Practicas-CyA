/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Simulación de Autómatas Finitos
 * @file strings.h
 * @author Cheuk Kelly Ng Pante
 * @brief 
 * @version 0.1
 * @date 2022-11-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <string>
#include <vector>

class symbol;

class strings {
  public:
    strings() = default;
    strings(std::string str);
    std::vector<symbol> get_string() const;
    strings reverse();

  private:
    std::vector<symbol> strings_;
    
};

bool operator<(const strings& strings1, const strings& strings2);
bool operator==(const strings& strings1, const strings& strings2);
std::ostream& operator<<(std::ostream& out, const strings& strings);
strings operator+(const strings& strings1, const strings& strings2);