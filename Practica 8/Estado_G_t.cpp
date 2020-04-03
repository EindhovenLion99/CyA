/*

Practica #8: Computabilidad y Algoritmia

Name: estado_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include "Estado_G_t.h"

using namespace std;

estado_g::estado_g(string name) {
  name_ = name;
}

string estado_g::get_name() {
  return name_;
}

bool estado_g::isArranque() {
  return isArranque_;
}

void estado_g::set_Arranque() {
  isArranque_ = 1;
}

bool estado_g::isAceptacion() {
  return isAccept_;
}

void estado_g::set_Aceptacion() {
  isAccept_ = 1;
}

