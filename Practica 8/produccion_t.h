/*

Practica #8: Computabilidad y Algoritmia

Name: transicion_t.h
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

#include <iostream>
#include <string>

using namespace std;

class produccion_t {
 private:
  string est_act_;
  string est_sig_;
  string prod_;

 public:
  /**
   * @brief Crea una transicion
   * @param name Nombre del estado actual
   * @param ent Nombre de la entrada
   * @param name2 Nombre del estado siguiente
   */
  produccion_t(string name, string prod, string name2);

  /**
   * @brief Da el nombre del estado actual
   * @return name_ Nombre del estado actual
   */
  string get_actual();

  /**
   * @brief Da el nombre del estado actual
   * @return name_ Nombre del estado actual
   */
  string get_prod();

  /**
   * @brief Da el nombre del estado siguiente
   * @return name_ Nombre del estado siguiente
   */

  string get_siguiente();
};