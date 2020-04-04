/*

Practica #8: Computabilidad y Algoritmia

Name: estado_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include "estado_t.h"

using namespace std;

estado_t::estado_t(string name) {
  name_ = name;
}

string estado_t::get_name() {
  return name_;
}

bool estado_t::isArranque() {
  return isArranque_;
}

void estado_t::set_Arranque() {
  isArranque_ = 1;
}

bool estado_t::isAceptacion() {
  return isAccept_;
}

void estado_t::set_Aceptacion() {
  isAccept_ = 1;
}

