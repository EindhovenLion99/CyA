/*

Practica #3: Computabilidad y Algoritmia

Name: Language_t.h
Purpose of the code: Read Languages from file, operate them
                     and import them into an exit file.

Content of the file: Class Language_t, creates the language, by strings

Author: Noah Sanchez Geurts
Date: 04/10/2019

*/

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

class Language_t {
 private:
  set<string> language_;

 public:
  Language_t() {}
  ~Language_t() {}
  void insert(string cadena) { language_.insert(cadena); }   // Insert strings in the language
  set<string> get_L(){ return language_; }

  void print() {
    set<string>::iterator it = language_.begin();
    for (; it != language_.end(); it++) {
      cout << (*it) << ", ";
      cout << endl;
    }
  }
};