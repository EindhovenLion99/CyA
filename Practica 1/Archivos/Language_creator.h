/*

Practica #3: Computabilidad y Algoritmia

Name: Calculator_t.h
Purpose of the code: Read Languages from file, operate them
                     and import them into an exit file.

Content of the file: Constructor of language_creator, also,
                     creates both languages, the calls function
                     operate, which does the operations

Author: Noah Sanchez Geurts
Date: 04/10/2019

*/

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include "Calculator_t.h"

using namespace std;

class language_creator_t {
 public:
  language_creator_t(char* file, char* file2,
                     int Operador) {  // Constructor for the language_creator
    ifstream Entry_File(file);
    Language_t A;  // Languages objects
    Language_t B;
    /*
        char c;
        string cd;
        string cadena;
        int contarComas;
        vector<int> posicionComas;
        char delim = '}';
        do {
         getline(Entrada, cd, delim);
         cd.erase(remove(cd.begin(), cd.end(), '{'), cd.end());
         cd.erase(remove(cd.begin(), cd.end(), ' '), cd.end());

          for (int k = 0; k < cd.length(); k++){
                if( cd[k] == ',' ){
                  contarComas++;
                  posicionComas.push_back(k);
                }
              }
              for (int l = 0; l < posicionComas.size(); l++){
                cd.replace(posicionComas[l],1," ");
              }
          cadena=cd;
      posicionComas.clear();

          lenguajes.insert(cadena);


        } while (!Entrada.eof());
      }
    }*/
    if (!Entry_File.is_open()) {
      cout << "Fallo en los archivos" << endl;
      exit(1);
    } else {
      string word;

      do {  // Read the files, and creates the language
        Entry_File >> word;
        if (word.compare(",") != 0 && word.compare("{") != 0 &&
            word.compare("}") != 0)
          A.insert(word);
      } while (word.compare("}") != 0);
      do {
        Entry_File >> word;
        if (word.compare(",") != 0 && word.compare("{") != 0 &&
            word.compare("}") != 0)
          B.insert(word);
      } while (word.compare("}") != 0);
    }
    set<string> Lang1 = A.get_L();
    set<string> Lang2 = B.get_L();

    cout << "Fichero de entrada abierto correctamente" << endl;
    Calculator_t C;  // Creates the object Calculator
    C.operators(Lang1, Lang2, file2,
                Operador);  // Main function for class calculator
  }
};
