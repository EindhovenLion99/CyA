/*

Practica #7: Computabilidad y Algoritmia

Name: NFA_t.h
Purpose of the code: Read a NFA file, and converts it to a .dfa file
                     NFA Reader

Content of the file:
Class NFA_t

Author: Noah Sanchez Geurts
Date: 2/11/2019

*/

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "DFA_t.h"


using namespace std;

class NFA_t {
 private:
  vector<estado_t> Estados_;
  vector<transicion_t> Transiciones_;
  set<char> Alfabeto_;
  stack<string> Pila_;
  int numEstados_;
  int numTransiciones_;

 public:
  /**
   * @brief Lee el nfa del fichero de entrada para luego crear el dfa
   * @param Entry_File Archivo entrada
   * @param Exit_File  Archivo Salida
   */

  NFA_t(char* Entry_File, char* Exit_File);

  /**
   * @brief Funcion epsilon-clausura para cada estado
   */

  void eps_Clausura();

  /**
   * @brief Algoritmo de creacion de subconjuntos
   */

  void Subconjuntos();

  /**
   * @brief Funcion move para el algoritmo de creacion de subconjuntos
   */

  void move();

  /**
   * @brief Funcion marcar para el algoritmo de creacion de subconjuntos
   */

  void marcar();

   /**
   * @brief Funcion desmarcar para el algoritmo de creacion de subconjuntos
   */

  void desmarcar();

  /**
   * @brief Escribe el dfa en un fichero
   * @param Exit_File  Archivo Salida
   */

  void NFA2DFA(char* Exit_File);

  /**
   * @brief Escribe el NFA en un fichero
   * @param Exit_File  Archivo Salida
   */

  void drawNFA(char* Exit_File);
};