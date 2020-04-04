/*

Practica #6: Computabilidad y Algoritmia

Name: dfa_t.cpp
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:
DFA class methods

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include "dfa_t.h"

using namespace std;

dfa_t::dfa_t(char* Entry_File,
             char* Exit_File) {  // Read line by line, Test.dfa
  ifstream Entry_(Entry_File);

  if (!Entry_.is_open()) {
    cout << "El fichero no se ha abierto, intentelo de nuevo" << endl;
  } else {
    // Numero de simbolos y simbolos del alfabeto

    int n_sym;
    char sym;
    Entry_ >> n_sym;
    for (int i = 0; i < n_sym; i++) {
      Entry_ >> sym;
      myAlfabet_.insert(sym);
    }

    // Numero de estados, los meto en un vector

    Entry_ >> num_estados;
    string name;
    for (int i = 0; i < num_estados; i++) {
      Entry_ >> name;
      estado_t newEstado(name);
      myEstados_.push_back(newEstado);
    }

    Entry_ >> name;
    for (unsigned int i = 0; i < myEstados_.size(); i++) {
      if (myEstados_[i].get_name() == name) myEstados_[i].set_Arranque();
    }

    // Estados de aceptacion

    int num_accept;
    Entry_ >> num_accept;
    string new_name;
    for (int i = 0; i < num_accept; i++) {
      Entry_ >> new_name;
      for (unsigned int i = 0; i < myEstados_.size(); i++) {
        if (myEstados_[i].get_name() == new_name) {
          myEstados_[i].set_Accept();
        }
      }
    }

    // Transiciones

    Entry_ >> num_transiciones;
    string e_a, e_s;
    int num;
    for (int i = 0; i < num_transiciones; i++) {
      Entry_ >> e_a;
      Entry_ >> num;
      Entry_ >> e_s;
      transicion_t newtransicion(e_a, num, e_s);
      myTransiciones_.push_back(newtransicion);
    }

    Write_dot(Exit_File, num_accept, num_transiciones);
  }
}

void dfa_t::Write_dot(char* Exit_File, int num_accept, int num_transiciones) {
  ofstream Exit_(Exit_File);
  Exit_ << "digraph DFA {" << endl
        << '\t' << "rankdir=LR;" << endl
        << '\t' << "node [ shape = none ]; \"\";" << endl;

  int cont = 0;

  for (unsigned int i = 0; i < myEstados_.size(); i++) {
    for (unsigned int j = 0; i < myTransiciones_.size(); j++) {
      if (!myEstados_[i].isAccept() &&
          (myEstados_[i].get_name() == myTransiciones_[j].get_actual() ==
           myTransiciones_[j].get_siguiente()))
        cont++;
      if (cont == 2) {
        Exit_ << '\t' << "node [style = filled]; \""
              << myTransiciones_[i].get_actual() << "\"" << endl;
        cont = 0;
      }
    }
  }

  Exit_ << '\t' << "node [shape = circle];" << endl << '\t' << "\"\" -> \"";
  for (unsigned int i = 0; i < myEstados_.size(); i++) {
    if (myEstados_[i].isArranque()) {
      Exit_ << myEstados_[i].get_name() << "\";" << endl;
    }
  }
  for (int i = 0; i < num_transiciones; i++) {
    Exit_ << '\t' << "\"" << myTransiciones_[i].get_actual() << "\""
          << " -> "
          << "\"" << myTransiciones_[i].get_siguiente() << "\""
          << " "
          << "[ label = \"" << myTransiciones_[i].get_entrada() << "\"];"
          << endl;
  }
  Exit_ << "}";
}
