// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo transition.h: archivo de cabecera de la clase transition.
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

#include "state.h"

class Transition : public state 
{
  public: 
    Transition () {};
    Transition (
      std::string originalState,
      std::string nextState, 
      std::string condition) :
      originalState_( originalState ),
      nextState_( nextState ),
      condition_( condition )
      {
        State1.state::setStateID( originalState_ );
        State2.state::setStateID( nextState_ );
      };
    ~Transition () {};
    std::string getOriginalStateID( void );
    std::string getNextStateID( void );
    std::string getCondition( void );
    void setOriginalStateID( std::string );
    void setNextStateID( std::string );
    void setCondition( std::string );
    
  private:
    std::string originalState_, nextState_, condition_;
    state State1, State2;
}; 