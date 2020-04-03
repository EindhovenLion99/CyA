/*

Practica #8: Computabilidad y Algoritmia

Name: estado_t.h
Purpose of the code: Read a Grammar file, and converts it to a .nfa file
                     Grammar Reader

Content of the file:

Author: Noah Sanchez Geurts
Date: 11/11/2019

*/

/*
 * @file estado_t.h
 * @version 1.0
 * @date 28/10/19
 * @author Noah Sanchez
 * @brief Atributos de un estado
 * @title Estado
 *
 */

#include <iostream>
#include <string>

using namespace std;

class estado_g {
 private:
  string name_;
  bool isArranque_ = 0;
  bool isAccept_;

 public:
  /**
   * @brief Crea un esatdo
   * @param name Nombre del estado
   */
  estado_g(string name);
  /**
   * @brief Da el nombre del estado
   * @return name_ Nombre del estado
   */
  string get_name();

  /**
   * @brief Saber si es un estado de arranque
   * @return isArranque_ Es estado de arraque?
   */
  bool isArranque();
  /**
   * @brief Saber si es un estado de acceptacion
   * @return isArranque_ Es estado de acceptacion?
   */
  bool isAceptacion();
  /**
   * @brief Pone un estado como estado de arranque
   */

  void set_Arranque();
  /**
   * @brief Pone un estado como estado de acceptacion
   */
  void set_Aceptacion();
};