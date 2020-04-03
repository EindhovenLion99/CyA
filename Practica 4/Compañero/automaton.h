// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo automaton.h: archivo de cabecera de la clase automaton.
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

#include <vector>
#include "transition.h"
#include "alphabet.h"

class Automaton : public Transition
{
  public:
    Automaton () {};
    Automaton 
    (Alphabet alphabet, state initial) :
    alphabet_( alphabet ),
    initial_( initial )
    { 
      
      actual_ = initial_;
      loadStates();
      loadFinalStates();
      loadTransitions();
    };
    ~Automaton () {};
    void loadStates( void );
    void loadFinalStates( void );
    void loadTransitions( void );
    std::string getActual( void );
    void setActual( state );
    std::string searchNextState(std::string);

  
  private:
    Alphabet alphabet_;
    state initial_;
    state actual_;
    std::vector<state> states_;
    std::vector<state> finalStates_;
    std::vector<Transition> transitions_;

};