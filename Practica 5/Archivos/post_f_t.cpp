/*

Practica #5: Computabilidad y Algoritmia

Name: post_f_t.cpp
Purpose of the code: Infix regular expressions to postfix regular expressions

Content of the file:
Method for the object postfix

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include "post_f_t.h"

using namespace std;

post_f_t::post_f_t(char str[], char* file2) {  //Constructor for postfix
  char c;
  int i = 0, j = 0;
  while (str[i++] != '\0');  //Adds parentesis at biginning and end of ER
  str[i+1] = '\0';
  str[i--] = ')';
  while (i > 0) {
    str[i] = str[i-1];
    i--;
  }
  str[i] = '(';


  while (str[i] != '\0') {    // Creates postfix expression
    if (str[i] == '(') {
      myStack.push(str[i]);
    } else if (isalpha(str[i])) {
      postfix[j++] = str[i];
    } else if (str[i] == '|' || str[i] == '&' || str[i] == '*') {
      while (myStack.peep() == '|' || myStack.peep() == '&' ||
             myStack.peep() == '*') {
        if (findPrecedence(myStack.peep()) >= findPrecedence(str[i])) {
          postfix[j++] = myStack.pop();
        } else {
          break;
        }
      }
      myStack.push(str[i]);
    } else if (str[i] == ')') {
      while ((c = myStack.pop()) != '(') {
        postfix[j++] = c;
      }
    }
    i++;
  }
  postfix[j] = '\0';
  Write(str, postfix, node, file2);
  
}

int post_f_t::findPrecedence(char c) {
  switch (c) {
    case '|':
      return 1;
      break;
    case '&':
      return 2;
      break;
    case '*':
      return 3;
      break;
  }
  return 0;
}

void post_f_t::Write(char aux[], char str[], int node, char* file) {
  ofstream Exit_File(file, ios::app);
  Exit_File << "Infija: ";
  Exit_File << aux << endl;
  Exit_File << "Postfija: ";
  Exit_File << str << endl;
}
