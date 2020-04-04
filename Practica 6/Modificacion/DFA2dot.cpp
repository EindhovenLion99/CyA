/*

Practica #6: Computabilidad y Algoritmia

Name: DFA2dot.cpp
Purpose of the code: Read a dfa file, and converts it to a .dot file
                     DFA CREATROR

Content of the file:
Opens entry file and exit file

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include <iostream>
#include <sstream>
#include <string.h>

#include "dfa_t.h"

using namespace std;

int main(int argc, char *argv[]) {
  const char *help = "--help";
  if (argc == 1) {
    cout << "Modo de empleo: ./DFA2dot input.dfa output.dot " << endl;
    cout << "Pruebe ’./DFA2dot --help’ para más información." << endl;
    exit(1);
  }
  if (argc == 2) {
    const char *Entry_File = argv[1];
    if (strcmp(Entry_File, help) == 0) {
      cout << "Funcionamiento del programa" << endl;
      cout << "Ejecute el ejecutable, introduciendo dos ficheros por "
              "argumentos, un fichero de entrada, por ejemplo, "
              "Input.dfa, y uno de salida, por ejemplo output.dot"
           << endl;
      exit(1);
    } else {
      cout << "Modo de empleo: ./DFA2dot input.dfa output.dot " << endl;
      cout << "Pruebe ’DFA2dot --help’ para más información." << endl;
      exit(1);
    }
  }
  if (argc == 3) {
    char *Entry_File = argv[1];  // Entry file (file.dfa)
    char *Exit_File = argv[2];   // Exit file  (DFA_file.dot)
    dfa_t DFA(Entry_File, Exit_File);
  }
}

