/*

Practica #8: Computabilidad y Algoritmia

Name: NFA_t.h
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader


Content of the file:
Class NFA_t

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/


#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "estado_t.h"
#include "transicion_t.h"

using namespace std;

class NFA_t {
 private:
  set<string> Estados_;
  vector<transicion_t> Transiciones_ ;

  int numEstados_;
  int numTransiciones_ = 0;

 public:
  /**
   * @brief Lee el nfa del fichero de entrada para luego crear el dfa
   * @param Entry_File Archivo entrada
   * @param Exit_File  Archivo Salida
   */

  NFA_t();
  void Set_Transicion(string E_e, string entr, string E_s);
  void Set_Estado(string E_e);

  void numEstado(int num);
  void Ver();

  /**
   * @brief Escribe el NFA en un fichero
   * @param Exit_File  Archivo Salida
   */

  void drawNFA(char* Exit_File);
};
