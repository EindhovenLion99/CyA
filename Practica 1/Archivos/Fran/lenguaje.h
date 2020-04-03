// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º
// Práctica 3 CyA - Calculadora de lenguajes.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 08/10/2019
// Archivo lenguje.h: Archivo de cabera de la clase lenguaje que contine todas
// las operacionaes para
//                    operar con Lenguajes.
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
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Lenguaje {
 public:
  Lenguaje(string Entry_File, string Exit_File, int operacion = 0, ) {
    ifstream file(Entry_File);
    ofstream file2(Exit_File);
    int numLines = 0, cont = 0;
    vector<int> posicionComas;
    string chain, aux_1;
    if (infile.is_open()) {
      cout << "OPENED" << Entry_File << endl;
      string aux;
      while (!file.eof()) {
        getline(file, aux, '\n');
        numLines++;
      }
      file.seekg(0);
      for (int i = 0; i < numLines / 2; i++) {
        getline(file, chain, '\n');
        for (int j = 0; j < chain.length(); j++) {
          if ((chain[j] == '}') || (chain[j] == '{') || (chain[j] == ' ')) {
            chain.erase(j, 1);
            j--;
          }
        }
        for (int k = 0; k < chain.length(); k++) {
          if (chain[k] == ',') {
            cont++;
            posicionComas.push_back(k);
          }
        }
        for (int l = 0; l < posicionComas.size(); l++) {
          chain.replace(posicionComas[l], 1, " ");
        }
        istringstream iss(chain);
        while (iss >> aux_1) {
          l_1.push_back(aux_1);
        }
        posicionComas.clear();

        getline(file, chain, '\n');
        for (int j = 0; j < chain.length(); j++) {
          if ((chain[j] == '}') || (chain[j] == '{') || (chain[j] == ' ')) {
            chain.erase(j, 1);
            j--;
          }
        }
        for (int k = 0; k < chain.length(); k++) {
          if (chain[k] == ',') {
            cont++;
            posicionComas.push_back(k);
          }
        }
        for (int l = 0; l < posicionComas.size(); l++) {
          chain.replace(posicionComas[l], 1, " ");
        }
        istringstream iss_1(chain);
        while (iss_1 >> aux_1) {
          l_2.push_back(aux_1);
        }
        posicionComas.clear();
        seleccionMetodo(l_1, l_2, outfile, operacion);
        l_1.clear();
        l_2.clear();
      }
      outfile.close();
      cout << "CLOSED '" << Entry_File << endl;
      infile.close();
    } else {
      cout << "error de apertura" << endl;
    }
    file2.close();
    file.close();
  };
  ~Lenguaje(){};
  void seleccionMetodo(vector<string>, vector<string>, ofstream&, int);
  vector<string> concatenacion(vector<string>, vector<string>);
  vector<string> union_(vector<string>, vector<string>);
  vector<string> interseccion(vector<string>, vector<string>);
  vector<string> diferencia(vector<string>, vector<string>);
  bool sublenguaje(vector<string>, vector<string>);
  bool igualdad(vector<string>, vector<string>);
  vector<string> inversa(vector<string>);
  vector<string> potencia(vector<string>, int);
  vector<string> cierre_kleene(vector<string>);
  vector<string> cierre_positivo(vector<string>);
  set<string> cambioSet(vector<string>);

 private:
  vector<string> l_1;
  vector<string> l_2;
  set<string> set_resultado;
  set<string>::iterator it;
};