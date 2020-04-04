/*

Practica #8: Computabilidad y Algoritmia

Name: transicion_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include "transicion_t.h"

using namespace std;

transicion_t::transicion_t(string name, string s, string name2) {
  est_act_ = name;
  est_sig_ = name2;
  entrada_ = s;
}

string transicion_t::get_actual() {
  return est_act_;
}

string transicion_t::get_entrada() {
  return entrada_;
}


string transicion_t::get_siguiente() {
  return est_sig_;
}
