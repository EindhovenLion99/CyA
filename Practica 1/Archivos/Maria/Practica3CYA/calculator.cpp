/***************************************************************************
 *  Computabilidad y Algoritmia                                             *
 *  Práctica Calculadora de Lenguajes Formales                              *
 *  Práctica hecha por: María Candelaria Fariña Rodríguez                   *
 *  Fecha: 01/10/2019                                                       *
 ***************************************************************************/

#include "calculator.hpp"

set<string> Calculator::Concatenation(set<string> language1,
                                      set<string> language2) {
  cout << "Concatenación(L1 * L2) = {";
  set<string> C;
  string cadena;
  for (set<string>::iterator i = language1.begin(); i != language1.end(); i++) {
    for (set<string>::iterator j = language2.begin(); j != language2.end();
         j++) {
      cadena = (*i) + (*j);
      C.insert(cadena);
      cout << (*i) << (*j) << ", ";
    }
  }
  cout << "}" << endl;

  return C;
}

set<string> Calculator::Union(set<string> language1, set<string> language2) {
  cout << "Unión (L1 U L2) = { &, ";

  set<string> C;
  set_union(language1.begin(), language1.end(), language2.begin(),
            language2.end(), inserter(C, C.begin()));
  for (set<string>::iterator i = C.begin(); i != C.end(); i++)
    cout << (*i) << ", ";

  cout << "}" << endl;
  return C;
}
set<string> Calculator::Intersection(set<string> language1,
                                     set<string> language2) {
  cout << endl << "Intersección (L1 ∩ L2) = { &, ";
  set<string> C;
  set_intersection(language1.begin(), language1.end(), language2.begin(),
                   language2.end(), inserter(C, C.begin()));
  for (set<string>::iterator i = C.begin(); i != C.end(); i++)
    cout << (*i) << ", ";

  cout << "}" << endl;
  return C;
}

set<string> Calculator::Difference(set<string> language1,
                                   set<string> language2) {
  cout << "Diferencia = {";
  set<string> C;
  set_difference(language2.begin(), language2.end(), language1.begin(),
                 language1.end(), inserter(C, C.begin()));

  for (set<string>::iterator i = C.begin(); i != C.end(); i++)
    cout << (*i) << ", ";

  cout << "}" << endl;
  return C;
}

void Calculator::Sublanguages(set<string> language1, set<string> language2) {
  bool sublenguaje = false;

  if (language1.size() > language2.size())
    cout << "L1 no es sublenguaje de L2.\n" << endl;

  else {
    for (set<string>::iterator i = language1.begin(); i != language1.end();
         i++) {
      for (set<string>::iterator j = language2.begin(); j != language2.end();
           j++) {
        if (*i == *j) {
          sublenguaje = true;
        }
      }
    }

    if (!sublenguaje) {
      cout << "L1 no es sublenguaje de L2.\n" << endl;
    } else {
      cout << "L1 es sublenguaje de L2.\n" << endl;
    }

    sublenguaje = false;
  }

  if (language2.size() > language1.size())
    cout << "L2 no es sublenguaje de L1.\n" << endl;

  else {
    for (set<string>::iterator i = language2.begin(); i != language2.end();
         i++) {
      for (set<string>::iterator j = language1.begin(); j != language1.end();
           j++) {
        if (*i == *j) {
          sublenguaje = true;
        }
      }
    }
    if (!sublenguaje) {
      cout << "L2 no es sublenguaje de L1.\n" << endl;
    } else {
      cout << "L2 es sublenguaje de L1.\n" << endl;
    }
  }
}

void Calculator::Equality_of_languages(set<string> language1,
                                       set<string> language2) {
  bool igual = false;

  if (language1.size() != language2.size()) {
    cout << "Los lenguajes son diferentes.\n" << endl;
  } else {
    set<string>::iterator j = language2.begin();
    for (set<string>::iterator i = language1.begin(); i != language1.end();
         i++) {
      if (*i == *j) {
        igual = true;
      } else {
        cout << "main" << endl;
        break;
      }
      j++;
    }
    if (igual) {
      cout << "Los lenguajes son iguales.\n" << endl;
    } else {
      cout << "Los lenguajes son diferentes.\n" << endl;
    }
  }
}

set<string> Calculator::Inverse(set<string> language) {
  set<string> aux2;

  for (set<string>::iterator i = language.begin(); i != language.end(); i++) {
    string inver = *i;
    inver = string(inver.rbegin(), inver.rend());
    aux2.insert(inver);
  }

  cout << "Inversa L1 = {";
  for (set<string>::iterator i = aux2.begin(); i != aux2.end(); i++)
    cout << (*i) << ", ";

  cout << "}" << endl;

  return aux2;
}

set<string> Calculator::Potency(set<string> language1, int poten) {
  set<string> tmp = language1;
  if (poten == 0) {
    cout << "L^0 = { & }" << endl;
  } else {
    set<string> tmp2;
    for (int i = 1; i < poten; i++) {
      for (auto acc : language1) {
        for (auto acc2 : tmp) {
          tmp2.insert(acc + acc2);
        }
      }
      tmp = tmp2;
      tmp2.clear();
    }
  }
  cout << "L^" << poten << "= {";
  for (set<string>::iterator i = tmp.begin(); i != tmp.end(); i++)
    cout << (*i) << ", ";

  cout << "}";
  cout << endl;

  return tmp;
}

set<string> Calculator::Positive_closure(set<string> language1) {
  int iter;
  set<string> tmp = language1;
  cout << "¿Cuántas iteraciones quieres?   ";
  cin >> iter;
  set<string> tmp3;

  set<string> tmp2;
  for (auto ac : language1) {
    tmp2.insert(ac);
  }
  for (int i = 1; i < iter; i++) {
    for (auto acc : language1) {
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

  cout << "L⁺ = {";
  for (set<string>::iterator j = tmp3.begin(); j != tmp3.end(); j++)
    cout << (*j) << ", ";

  cout << "...}";
  cout << endl;

  return tmp3;
}

set<string> Calculator::Kleene_closure(set<string> language1) {
  int iter;
  set<string> tmp = language1;
  cout << "¿Cuántas iteraciones quieres?   ";
  cin >> iter;
  set<string> tmp3;

  if (iter == 0) {
    cout << "L^0={&}" << endl;
  } else {
    set<string> tmp2;
    for (auto ac : language1) {
      tmp2.insert(ac);
    }
    for (int i = 1; i < iter; i++) {
      for (auto acc : language1) {
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

  cout << "L* = {";
  for (set<string>::iterator j = tmp3.begin(); j != tmp3.end(); j++)
    cout << (*j) << ", ";

  cout << "...}";
  cout << endl;

  return tmp3;
}