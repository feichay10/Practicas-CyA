/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de una DFA
 * @file alphabet.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Contiene la implementación de los diferentes metodos de la clase 'Alphabet'
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/alphabet.h"

/**
 * @brief Constructor por defecto de la clase 'Alphabet'
 *
 */
Alphabet::Alphabet() {}

/**
 * @brief Añade un símbolo al alfabeto
 * 
 * @param symbols Introduce un símbolo al alfabeto
 */
void Alphabet::setSymbol(Symbol symbols) {
  bool flag = true;

  for (unsigned i = 0; i < alphabet_.size(); i++) {
    if (alphabet_.at(i).getSymbol() == symbols.getSymbol()) {
      flag = false;
    }
  }
  if (flag == true) {
    alphabet_.push_back(symbols);
  }
}

/**
 * @brief Devuelve el símbolo del alfabeto en la posición 'i'
 * 
 * @param pos Posicion del símbolo en el alfabeto
 * @return std::string 
 */
std::string Alphabet::getSymbol(int pos) {
  return alphabet_.at(pos).getSymbol();
}

/**
 * @brief Devuelve el tamaño del alfabeto
 * 
 * @return unsigned 
 */
unsigned Alphabet::getAlphabetSize() { return alphabet_.size(); }

/**
 * @brief Comprueba si el símbolo introducido pertenece al alfabeto
 * 
 * @param strings Símbolo a comprobar
 * @return true 
 * @return false 
 */
bool Alphabet::AlphabetComprobation(std::string strings) {
  if (strings == "&") {
    return true;
  } else {
    size_t count = 0;
    for (size_t i = 0; i < strings.size(); i++) {
      for (size_t j = 0; j < alphabet_.size(); j++) {
        Symbol auxiliary = alphabet_[j];
        if (strings[i] == auxiliary.getSymbol()[i]) {
          count++;
        }
      }
    }
    if (count == strings.size()) {
      return true;
    } else {
      return false;
    }
  }
}