/*

Practica #6: Computabilidad y Algoritmia

Name: dfa_t.h
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:
DFA class

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

/*
 * @file dfa_t.h
 * @version 1.0
 * @date 28/10/19
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

class dfa_t {
 private:
  vector<estado_t> myEstados_;
  vector<transicion_t> myTransiciones_;
  set<char> myAlfabet_;
  int num_estados;
  int num_transiciones;

 public:
  /**
   * @brief Crea el dfa
   * @param Entry_File Archivo entrada
   * @param Exit_File  Archivo Salida
   */

  dfa_t(char* Entry_File, char* Exit_File);

  /**
   * @brief Escitura en el archivo
   * @param Entry_File Archivo entrada
   * @param Exit_File  Archivo Salida
   * @param num_accept Estados de acceptacion
   * @param num_transiciones Numero de transiciones
   */
  void Write_dot(char* Exit_File, int num_accept, int num_transiciones);
};