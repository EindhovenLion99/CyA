// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 14/10/2019
// Archivo main_commenteraser.c++: programa cliente. utiliza un automata y la clase commenteraser 
//                                 para eliminar comentarios en c++ pasandole un programa de c++
//                                 y dando como salida el mismo programa pero sin los comentarios
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
#include <string>
#include "commenteraser.h"

int main (int argc ,char *argv[] ){

switch ( argc ) {
  case 1: 
    std::cout << "FALTAN 2 PARAMETROS. !!!NOTA:Se debe colocar dos ficheros como parametros. Ejemplo: ./Analisis nombre_fichero_entrada[1] nombre_fichero_salida[2] [0-9]-> operacion¡¡¡."<< std::endl << std::endl << std::endl;
  break;

  case 2: 
    std::cout << "FALTA 1 PARAMETRO. !!!NOTA:Se debe colocar dos ficheros como parametros. Ejemplo: ./Analisis nombre_fichero_entrada[1] nombre_fichero_salida[2] [0-9]-> operacion¡¡¡."<< std::endl << std::endl << std::endl;
  break; 

  case 3: 
  { std::string filein ( argv[1] ),fileout ( argv[2] );
    commentEraser cEraser (filein, fileout);
  }
  break;

  default :
    std::cout << "HAY DEMASIADOS PARAMETROS. !!!NOTA: Se debe colocar dos ficheros como parametros. Ejemplo: ./Analisis nombre_fichero[1] nombre_fichero[2] [0-9]-> operacion¡¡¡."<< std::endl << std::endl << std::endl;
}
}