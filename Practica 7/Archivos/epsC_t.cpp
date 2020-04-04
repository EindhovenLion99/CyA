/*

Practica #7: Computabilidad y Algoritmia

Name: epsC_t.cpp
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include "epsC_t.h"

using namespace std;

epsC_t::epsC_t(string name, string names[]) {
  est_act_ = name;
  for(int i = 0; i < 20; i++){
    est_sig_[i] = names[i];
  }
}

string epsC_t::get_actual() { return est_act_; }

string epsC_t::get_siguiente() { return est_sig_[20]; }