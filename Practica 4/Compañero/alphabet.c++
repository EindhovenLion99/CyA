// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo alphabet.c++: archivo con los metodos de la clase alphabet.
//
// Objetivo: Trabajar con los conceptos de estados y transiciones en un automata diseñado
//           para realizar una determinada tarea.
//
//           Profundizar en las capacidades de desarrollar programas orientados a objetos en
//           C++.
// Referencias: 
//                    Enunciado de la práctica:
//                    https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
// Historial de revisiones
//                   13/10/2019 - Creación (primera versión) del código.
//                   14/10/2019 - Modificacion (primera).

#pragma once

#include <iostream>
#include <set>
#include <string>
#include "alphabet.h"



//getter
std::set<std::string> 
Alphabet::getAlphabet( void )
{
  return alphabet_;
}



//setter
void 
Alphabet::setAlphabet( std::set<std::string> newAlphabet )
{
  alphabet_ = newAlphabet;
}



//Verifica si un caracter pertenece al alfabeto o no, valor de retorno : booleano.
bool 
Alphabet::alphabetCheck( std::string symbol )
{
  if ( alphabet_.find( symbol ) != alphabet_.end() ){
    return true;
  }
  else {
    return false;
  }
}