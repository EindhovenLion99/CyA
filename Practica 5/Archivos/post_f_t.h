/*

Practica #5: Computabilidad y Algoritmia

Name: post_f_t.h
Purpose of the code: Infix regular expressions to postfix regular expressions

Content of the file:
Postfix class, includes the stack class.

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "stack.h"

using namespace std;

class post_f_t {
 private:
  Stack myStack;
  int node = 0;
  char postfix[50];
 public:
  post_f_t(char str[], char* file2);
  ~post_f_t() {}

  int findPrecedence(char c);
  void Write(char aux[], char str[], int node, char* file);

};