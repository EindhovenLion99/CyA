/***************************************************************************
 *  Computabilidad y Algoritmia                                             *
 *  Práctica Calculadora de Lenguajes Formales                              *
 *  Práctica hecha por: María Candelaria Fariña Rodríguez                   *
 *  Fecha: 01/10/2019                                                       *
 ***************************************************************************/

#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
#include "languages.hpp"

using namespace std;

class Calculator {
 private:
 public:
  inline Calculator(){};   // Constructor por defecto
  inline ~Calculator(){};  // Destructor por defecto

  set<string> Concatenation(set<string> language1, set<string> language2);

  set<string> Union(set<string> language1, set<string> language2);

  set<string> Intersection(set<string> language1, set<string> language2);

  set<string> Difference(set<string> language1, set<string> language2);

  void Sublanguages(set<string> language1, set<string> language2);

  void Equality_of_languages(set<string> language1, set<string> language2);

  set<string> Inverse(set<string> language);

  set<string> Potency(set<string> language, int poten);

  set<string> Positive_closure(set<string> language);

  set<string> Kleene_closure(set<string> language);
};
