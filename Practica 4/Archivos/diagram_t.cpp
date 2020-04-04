/*

Practica #4: Computabilidad y Algoritmia

Name: diagram_t.cpp
Purpose of the code: Read a cpp file, writes everything in a file, without the
comments


Content of the file:
Methods, and constructor for the diagram class

Author: Noah Sanchez Geurts
Date: 13/10/2019

*/

#include "diagram_t.h"

using namespace std;

diagram_t::diagram_t(
    char* file,
    char* file2) {  // Constructor, creates the diagram and the phase
  ifstream Entry_File(file);

  if (!Entry_File.is_open()) {
    cout << "ERROR, no se han podido abrir los archivos" << endl;
    exit(1);
  } else {
    char c;
    phase_t Ph;
    Ph.set_phase(START_S);
    while (Entry_File.get(c)) {
      switch (Ph.get_phase()) {
        case 1:

          if (c == SLASH_C) {
            Ph.set_phase(SLASH_S);
          } else if (c == QUOTA_C) {
            Ph.set_phase(QUOTA_S);
            Write(file2, c);
          } else {
            Write(file2, c);
          }
          break;

        case 2:

          if (c == SLASH_C) {
            Ph.set_phase(Cpp_S);
            Ph.comment_count(SLASH_S);
          } else if (c == STAR_C) {
            Ph.set_phase(C_S);
          } else if (c != SLASH_C) {
            Write_s(file2);
            Write(file2, c);
            Ph.set_phase(START_S);
          }
          break;

        case 3:
          if (c == STAR_C) {
            Ph.set_phase(STAR_S);
          }
          break;

        case 4:

          if (c == '\n') {
            Ph.set_phase(START_S);
            Write_endl(file2);
          }
          break;

        case 5:

          if (c == SLASH_C) {
            Ph.set_phase(START_S);
            Ph.comment_count(STAR_S);
          } else if (c != STAR_C) {
            Ph.set_phase(C_S);
          }
          break;

        case 6:

          if (c == QUOTA_C) {
            Ph.set_phase(START_S);
            Write(file2, c);
          } else {
            Write(file2, c);
          }
      }
    }
    Write_endl(file2);
    Ph.comment_counter(file2);
  }
}

void diagram_t::Write(char* file, char c) {  // Write in the entry file
  ofstream Exit_File(file, ios::app);
  Exit_File << c;
}

void diagram_t::Write_s(char* file) {  // Write in the entry file
  ofstream Exit_File(file, ios::app);
  Exit_File << "/";
}

void diagram_t::Write_endl(char* file) {  // Writes endline in case 4
  ofstream Exit_File(file, ios::app);
  Exit_File << endl;
}
