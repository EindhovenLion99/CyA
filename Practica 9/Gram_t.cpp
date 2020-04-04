/*

Practica #8: Computabilidad y Algoritmia

Name: Gram_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:
Gram class methods

Author: Noah Sanchez Geurts
Date: 19/11/2019

*/

#include "Gram_t.h"

using namespace std;

Gram_t::Gram_t(char* Entry_File) {  // Read line by line
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
      NTerminal newEstado(name);
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
    string arrow;
    for (int i = 0; i < numProducciones_; i++) {
      Entry_ >> NT;
      Entry_ >> arrow;
      Entry_ >> T;
      Entry_ >> Nt;
      produccion_t newproduccion(NT, T, Nt);
      Producciones_.push_back(newproduccion);
    }
  }
}

void Gram_t::ConvertToCNF() { // Convertir a forma Normal de Chomsky
  
}

void Gram_t::DrawG(char* Exit_File) {
  ofstream Exit_(Exit_File);
  Exit_ << "Forma Normal de Chomsky" << endl;
  for (int i = 0; i < numProducciones_; i++) {
    Exit_ << Producciones_[i].get_actual() << " ->>"
          << Producciones_[i].get_siguiente() << endl;
  }
}
