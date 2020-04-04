/*

Practica #3: Computabilidad y Algoritmia

Name: main_Calculator.cpp
Purpose of the code: Read Languages from file, operate them
                     and import them into an exit file.

Content of the file: Opens both files, creates the
                     object Language_creator which
                     does all the operations

Author: Noah Sanchez Geurts
Date: 04/10/2019

*/

#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

#include "Language_creator.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    cout << "No hay suficientes argumentos, introduzca el fichero de entrada "
            "y/o de salida, y el numero de operacion"
         << endl;

  } else {
    char *Entry_File = argv[1];  // Entry file (fichero_entrada.txt)
    char *Exit_File = argv[2];   // Exit file  (fichero_salida.txt)
    int Operador = atoi(argv[3]);


    language_creator_t Languages(Entry_File, Exit_File, Operador); // Creates the languages

  }
}
