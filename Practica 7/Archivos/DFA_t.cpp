/*

Practica #7: Computabilidad y Algoritmia

Name: DFA_t.cpp
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:
DFA class methods

Author: Noah Sanchez Geurts
Date: 2/11/2019

*/


#include "DFA_t.h"

using namespace std;

/* DFA_t::DFA_t() {

}
*/

void DFA_t::drawDFA(char* Exit_File) { /*
  ofstream Exit_(Exit_File);
  Exit_ << "digraph DFA {" << endl
        << '\t' << "rankdir=LR;" << endl
        << '\t' << "node [ shape = none ]; \"\";" << endl;
  for (unsigned int i = 0; i < myEstados_.size(); i++) {
    if (myEstados_[i].isAccept()) {
      Exit_ << '\t' << "node [shape = doublecircle]; \""
            << myEstados_[i].get_name() << "\"" << endl;
    }
  }
  Exit_ << '\t' << "node [shape = circle];" << endl << '\t' << "\"\" -> \"";
  for(unsigned int i = 0; i < myEstados_.size(); i++) {
    if(myEstados_[i].isArranque()) { Exit_ << myEstados_[i].get_name() << "\";" << endl; }
  }
  for (int i = 0; i < num_transiciones; i++) {
    Exit_ << '\t' << "\"" << myTransiciones_[i].get_actual() << "\""
          << " -> "
          << "\"" << myTransiciones_[i].get_siguiente() << "\""
          << " "
          << "[ label = \"" << myTransiciones_[i].get_entrada() << "\"];"
          << endl;
  }
  Exit_ << "}"; */
}
