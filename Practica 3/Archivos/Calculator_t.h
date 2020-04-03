/*

Practica #3: Computabilidad y Algoritmia

Name: Calculator_t.h
Purpose of the code: Read Languages from file, operate them
                     and import them into an exit file.

Content of the file: Class calculator_t, has the headers
                     for the class functions (operations)

Author: Noah Sanchez Geurts
Date: 04/10/2019

*/

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

#include "Language_t.h"

using namespace std;

class Calculator_t {
 private:
  // No tiene atributos la clase

 public:
  void operators(set<string> A, set<string> B, char* file, int operato);

  void Inverted(set<string> A, char* file);
  void Concatenation(set<string> A, set<string> B, char* file);
  void Union(set<string> A, set<string> B, char* file);
  void Intersection(set<string> A, set<string> B, char* file);
  void Diference(set<string> A, set<string> B, char* file);
  void Sublanguages(set<string> A, set<string> B, char* file);
  void Equalanguages(set<string> A, set<string> B, char* file);
  void Power(set<string> A, char* file);
  void Positive(set<string> A, char* file);
  void Kleene(set<string> A, char* file);
};
