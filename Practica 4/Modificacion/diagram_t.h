/*

Practica #4: Computabilidad y Algoritmia

Name: diagram_t.h
Purpose of the code: Read a cpp file, writes everything in a file, without the comments


Content of the file:
Class diagram_t, has the atributes and the constructor, and methods, to create
a diagram, that will hold the different phases of the diagram himself

Author: Noah Sanchez Geurts
Date: 13/10/2019

*/

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "phase_t.h"

using namespace std;

class diagram_t {
 public:                       // Constant atributes for the diagram, different states
  const char SLASH_C = '/';
  const char STAR_C = '*';
  const char QUOTA_C = '"';
  const char PARENT_C = ')';

  const int START_S = 1;
  const int SLASH_S = 2;
  const int C_S = 3;
  const int Cpp_S = 4;
  const int STAR_S = 5;
  const char QUOTA_S = 6;
  const char PARENT_S = 7;

  diagram_t(char* file, char* file2);  // Constructor
  ~diagram_t() {}                      // Destructor
  void Write(char* file, char c);      // Write in the entry file
  void Write_endl(char* file);         // Writes an endline in case 4
  void Write_s(char* file);            // Write / in case of /code...
  void Write_sp(char* file);            // Writes endline in case 4
};