// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º
// Práctica 3 CyA - Calculadora de lenguajes.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 08/10/2019
// Archivo main_lenguaje.cpp: programa cliente. Contiene la función main del
// proyecto
//                    que usa las clases lenguaje y cadena que realizan el
//                    trabajo de leer el fichero de entrada leyendo lineia a
//                    linea identificando lenguajes y operar con ellos para
//                    generar un archivo de salida con la respuesta a dicha
//                    operacion salida.
//
// Objetivo: El objetivo de la practica es trabajar los conceptos basicos sobre
// alfabetos, cadenas
//           y lenguajes formales a traves del diseño de una calculadora para
//           lenguajes formales.
//
//           Antes de comenzar a describir la herramienta a desarrollar es
//           importante tener claramente identificados los tres conceptos
//           introducidos en el primer tema de la asignatura:
//
//            Un alfabeto es un conjunto no vacio y finito de simbolos.
//            Una cadena es una secuencia finita de simbolos de un determinado
//            alfabeto. Un lenguaje (formal) es un conjunto de cadenas.
//
//            Ademas de repasar estos conceptos y asentar los principios de las
//            operaciones ´ basicas con cadenas y con lenguajes, se propone que
//            el alumnado utilice este ejercicio ´ para continuar poniendo en
//            practica los aspectos del desarrollo de programas en C++ ´ sobre
//            los que ya se ha trabajado en las practicas anteriores,
//            enfatizando al menos los ´ siguientes:
//
//            Paradigma de programacion orientada a objetos: identifique clases
//            y objetos que permitan modelar adecuadamente el escenario de
//            trabajo que se plantea.
//
//            Paradigma de modularidad: el programa debiera escribirse de modo
//            que las diferentes funcionalidades que se precisen fueran
//            encapsuladas en metodos concretos cuya extension textual se
//            mantuviera acotada.
//
//            Formato propuesto para la escritura de programas en C++ en esta
//            asignatura.
//
//            El ejercicio plantea nuevamente una oportunidad para trabajar con
//            conjuntos de la STL. Identifique situaciones en las que el uso de
//            conjuntos y la operatoria de los mismos facilite la implementacion
//            que se realiza.
//
// Referencias:
//                    Enunciado de la práctica:
//                    https://campusvirtual.ull.es/1920/pluginfile.php/159482/mod_assign/introattachment/0/CYA_1920_Practica_3.pdf?forcedownload=1
// Historial de revisiones
//                   06/10/2019 - Creación (primera versión) del código.
//                   07/10/2019 - Modificacion (primera).

#include <fstream>
#include <iostream>
#include <string>
#include "cadena.h"
#include "lenguaje.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    cout << "No hay suficientes argumentos, introduzca el fichero de entrada "
            "y/o de salida, y el numero de operacion"
         << endl;
  }
  if (argc == 4) {
    string A = argv[1], B = argv[2], C = argv[3];
    int Op = stoi(C);
    Lenguaje Lang(A, B, Op);
  }

}
