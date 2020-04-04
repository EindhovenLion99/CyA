/*

Practica #4: Computabilidad y Algoritmia

Name: remove_t.cpp
Purpose of the code: Read a cpp file, writes everything in a file, without the comments

Content of the file:
Methods, and constructor for the phase class

Author: Noah Sanchez Geurts
Date: 13/10/2019

*/

#include "phase_t.h"

using namespace std;

phase_t::phase_t(void) {}  // Empty Constructor
void phase_t::set_phase(const int fase) { phase_ = fase; }   // Sets the new phase of the diagram
int phase_t::get_phase() { return phase_; }                  // Gives the actual phase of the diagram
void phase_t::comment_count(int fase) {                      // Counts the amount of different comments
  if(fase == 2) {counter++;}
  if(fase == 5) {counter2++;}
}

void phase_t::comment_counter(char* file){                  // Writes the amount of different comments
  ofstream Exit_File(file, ios::app);
  Exit_File << endl << endl;
  Exit_File << counter << " comentarios // eliminados" << endl;
  Exit_File << counter2 << " comentarios /* */ eliminados" << endl;
}
