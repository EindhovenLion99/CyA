/*

Practica #5: Computabilidad y Algoritmia

Name: stack.h
Purpose of the code: Class for the regular expression, reads expression from file

Content of the file:
Class stack

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include <iostream>

using namespace std;

#define siz 50

class Stack {

  int arr[siz];
  int top;

 public:
  Stack();
  void push(int);
  int pop();
  int peep();
  bool isfull();
  bool isempty();
};