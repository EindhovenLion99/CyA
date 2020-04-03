/*

Practica #7: Computabilidad y Algoritmia

Name: epsC_t.h
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class epsC_t {
 private:
  string est_act_;
  string est_sig_[20];

 public:
  /**
   * @brief Crea una transicion
   * @param name Nombre del estado actual
   * @param ent Nombre de la entrada
   * @param name2 Nombre del estado siguiente
   */
  epsC_t(string name, string names[]);

  /**
   * @brief Da el nombre del estado actual
   * @return name_ Nombre del estado actual
   */
  string get_actual();

  /**
   * @brief Da el nombre del estado siguiente
   * @return name_ Nombre del estado siguiente
   */

  string get_siguiente();
};