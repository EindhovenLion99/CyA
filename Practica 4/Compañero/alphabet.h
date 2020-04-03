// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo alphabet.h: archivo de cabecera de la clase alphabet.
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
#include <fstream>
#include <string>

class Alphabet 
{
  public:
    Alphabet () {};
    Alphabet( std::string filename ) :
      filename_( filename )
    {
      std::ifstream file_alphabet( filename_ );
      std::string symbol;
      if ( file_alphabet.is_open() ){
        while ( !file_alphabet.eof() ){
          file_alphabet >> symbol;
          alphabet_.insert( symbol );
        }
      }
      else {
        std::cout << "WARNING:ERROR DE APERTURA" << std::endl;
      } 
      file_alphabet.close();
    }
    ~Alphabet () {};
    std::set<std::string> getAlphabet( void );
    void setAlphabet( std::set<std::string> );
    bool alphabetCheck( std::string );
    
  private:
    std::set<std::string> alphabet_;
    std::string filename_;
};