/***************************************************************************
 *  Computabilidad y Algoritmia                                             *
 *  Práctica Calculadora de Lenguajes Formales                              *
 *  Práctica hecha por: María Candelaria Fariña Rodríguez                   *
 *  Fecha: 01/10/2019                                                       *
 ***************************************************************************/

#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <set>
#include <string>

using namespace std;

class languages {
 private:
  set<string> language1_;
  set<string> language2_;

 public:
  languages(string namefile_) {
    ifstream file(namefile_);
    string string_;
    int h;

    if (file.is_open()) {
      file >> h;
      for (int n_cadenasl1 = 0; n_cadenasl1 != h; n_cadenasl1++) {
        file >> string_;
        if ((string_ != "{") && (string_ != "}") && (string_ != ",")) {
          language1_.insert(string_);
        }
      }
      file >> h;
      for (int n_cadenasl1 = 0; n_cadenasl1 != h; n_cadenasl1++) {
        file >> string_;
        if ((string_ != "{") && (string_ != "}") && (string_ != ",")) {
          language2_.insert(string_);
        }
      }

    } else {
      cout << "No se pudo abrir el fichero de lectura";
    }
    file.close();

    /*int numero;
    string cadena;
    char simbolo;


    numero = 0;
    cout << "Número de cadenas del lenguaje: ";
    cin >> numero;

    int i = 1;
    int aux = 0;

    while(aux != numero){

            cout << "Cadena " << i <<": ";
            cin >> cadena;
            lenguaje_.insert(cadena);

            aux++;
            i++;

    }*/
  };

  ~languages() {}

  void write_language1();

  void write_language2();

  set<string> get_language1();

  set<string> get_language2();
};