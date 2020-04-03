/*

Practica #2: Computabilidad y Algoritmia

Name: word_analyzer.cpp
Purpose of the code: Analyze the words of an entry
                     file and import those words, categorized,
                     into an exit file.

Content of the file: Constructor, Comparation method,
                     which compares the words of the
                     entry file, and the Write methods,
                     that imports the categorized words
                     into the exit file

Author: Noah Sanchez Geurts
Date: 02/10/2019

*/

#include "word_analyzer.h"

analyzer_t::analyzer_t(void) {  // Constructor

  ifstream Esp, Sign, Oper;

  Esp.open("ESPECIALES.txt");
  Sign.open("SIGNO.txt");
  Oper.open("OPERADORES.txt");

  if (!Esp.is_open() || !Sign.is_open() || !Oper.is_open()) {
    cout << "Fallo en los archivos" << endl;
    exit(1);

  } else {
    while (!Esp.eof()) {  // Insert the special words, signs
                          // and operator in their own set.
      string word;
      while (Esp >> word) {
        special_.insert(word);
      }
      set<string>::iterator it = special_.begin();
      for (; it != special_.end(); it++) {
        cout << *it << endl;
      }
    }

    while (!Sign.eof()) {
      string sign;
      while (Sign >> sign) {
        sign_.insert(sign);
      }
    }

    while (!Oper.eof()) {
      string oper;
      while (Oper >> oper) {
        oper_.insert(oper);
      }
    }
  }
}

void analyzer_t::Comparation(char* file, char* file2) {
  ifstream Entry_file(file);

  if (!Entry_file.is_open()) {
    cout << "Fallo en los archivos" << endl;
    exit(1);

  } else {
    string word;

    regex integer("[0-9]+");      // We use regex to create an alphabet for the
    regex flot("[0-9]+.[0-9]+");  // comparation of numbers, floatings and word.

    regex alnum("[a-zA-Z]+[0-9]+|[a-zA-Z]+");

    while (!Entry_file.eof()) {
      Entry_file >> word;

      // We check for integers and float types

      bool match_int = regex_match(word, integer);
      bool match_float = regex_match(word, flot);
      bool match_alnum = regex_match(word, alnum);

      set<string>::iterator it = special_.find(word);  // Itarator to search for
      set<string>::iterator it2 = oper_.find(word);  // the words are in the set
      set<string>::iterator it3 = sign_.find(word);

      if (match_int) {
        Write(file2, "INT", word);
      } else if (match_float) {
        Write(file2, "FLOT", word);
      } else if (it != special_.end()) {
        Write_Special(file2, word);
      } else if (it2 != oper_.end()) {
        Write(file2, "OP", word);
      } else if (it3 != sign_.end()) {
        Write(file2, "SIG", word);
      } else if (match_alnum) {
        Write(file2, "PAL", word);
      } else {
        Write(file2, "DESCONOCIDO", word);
      }
    }
  }
}

void analyzer_t::Write(char* file, string type, string pal) {
  ofstream Exit_file(file, fstream::app);

  if (!Exit_file.is_open()) {
    cout << "Fallo en los archivos" << endl;
    exit(1);

  } else {
    Exit_file << type << " " << pal << endl;
  }
}

void analyzer_t::Write_Special(char* file, string pal) {
  ofstream Exit_file(file, fstream::app);

  if (!Exit_file.is_open()) {
    cout << "Fallo en los archivos" << endl;
    exit(1);

  } else {
    for (unsigned int i = 0; i < pal.length();
         i++) {  // Used for writting in capital letters

      pal[i] = towupper(pal[i]);
    }

    Exit_file << pal << endl;
  }
}
