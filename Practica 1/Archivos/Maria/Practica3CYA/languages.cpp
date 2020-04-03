/***************************************************************************
 *  Computabilidad y Algoritmia                                             *
 *  Práctica Calculadora de Lenguajes Formales                              *
 *  Práctica hecha por: María Candelaria Fariña Rodríguez                   *
 *  Fecha: 01/10/2019                                                       *
 ***************************************************************************/

#include <fstream>
#include "languages.hpp"

void languages::write_language1() {
  cout << "LENGUAJE 1." << endl;
  cout << "L={";

  for (set<string>::iterator i = language1_.begin(); i != language1_.end(); i++)
    cout << (*i) << ", ";

  cout << "}";
  cout << endl;
}

void languages::write_language2() {
  cout << "LENGUAJE 2." << endl;
  cout << "L={";

  for (set<string>::iterator i = language2_.begin(); i != language2_.end(); i++)
    cout << (*i) << ", ";

  cout << "}";
  cout << endl;
}

set<string> languages::get_language1() { return language1_; }

set<string> languages::get_language2() { return language2_; }
