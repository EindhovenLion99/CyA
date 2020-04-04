/*

Practica #4: Computabilidad y Algoritmia

Name: remove_t.h
Purpose of the code: Read a cpp file, writes everything in a file, without the comments


Content of the file:
Class phase_t, has the atributes and the constructor, and methods, to create
the phase of the diagram, that will change in the constructor of the diagram, depending by
the character that recieves from the entry file.

Author: Noah Sanchez Geurts
Date: 13/10/2019

*/
#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class phase_t {
 private:
  int phase_;
  int counter;
  int counter2;

 public:
  phase_t();
  ~phase_t() {}
  int get_phase();                  // Gives the actual phase of the diagram
  void set_phase(int fase);         // Sets the new phase of the diagram
  void comment_count(int fase);     // Counts the amount of different comments
  void comment_counter(char* file); // Writes the amount of different comments
};
