/*

Practica #5: Computabilidad y Algoritmia

Name: ER2Tree.cpp
Purpose of the code: Read a cpp file, writes everything in a file, without the comments

Content of the file:
Opens entry file and exit file, also creates the diagram.

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

#include "rexpression_t.h"


using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "No hay suficientes argumentos, introduzca el fichero de entrada "
            "y/o de salida"
         << endl;

  } else {
    char *Entry_File = argv[1];  // Entry file (fichero_entrada.txt)
    char *Exit_File = argv[2];   // Exit file  (fichero_salida.txt)

    rexpression_t ER(Entry_File, Exit_File);

  }
}