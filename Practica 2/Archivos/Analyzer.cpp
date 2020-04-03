/*

Practica #2: Computabilidad y Algoritmia

Name: Analyzer.cpp
Purpose of the code: Analyze the words of an entry
                     file and import those words,
                     categorized, into an exit file.

Content of the file: Opens both files, creates the
                     object T (from class analyze_t)
                     and calls the function Comparation.

Author: Noah Sanchez Geurts
Date: 02/10/2019

*/

#include <fstream>
#include <iostream>
#include "word_analyzer.h"

using namespace std;

int main(int argc, char *argv[]) {

  if (argv[1] == NULL || argv[2] == NULL) {
    cout << "No hay suficientes argumentos, introduzca el fichero de entrada "
            "y/o de salida"
         << endl;

  } else {
    char *Entry_File = argv[1];  // Entry file (fichero_entrada.txt)
    char *Exit_File = argv[2];   // Exit file  (fichero_salida.txt)

    analyzer_t T;  // Creation of the main object, class analyzert_t

    T.Comparation(
        Entry_File,
        Exit_File);  // We call function Comparation to compare the strings
  }                  // from the entry file and import them into the exit file
}
