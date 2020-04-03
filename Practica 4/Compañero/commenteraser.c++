// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo commenteraser.c++: Archivo con los metodos de a clase commenteraser.
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


#include "commenteraser.h"



//Analiza un caracter como condicion y a partir del estado actual hace el salto hacia el siguiente
//y retorna una etiqueta hacia el siguiente estado.
std::string 
commentEraser::analyze( std::string characterReaded )
{ 
  std::string condition, actual;
  
  if (( characterReaded != "\"") && ( characterReaded != "/" ) && (characterReaded != "*") && (characterReaded != "\n")){
    condition = "otra";
  }
  else{
    condition = characterReaded;
  }
  actual = automaton_.searchNextState( condition );
  if( actual == "none" ){
    return "none";
  }
  else if ( actual == "comillas" ){
    return "comillas";
  }
  else if ( actual == "slash" ){
    return "slash";
  }
  else if ( actual == "cplusplus" ){
    return "cplusplus";
  }
  else if ( actual == "c" ){
    return "c";
  }
  else if ( actual == "star" ){
    return "star";
  }
}