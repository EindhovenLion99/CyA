/*

Practica #7: Computabilidad y Algoritmia

Name: estado_t.cpp
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:

Author: Noah Sanchez Geurts
Date: 16/10/2019

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

