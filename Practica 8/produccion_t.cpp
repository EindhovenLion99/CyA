/*

Practica #8: Computabilidad y Algoritmia

Name: transicion_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include "produccion_t.h"

using namespace std;

produccion_t::produccion_t(string name, string prod, string name2) {
  est_act_ = name;
  est_sig_ = name2;
  prod_ = prod;
}

string produccion_t::get_actual() {
  return est_act_;
}

string produccion_t::get_prod() {
  return prod_;
}


string produccion_t::get_siguiente() {
  return est_sig_;
}
