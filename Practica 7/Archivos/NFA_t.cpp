/*

Practica #7: Computabilidad y Algoritmia

Name: NFA_t.cpp
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     NFA CREATROR

Content of the file:
NFA class methods

Author: Noah Sanchez Geurts
Date: 2/11/2019

*/

#include "NFA_t.h"

using namespace std;

NFA_t::NFA_t(char* Entry_File,
             char* Exit_File) {  // Read line by line, Test.dfa
  ifstream Entry_(Entry_File);

  if (!Entry_.is_open()) {
    cout << "El fichero no se ha abierto, intentelo de nuevo" << endl;
  } else {
    // Numero de simbolos y simbolos del alfabeto

    int n_sim;
    char sim;
    Entry_ >> n_sim;
    for (int i = 0; i < n_sim + 1; i++) {
      Entry_ >> sim;
      Alfabeto_.insert(sim);
    }

    // Numero de estados, los meto en un vector

    Entry_ >> numEstados_;
    string name;
    for (int i = 0; i < numEstados_; i++) {
      Entry_ >> name;
      estado_t newEstado(name);
      Estados_.push_back(newEstado);
    }

    Entry_ >> name;
    for (unsigned int i = 0; i < Estados_.size(); i++) {
      if (Estados_[i].get_name() == name) {
        Estados_[i].set_Arranque();
      }
    }

    // Estados de aceptacion

    int numAceptacion;
    Entry_ >> numAceptacion;
    string new_name;
    for (int i = 0; i < numAceptacion; i++) {
      Entry_ >> new_name;
      for (unsigned int i = 0; i < Estados_.size(); i++) {
        if (Estados_[i].get_name() == new_name) {
          Estados_[i].set_Aceptacion();
        }
      }
    }

    // Transiciones

    Entry_ >> numTransiciones_;
    string e_a, e_s;
    char num;
    for (int i = 0; i < numTransiciones_; i++) {
      Entry_ >> e_a;
      Entry_ >> num;
      Entry_ >> e_s;
      transicion_t newtransicion(e_a, num, e_s);
      Transiciones_.push_back(newtransicion);
    }
  }
}

void NFA_t::eps_Clausura() { /* Algoritmo Epsilon-Clausura
  for(int i = 0; i < Estados_.size(); i++){
    Pila_.insert(Estados_[i].get_name());
  }
  while(!Pila_.empty()){
    p := pop()????
    for(int i = 0; i < Transiciones_.size(); i++){
      if(Transiciones_[i].get_entrada() == '~'){
        if(!u in epsilon−clausura(T)????)
        epsilon−clausura(T) := epsilon−clausura(T) + {u} ???
        Pila_.push(u);
      }
    }
  } */
}

void NFA_t::Subconjuntos() { /*Algoritmo de Subconjuntos*/
}

void NFA_t::move() { /*Funcion move para Subconjuntos() */
}

void NFA_t::marcar() { /*Funcion move para Subconjuntos() */
}

void NFA_t::desmarcar() { /*Funcion move para Subconjuntos() */
}

void NFA_t::NFA2DFA(char* Entry_File) { /* Crear DFA a partir del NFA */
}

void NFA_t::drawNFA(char* Exit_File) {
  ofstream Exit_(Exit_File);
  Exit_ << "digraph NFA {" << endl
        << '\t' << "rankdir=LR;" << endl
        << '\t' << "node [ shape = none ]; \"\";" << endl;
  for (unsigned int i = 0; i < Estados_.size(); i++) {
    if (Estados_[i].isAceptacion()) {
      Exit_ << '\t' << "node [shape = doublecircle]; \""
            << Estados_[i].get_name() << "\"" << endl;
    }
  }
  Exit_ << '\t' << "node [shape = circle];" << endl << '\t' << "\"\" -> \"";
  for (unsigned int i = 0; i < Estados_.size(); i++) {
    if (Estados_[i].isArranque()) {
      Exit_ << Estados_[i].get_name() << "\";" << endl;
    }
  }
  for (int i = 0; i < numTransiciones_; i++) {
    Exit_ << '\t' << "\"" << Transiciones_[i].get_actual() << "\""
          << " -> "
          << "\"" << Transiciones_[i].get_siguiente() << "\""
          << " "
          << "[ label = \"" << Transiciones_[i].get_entrada() << "\"];" << endl;
  }
  Exit_ << "}" << endl;
}
