/*

Practica #5: Computabilidad y Algoritmia

Name: rexpression_t.h
Purpose of the code: Infix regular expressions to postfix regular expressions

Content of the file:
Class for the regular expression, reads expression from file

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/


#include <iostream>
#include <fstream>
#include <string>
#include "string.h"

#include "post_f_t.h"

using namespace std;

class rexpression_t {

  public:

  rexpression_t(char* file, char* file2);
  ~rexpression_t() {}

  void post_fix(char str[], char* file);


};