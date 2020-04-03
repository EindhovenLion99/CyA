/*

Practica #7: Computabilidad y Algoritmia

Name: DFA_t.h
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:
DFA class

Author: Noah Sanchez Geurts
Date: 02/11/2019

*/

/*
 * @file DFA_t.h
 * @version 1.0
 * @date 2/11/19
 * @author Noah Sanchez
 * @brief Atributos del dfa
 * @title DFA
 *
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

class DFA_t {
 private:
  vector<estado_t> myEstados;
  vector<transicion_t> myTransiciones;
  set<char> myAlfabet;
  int numEstados;
  int numTransiciones;

 public:
  /**
   * @brief Crea el dfa
   * @param Entry_File Archivo entrada
   * @param Exit_File  Archivo Salida
   */

  //DFA_t(char* Entry_File, char* Exit_File);

  /**
    * @brief Crea el dfa
    * @param Exit_File  Archivo Salida
    */

  void drawDFA(char* Exit_File);
};