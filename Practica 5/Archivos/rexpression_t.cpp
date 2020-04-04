/*

Practica #5: Computabilidad y Algoritmia

Name: rexpression_t.cpp
Purpose of the code: Infix regular expressions to postfix regular expressions

Content of the file:
Methods for class regular expression, reads expression from file and creates postfix object

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include "rexpression_t.h"

using namespace std;

rexpression_t::rexpression_t(char* file, char* file2) {
  ifstream Entry_File(file);
  if (!Entry_File) {
    cout << "ERROR, no se han podido abrir el archivo de entrada" << endl;
  } else {
    string line;
    char str[20];
    while (getline(Entry_File, line)) {
      for (unsigned int i = 0; i < line.size(); i++) {
        str[i] = line.at(i);
      }
      post_fix(str, file2);
      memset(str, 0, 20);
    }
  }
}
void rexpression_t::post_fix(char str[], char* file2){
  post_f_t post(str, file2);
}

