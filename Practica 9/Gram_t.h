/*

Practica #9: Computabilidad y Algoritmia

Name: Gram_t.h
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:
Class Gram_t

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/


#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "NTerminal_t.h"
#include "produccion_t.h"


using namespace std;

class Gram_t {
 private:
  vector<NTerminal> NoTerminales_;
  vector<produccion_t> Producciones_;
  set<char> Alfabeto_;

  int numEstados_;
  int numProducciones_;
  string NT, T, Nt;

 public:
  /**
   * @brief Lee el nfa del fichero de entrada para luego crear el dfa
   * @param Entry_File Archivo entrada
   * @param Exit_File  Archivo Salida
   */

  Gram_t(char* Entry_File);

  /**
   * @brief Escribe el dfa en un fichero
   * @param Exit_File  Archivo Salida
   */

  void ConvertToCNF();

  /**
   * @brief Escribe el dfa en un fichero
   * @param Exit_File  Archivo Salida
   */

  void DrawG(char* Exit_File);

};
