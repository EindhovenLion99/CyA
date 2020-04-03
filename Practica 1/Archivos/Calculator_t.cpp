/*

Practica #3: Computabilidad y Algoritmia

Name: Calculator_t.cpp
Purpose of the code: Read Languages from file, operate them
                     and import them into an exit file.

Content of the file: Calculator_t methods, has the functions that
                     do all the operations, invert languages,
                     union, concatenation, etc.

Author: Noah Sanchez Geurts
Date: 04/10/2019

*/

#include "Calculator_t.h"

using namespace std;

void Calculator_t::operators(set<string> A, set<string> B,
                             char* file,     // Constructor for calculator class
                             int operato) {  // Switch for operators
  switch (operato) {
    case 1:
      Concatenation(A, B, file);
      break;
    case 2:
      Union(A, B, file);
      break;
    case 3:
      Intersection(A, B, file);
      break;
    case 4:
      Diference(A, B, file);
      break;
    case 5:
      Sublanguages(A, B, file);
      break;
    case 6:
      Equalanguages(A, B, file);
      break;
    case 7:
      Inverted(A, file);
      Inverted(B, file);
      break;
    case 8:
      Power(A, file);
      Power(B, file);
      break;
    case 9:
      Positive(A, file);
      Positive(B, file);
      break;
    case 10:
      Kleene(A, file);
      Kleene(B, file);
      break;
  }
}
void Calculator_t::Inverted(set<string> A, char* file) {  // Operation inverted:
  if (!A.empty()) {  // Inverts the strings, hola -> aloh
    set<string> aux2;
    ofstream Exit_File(file, fstream::app);

    for (set<string>::iterator i = A.begin(); i != A.end(); i++) {
      string inver = *i;
      inver = string(inver.rbegin(), inver.rend());
      aux2.insert(inver);
    }
    Exit_File << "Inversa L = { ";
    for (set<string>::iterator i = aux2.begin(); i != aux2.end(); i++) {
      Exit_File << (*i) << ", ";
      if (i == aux2.end()) Exit_File << " ";
    }

    Exit_File << " }" << endl;
  }
}

void Calculator_t::Concatenation(set<string> A, set<string> B,
                                 char* file) {  // Operation Concatenation:
  ofstream Exit_File(file, fstream::app);       // Concatenates 2 strings,
                 // hola * adios -> holaadios
    Exit_File << "Concatenación (L1 * L2) = { ";
    // string empty = "&";

    for (set<string>::iterator i = A.begin(); i != A.end(); i++) {
      for (set<string>::iterator j = B.begin(); j != B.end(); j++) {
        // set<string>::iterator it = A.find(empty);
        // set<string>::iterator it2 = B.find(empty);
        // if (it != A.end()) {
        // Exit_File << (*j) << ", ";
        //} else if (it2 != B.end()) {
        //  Exit_File << (*i) << ", ";
        //} else {
        Exit_File << (*i) << (*j) << ", ";
        //}
      }
    }
    Exit_File << "}" << endl;
  } else {
    Exit_File << "ERROR, Solo hay un lenguaje" << endl;
  }
}

void Calculator_t::Union(set<string> A, set<string> B,
                                       char* file) {    // Operation Union:
                                                        // Takes all strings from
  ofstream Exit_File(file, fstream::app);               // both languages into one language
  if (!A.empty() && !B.empty()) {
    Exit_File << "Unión (L1 U L2) = { ";

    ostream_iterator<string> iter(Exit_File, ", ");
    set_union(A.begin(), A.end(), B.begin(), B.end(), iter);
    Exit_File << "}" << endl;
  } else {
    Exit_File << "ERROR, Solo hay un lenguaje" << endl;
  }
}

void Calculator_t::Intersection(set<string> A, set<string> B,
                                char* file) {                 // Operation Intersection:
  ofstream Exit_File(file, fstream::app);                     // Takes the strings from 2
  if (!A.empty() && !B.empty()) {                             // languages that are equal
    cout << endl << "Intersección (L1 ∩ L2) = { &, ";         // into another language
    ostream_iterator<string> iter(Exit_File, ", ");
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), iter);
    Exit_File << "}" << endl;
  } else {
    Exit_File << "ERROR, Solo hay un lenguaje" << endl;
  }
}

void Calculator_t::Diference(set<string> A, set<string> B,
                             char* file) {  // Operation Diference:
  ofstream Exit_File(file, fstream::app);
  if (!A.empty() && !B.empty()) {
    Exit_File << "Diferencia={";
    set<string> C;
    set_difference(B.begin(), B.end(), A.begin(), A.end(),
                   inserter(C, C.begin()));

    for (set<string>::iterator i = C.begin(); i != C.end(); i++)
      Exit_File << (*i) << ", ";

    Exit_File << "}" << endl;
  } else {
    Exit_File << "ERROR, Solo hay un lenguaje" << endl;
  }
}

void Calculator_t::Sublanguages(set<string> A, set<string> B,
                                char* file) {  // Operation Sublanguages:
  ofstream Exit_File(file, fstream::app);
  if (!A.empty() && !B.empty()) {
    int p = 0;

    if (A.size() > B.size())
      Exit_File << "L1 no es sublenguaje de L2.\n" << endl;

    else {
      for (set<string>::iterator i = A.begin(); i != A.end(); i++) {
        for (set<string>::iterator j = B.begin(); j != B.end(); j++) {
          if (*i == *j) {
            p++;
          }
        }
      }
      if (p == 0) {
        Exit_File << "L1 no es sublenguaje de L2.\n" << endl;
      } else {
        Exit_File << "L1 es sublenguaje de L2.\n" << endl;
      }
      p = 0;
    }

    if (B.size() > A.size())
      Exit_File << "L2 no es sublenguaje de L1.\n" << endl;

    else {
      for (set<string>::iterator i = B.begin(); i != B.end(); i++) {
        for (set<string>::iterator j = A.begin(); j != A.end(); j++) {
          if (*i == *j) {
            p++;
          }
        }
      }
      if (p == 0) {
        Exit_File << "L2 no es sublenguaje de L1.\n" << endl;
      } else {
        Exit_File << "L2 es sublenguaje de L1.\n" << endl;
      }
    }
  } else {
    Exit_File << "ERROR, Solo hay un lenguaje" << endl;
  }
}

void Calculator_t::Equalanguages(set<string> A, set<string> B,
                                 char* file) {  // Operation Equalanguages:
  ofstream Exit_File(file, fstream::app);
  if (!A.empty() && !B.empty()) {
    unsigned int p = 0;
    if (A.size() != B.size()) {
      Exit_File << "Los lenguajes son diferentes.\n" << endl;
    } else {
      set<string>::iterator j = B.begin();
      for (set<string>::iterator i = A.begin(); i != A.end(); i++) {
        if (*i == *j) {
          p++;
        } else {
          Exit_File << "main" << endl;
          break;
        }
        j++;
      }
      if (p == A.size()) {
        Exit_File << "Los lenguajes son iguales.\n" << endl;
      } else {
        Exit_File << "Los lenguajes son diferentes.\n" << endl;
      }
    }
  } else {
    Exit_File << "ERROR, Solo hay un lenguaje" << endl;
  }
}

void Calculator_t::Power(set<string> A, char* file) {  // Operation Power:
  ofstream Exit_File(file, fstream::app);
  if (!A.empty()) {
    int poten;
    set<string> tmp = A;
    cout << "¿A qué número desea elevar el lenguaje?   ";
    cin >> poten;

    if (poten == 0) {
      cout << "L^0 = {&}" << endl;
    } else {
      set<string> tmp2;
      for (int i = 1; i < poten; i++) {
        for (auto acc : A) {
          for (auto acc2 : tmp) {
            tmp2.insert(acc + acc2);
          }
        }
        tmp = tmp2;
        tmp2.clear();
      }
    }
    Exit_File << "L^" << poten << " = { ";
    for (set<string>::iterator i = tmp.begin(); i != tmp.end(); i++)
      Exit_File << (*i) << ", ";

    Exit_File << " }";
    Exit_File << endl;
  }
}

void Calculator_t::Positive(set<string> A,
                            char* file) {  // Operation Positive close:
  ofstream Exit_File(file, fstream::app);
  if (!A.empty()) {
    int iter;
    set<string> tmp = A;
    cout << "¿Cuántas iteraciones quieres?   ";
    cin >> iter;
    set<string> tmp3;

    set<string> tmp2;
    for (auto ac : A) {
      tmp2.insert(ac);
    }
    for (int i = 1; i < iter; i++) {
      for (auto acc : A) {
        for (auto acc2 : tmp) {
          tmp2.insert(acc + acc2);
        }
      }
      for (auto c : tmp2) {
        tmp3.insert(c);
      }
      tmp = tmp2;
      tmp2.clear();
    }

    Exit_File << "L+ = {";
    for (set<string>::iterator j = tmp3.begin(); j != tmp3.end(); j++)
      Exit_File << (*j) << ", ";

    if (iter != 0) {
      Exit_File << "...}";
    }
    Exit_File << endl;
  }
}

void Calculator_t::Kleene(set<string> A,
                          char* file) {  // Operation Kleene close:
  ofstream Exit_File(file, fstream::app);
  if (!A.empty()) {
    int iter;
    set<string> tmp = A;
    cout << "¿Cuántas iteraciones quieres?   ";
    cin >> iter;
    set<string> tmp3;

    if (iter == 0) {
      Exit_File << "L^0 = {&}" << endl;
    } else {
      set<string> tmp2;
      for (auto ac : A) {
        tmp2.insert(ac);
      }
      for (int i = 1; i < iter; i++) {
        for (auto acc : A) {
          for (auto acc2 : tmp) {
            tmp2.insert(acc + acc2);
          }
        }
        for (auto c : tmp2) {
          tmp3.insert(c);
        }
        tmp = tmp2;
        tmp2.clear();
      }
    }

    Exit_File << "L* = { &, ";
    for (set<string>::iterator j = tmp3.begin(); j != tmp3.end(); j++)
      Exit_File << (*j) << ", ";
    if (iter != 0) {
      Exit_File << "...}";
    }
    Exit_File << endl;
  }
}
