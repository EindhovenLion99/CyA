/*

Practica #8: Computabilidad y Algoritmia

Name: Gram_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:
Gram class methods

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include "Gram_t.h"

using namespace std;

Gram_t::Gram_t(char* Entry_File) {  // Read line by line, Test.dfa
  ifstream Entry_(Entry_File);

  if (!Entry_.is_open()) {
    cout << "El fichero no se ha abierto, intentelo de nuevo" << endl;
  } else {
    // Numero de simbolos y simbolos del alfabeto

    int n_sim;
    char sim;
    Entry_ >> n_sim;
    for (int i = 0; i < n_sim; i++) {
      Entry_ >> sim;
      Alfabeto_.insert(sim);
    }

    // Numero de estados, los meto en un vector

    int numNoTerminales;

    Entry_ >> numNoTerminales;
    string name;
    for (int i = 0; i < numNoTerminales; i++) {
      Entry_ >> name;
      estado_g newEstado(name);
      NoTerminales_.push_back(newEstado);
    }

    Entry_ >> name;
    for (unsigned int i = 0; i < NoTerminales_.size(); i++) {
      if (NoTerminales_[i].get_name() == name) {
        NoTerminales_[i].set_Arranque();
      }
    }

    // Transiciones

    Entry_ >> numProducciones_;
    string flecha;
    for (int i = 0; i < numProducciones_; i++) {
      Entry_ >> NT;
      Entry_ >> flecha;
      Entry_ >> T;
      Entry_ >> Nt;
      produccion_t newproduccion(NT, T, Nt);
      Producciones_.push_back(newproduccion);
    }
  }
}

void Gram_t::ConvertToNFA(char* Exit_File) {
  NFA_t nfa;
  int num = 1;
  unsigned int k = 0;
  string aux, name;

  nfa.numEstado(numEstados_);

  for (int i = 0; i < numProducciones_; i++) {
    nfa.Set_Estado(Producciones_[i].get_actual());
    if (Producciones_[i].get_prod().size() > 1) {
      for (; k < Producciones_[i].get_prod().size() - 1;
           k++) {
        aux = Producciones_[i].get_prod().at(k);
        name = to_string(num);
        nfa.Set_Transicion(Producciones_[i].get_actual(), aux, name);
        num++;
      }
      aux = Producciones_[i].get_prod().at(k);
      nfa.Set_Transicion(name, aux, Producciones_[i].get_siguiente());
    } else if (Producciones_[i].get_prod().size() == 1 &&
               Producciones_[i].get_prod() != "e") {
      nfa.Set_Transicion(Producciones_[i].get_actual(),
                         Producciones_[i].get_prod(),
                         Producciones_[i].get_siguiente());
    } else if (Producciones_[i].get_prod() == "e") {
      nfa.Set_Transicion(Producciones_[i].get_actual(),
                         Producciones_[i].get_prod(), "f");
    }
  }
  nfa.Ver();
  nfa.drawNFA(Exit_File);
}
