/*

Practica #8: Computabilidad y Algoritmia

Name: NFA_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:
NFA class methods

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include "NFA_t.h"

using namespace std;

NFA_t::NFA_t() {}

void NFA_t::Set_Transicion(string E_e, string entr, string E_s) {

  transicion_t newtransicion(E_e, entr, E_s);
  Transiciones_.push_back(newtransicion);
  numTransiciones_++;
}

void NFA_t::numEstado(int num) {

  numEstados_ = num;

}


void NFA_t::Set_Estado(string E_e) {

  Estados_.insert(E_e);

}

void NFA_t::Ver(){
  for(int i = 0; i < numTransiciones_; i++){
    cout << Transiciones_[i].get_actual() << " " << Transiciones_[i].get_entrada() << " " << Transiciones_[i].get_siguiente() << endl;
  }
}

void NFA_t::drawNFA(char* Exit_File) {

  ofstream Exit_(Exit_File);
  Exit_ << "digraph NFA {" << endl
        << '\t' << "rankdir=LR;" << endl
        << '\t' << "node [ shape = none ]; \"\";" << endl;
  Exit_ << '\t' << "node [shape = doublecircle]; \"f\"" << endl;
  Exit_ << '\t' << "node [shape = circle];" << endl << '\t' << "\"\" -> \"S\"" << endl;
  for (int i = 0; i < numTransiciones_; i++) {
    Exit_ << '\t' << "\"" << Transiciones_[i].get_actual() << "\""
          << " -> "
          << "\"" << Transiciones_[i].get_siguiente() << "\""
          << " "
          << "[ label = \"" << Transiciones_[i].get_entrada() << "\"];" << endl;
  }
  Exit_ << "}" << endl;

}
