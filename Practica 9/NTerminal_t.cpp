/*

Practica #8: Computabilidad y Algoritmia

Name: estado_t.cpp
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include "NTerminal_t.h"

using namespace std;

NTerminal::NTerminal(string name) {
  name_ = name;
}

string NTerminal::get_name() {
  return name_;
}

bool NTerminal::isArranque() {
  return isArranque_;
}

void NTerminal::set_Arranque() {
  isArranque_ = 1;
}

