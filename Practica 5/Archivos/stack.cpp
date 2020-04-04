/*

Practica #5: Computabilidad y Algoritmia

Name: stack.cpp
Purpose of the code: Class for the regular expression, reads expression from file

Content of the file:
Class stack, methos, pop, push and peep

Author: Noah Sanchez Geurts
Date: 16/10/2019

*/

#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(){
  top = -1;
}

void Stack::push(int data){
  if(!isfull()) {
    arr[++top] = data;
  } else {
    throw "Overflow!!";
  }
}

int Stack::pop(){
  if(!isempty()) {
    return arr[top--];
  } else {
    throw "Underflow!";
  }
}

int Stack::peep(){
  if(!isempty()) {
    return arr[top];
  } else {
    throw "Underflow!";
  }
}

bool Stack::isfull() {
  return top == siz - 1;
}

bool Stack::isempty() {
  return top == -1;
}


