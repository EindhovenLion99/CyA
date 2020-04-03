// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo automaton.c++: Archivo con la definicion de los metodos de la clase automaton.
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

#include <fstream>
#include "automaton.h"



//Carga en un contendor el conjunto de estados del automata.
void 
Automaton::loadStates( void )
{
  std::ifstream fileStates( "ficheros_importantes/estados.txt" );
  std::string aux;
  state stateAux;

  if ( fileStates.is_open() ){
    while ( !fileStates.eof() ){
      fileStates >> aux;
      stateAux.setStateID( aux );
      states_.push_back( stateAux );
    }
  }
  else {
    std::cout << "WARNING:ERROR DE APERTURA" << std::endl;
  }
}



//Carga en un contenedor los estados de acpetacion del automata.
void
Automaton::loadFinalStates( void )
{
  std::ifstream fileFinalStates( "ficheros_importantes/estados_finales.txt" );
  std::string aux;
  state stateAux;

  if ( fileFinalStates.is_open() ){
    while ( !fileFinalStates.eof() ){
      fileFinalStates >> aux;
      stateAux.setStateID( aux );
      finalStates_.push_back( stateAux );
    }
  }
  else {
    std::cout << "WARNING:ERROR DE APERTURA" << std::endl;
  }
}



//Cargar un contenedor con las transiciones del automata.
void
Automaton::loadTransitions( void )
{
  std::ifstream fileTransitions( "ficheros_importantes/transitions.txt" );
  std::string aux;
  Transition transitionAux;

  if ( fileTransitions.is_open() ){
    while ( !fileTransitions.eof() ){
      fileTransitions >> aux;
      transitionAux.setOriginalStateID( aux );
      fileTransitions >> aux;
      transitionAux.setNextStateID( aux );
      fileTransitions >> aux;
      transitionAux.setCondition( aux );
      transitions_.push_back( transitionAux );
    }
    transitionAux.setOriginalStateID( "cplusplus");
    transitionAux.setNextStateID("none");
    transitionAux.setCondition ("\n");
    transitions_.push_back( transitionAux );
  }
  else {
    std::cout << "WARNING:ERROR DE APERTURA" << std::endl;
  }
}



//getter, retorna la etiqueta del estado actual.
std::string
Automaton::getActual( void )
{
  return actual_.getStateID();
}



//setter, modifica la etiqueta del estado actual.
void 
Automaton::setActual( state newActual )
{
  actual_ = newActual;
}



//devuelve la etiqueta del siguiente estado evaluando la condicion de entrada pasada
//por parametro y actualiza el estado actual del automata al siguiente.
std::string 
Automaton::searchNextState( std::string condition )
{
  std::string aux;
  aux = actual_.getStateID();
  for (unsigned i = 0; i < transitions_.size(); i++){ 
    if (( transitions_[i].getOriginalStateID() == aux ) && ( transitions_[i].getCondition() == condition )){
      actual_.setStateID( transitions_[i].getNextStateID() );
      return transitions_[i].getNextStateID();
    }
  }
  return aux;
}