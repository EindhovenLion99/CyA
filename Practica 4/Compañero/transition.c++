// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo transition.c++: Archivo con la definicion de los metodos de la clase transition.
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

#include "transition.h"



//getter, retorna la etiqueta del estado original.
std::string 
Transition::getOriginalStateID( void )
{
  return State1.state::getStateID();
}



//getter, retorna el valor de la etiqueta del siguiente estado.
std::string 
Transition::getNextStateID( void )
{
  return State2.state::getStateID();
}



//getter, retorna la etiqueta de la condicion para pasar al siguiente estado.
std::string 
Transition::getCondition( void )
{
  return condition_;
}



//setter, cambiamos el estado orginal.
void 
Transition::setOriginalStateID( std::string newState1 )
{
  State1.state::setStateID( newState1 );
}



//setter, cambiamos el estado siguiente.
void 
Transition::setNextStateID( std::string newState2 )
{
  State2.state::setStateID( newState2 );
}



//setter, cambiamos la condicion para ir al siguiente estado. 
void 
Transition::setCondition( std::string newCondition )
{
  condition_ = newCondition;
}