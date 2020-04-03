/*

Practica #7: Computabilidad y Algoritmia

Name: transicion_t.h
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include <iostream>
#include <string>

using namespace std;

class transicion_t {
 private:
  string est_act_;
  string est_sig_;
  char entr_;

 public:
  /**
   * @brief Crea una transicion
   * @param name Nombre del estado actual
   * @param ent Nombre de la entrada
   * @param name2 Nombre del estado siguiente
   */
  transicion_t(string name, char ent, string name2);

  /**
   * @brief Da el nombre del estado actual
   * @return name_ Nombre del estado actual
   */
  string get_actual();

  /**
   * @brief Da el simbolo de entrada
   * @return entr_ Simbolo de entrada
   */
  char get_entrada();

  /**
   * @brief Da el nombre del estado siguiente
   * @return name_ Nombre del estado siguiente
   */

  string get_siguiente();
};