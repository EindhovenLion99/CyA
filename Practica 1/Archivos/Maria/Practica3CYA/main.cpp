/***************************************************************************
 *  Computabilidad y Algoritmia                                             *
 *  Práctica Calculadora de Lenguajes Formales                              *
 *  Práctica hecha por: María Candelaria Fariña Rodríguez                   *
 *  Fecha: 01/10/2019                                                       *
 ***************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include "calculator.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 4) {  // el nombre del ejecutable cuenta como argumento
    cout << "Uso: ./Calculator [nombreFicheroEntrada] [nombreFicheroSalida] "
            "[Operación]\n"
         << endl;
    cout << "1.Concatenación   2.Unión   3.Intersección   4.Diferencia   "
            "5.Sublenguajes   6.Igualdad de lenguajes   7. Inversa   8. "
            "Potencia   9. Cierre positivo  10. Cierre de Kleene"
         << endl;
  } else {
    string name_inputfile(argv[1]);
    string name_outputfile(argv[2]);
    languages L(name_inputfile);

    set<string> language1 = L.get_language1();
    set<string> language2 = L.get_language2();
    set<string> result;

    L.write_language1();
    L.write_language2();

    Calculator C;

    int opcion = atoi(argv[3]);
    ofstream file(name_outputfile);
    string string_;

    // C.operators(opcion);

    switch (opcion) {
      case 1:
        result = C.Concatenation(language1, language2);
        file << "Concatenación (L1 * L2) = {";
        for (set<string>::iterator i = result.begin(); i != result.end(); i++) {
          string_ = (*i);
          file << string_ << ", ";
        }
        file << "}";
        break;

      case 2:
        result = C.Union(language1, language2);
        file << "Unión (L1 U L2) = {";
        for (set<string>::iterator i = result.begin(); i != result.end(); i++) {
          string_ = (*i);
          file << string_ << ", ";
        }
        file << "}";
        break;

      case 3:
        result = C.Intersection(language1, language2);
        file << "Intersección (L1 ∩ L2) = {";
        for (set<string>::iterator i = result.begin(); i != result.end(); i++) {
          string_ = (*i);
          file << string_ << ", ";
        }
        file << "}";
        break;

      case 4:
        result = C.Difference(language1, language2);
        file << "Diferencia = {";
        for (set<string>::iterator i = result.begin(); i != result.end(); i++) {
          string_ = (*i);
          file << string_ << ", ";
        }
        file << "}";
        break;

      case 5:
        C.Sublanguages(language1, language2);
        break;

      case 6:
        C.Equality_of_languages(language1, language2);
        break;

      case 7:
        result = C.Inverse(language1);
        break;

      case 8:
        int poten;
        cout << "¿A qué número desea elevar el lenguaje?   ";
        cin >> poten;
        result = C.Potency(language1, poten);
        file << "L^" << poten << "= {";
        for (set<string>::iterator i = result.begin(); i != result.end(); i++) {
          string_ = (*i);
          file << string_ << ", ";
        }
        file << "}";
        break;

      case 9:
        result = C.Positive_closure(language1);
        file << "L⁺ = {";
        for (set<string>::iterator i = result.begin(); i != result.end(); i++) {
          string_ = (*i);
          file << string_ << ", ";
        }
        file << "}";
        break;

      case 10:
        result = C.Kleene_closure(language1);
        file << "L* = {";
        for (set<string>::iterator i = result.begin(); i != result.end(); i++) {
          string_ = (*i);
          file << string_ << ", ";
        }
        file << "}";
        break;

      case 0:
        cout << "Saliendo..." << endl;
        break;

      default:
        cout << "\nESA OPCIÓN NO ES VÁLIDA.\n" << endl;
    }
    file.close();
  }
}