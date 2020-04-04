/*

Practica #7: Computabilidad y Algoritmia

Name: NFA2DFA.cpp
Purpose of the code: Read a NFA file, and converts it to a .dfa file
                     NFA Reader

Content of the file:
Opens entry file and exit file

Author: Noah Sanchez Geurts
Date: 2/11/2019

*/

#include <string.h>
#include <iostream>
#include <sstream>

#include "NFA_t.h"

using namespace std;

int main(int argc, char *argv[]) {
  const char *help = "--help";
  if (argc == 1) {
    cout << "Modo de empleo: ./NFA2DFA input.dfa output.dot " << endl;
    cout << "Pruebe ’./NFA2DFA --help’ para más información." << endl;
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
      cout << "Pruebe ’NFA2DFA --help’ para más información." << endl;
      exit(1);
    }
  }
  if (argc == 3) {
    char *Entry_File = argv[1];  // Entry file (file.nfa)
    char *Exit_File = argv[2];   // Exit file  (DFA_file.dfa)
    NFA_t nfa(Entry_File, Exit_File);
    nfa.drawNFA(Exit_File);
    //nfa.eps_Clausura();
    //nfa.Subconjuntos();
    //nfa.WriteDFA(Exit_File);
  }
}
