/*

Practica #6: Computabilidad y Algoritmia

Name: transicion_t.cpp
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include "transicion_t.h"

using namespace std;

transicion_t::transicion_t(string name, int ent, string name2) {
  est_act_ = name;
  est_sig_ = name2;
  entr_ = ent;
}

string transicion_t::get_actual() {
  return est_act_;
}

int transicion_t::get_entrada() {
  return entr_;
}

string transicion_t::get_siguiente() {
  return est_sig_;
}
