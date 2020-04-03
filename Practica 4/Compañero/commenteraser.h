// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo commenteraser.h: archivo de cabecera de la clase commenteraser.
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


#include <iostream>
#include <set>
#include <fstream>
#include <string>

#include "automaton.h"
#include "alphabet.h"

class commentEraser
{
  public:
    commentEraser (std::string fileInName, std::string fileOutName):
      fileInName_( fileInName ),
      fileOutName_( fileOutName )
     {
        fileIn_.open( fileInName_ );
        fileOut_.open( fileOutName_ );
        std::string characterReaded, characterOut, aux;
        Alphabet alphabet_( "alphabet.txt" );
        state initial_( "none" );
        Automaton automaton(alphabet_, initial_);
        automaton_ = automaton;
        int numAux;
        std::string actual, anterior ( "none" );

        if (( fileIn_.is_open() ) && ( fileOut_.is_open() )){
          std::cout << "fichero '" << fileInName_ << "' abierto exitosamente."  << std::endl;
          while ( !fileIn_.eof() ){
            characterReaded = fileIn_.get();
            characterOut = analyze( characterReaded );
            actual = characterOut;
            std::cout << anterior << " " << characterReaded <<  " " << actual << std::endl;
            if ( actual == "none" ){
              fileOut_ << characterReaded;
              if ( anterior == "star"){
                  numAux = fileOut_.tellp(); 
                  fileOut_.seekp( numAux - 1 );
              }
              anterior = actual;
            }
            else if ( actual == "comillas" ){
              fileOut_ << characterReaded;
              anterior = actual;
            }
            else if ( actual == "slash" ){
              fileOut_ << characterReaded;
              anterior = actual;
              aux = fileIn_.peek();
              if(( aux == "/" ) || ( aux == "*" )){
                numAux = fileOut_.tellp(); 
                fileOut_.seekp( numAux - 1 );
              }
            }
            else if( actual == "c" ){
              anterior = actual;
            }
            else if( actual == "cpluslus" ){
              anterior = actual;  
            }
            else if( actual == "star" ){
              anterior = actual;
            }
          }
          fileIn_.close();
          fileOut_.close();
          std::cout << "fichero '" << fileOutName_ << "' creado exitosamente."  << std::endl;
        }
        else {
          std::cout << "WARNING:ERROR DE APERTURA.!!!" << std::endl;
        }
     };
    ~commentEraser () {};
    std::string analyze( std::string );
  
  private:
    std::ifstream fileIn_;
    std::ofstream fileOut_;
    std::string fileInName_; 
    std::string fileOutName_;
    Automaton automaton_;
};