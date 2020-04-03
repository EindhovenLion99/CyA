// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA 2019-2020)
// Curso: 2º
// Práctica 3 CyA - Calculadora de lenguajes.
// Autor: Francisco Jesus Mendes Gomez.
// Correo: alu0101163970@ull.edu.es
// Fecha: 08/10/2019
// Archivo lenguaje.c++: Archivo '.c++' donde se encuentran definidos los
// metodos de la clase
//                       Lenguaje.
//
// Objetivo: El objetivo de la practica es trabajar los conceptos basicos sobre
// alfabetos, cadenas
//           y lenguajes formales a traves del diseño de una calculadora para
//           lenguajes formales.
//
//           Antes de comenzar a describir la herramienta a desarrollar es
//           importante tener claramente identificados los tres conceptos
//           introducidos en el primer tema de la asignatura:
//
//            Un alfabeto es un conjunto no vacio y finito de simbolos.
//            Una cadena es una secuencia finita de simbolos de un determinado
//            alfabeto. Un lenguaje (formal) es un conjunto de cadenas.
//
//            Ademas de repasar estos conceptos y asentar los principios de las
//            operaciones ´ basicas con cadenas y con lenguajes, se propone que
//            el alumnado utilice este ejercicio ´ para continuar poniendo en
//            practica los aspectos del desarrollo de programas en C++ ´ sobre
//            los que ya se ha trabajado en las practicas anteriores,
//            enfatizando al menos los ´ siguientes:
//
//            Paradigma de programacion orientada a objetos: identifique clases
//            y objetos que permitan modelar adecuadamente el escenario de
//            trabajo que se plantea.
//
//            Paradigma de modularidad: el programa debiera escribirse de modo
//            que las diferentes funcionalidades que se precisen fueran
//            encapsuladas en metodos concretos cuya extension textual se
//            mantuviera acotada.
//
//            Formato propuesto para la escritura de programas en C++ en esta
//            asignatura.
//
//            El ejercicio plantea nuevamente una oportunidad para trabajar con
//            conjuntos de la STL. Identifique situaciones en las que el uso de
//            conjuntos y la operatoria de los mismos facilite la implementacion
//            que se realiza.
//
// Referencias:
//                    Enunciado de la práctica:
//                    https://campusvirtual.ull.es/1920/pluginfile.php/159482/mod_assign/introattachment/0/CYA_1920_Practica_3.pdf?forcedownload=1
// Historial de revisiones
//                   06/10/2019 - Creación (primera versión) del código.
//                   07/10/2019 - Modificacion (primera).

#include <fstream>
#include <iostream>
#include <string>
#include "cadena.h"
#include "lenguaje.h"

using namespace std;

void Lenguaje::seleccionMetodo(vector<string> l_1, vector<string> l_2,
                               ofstream& outfile, int metodo_,
                               int potencia_ = 0) {
  switch (metodo_) {
    case 1: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::concatenacion(l_1, l_2);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
    } break;

    case 2: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::union_(l_1, l_2);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
    } break;

    case 3: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::interseccion(l_1, l_2);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
    } break;

    case 4: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::diferencia(l_1, l_2);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
    } break;

    case 5: {
      bool esSublenguaje;
      esSublenguaje = Lenguaje::sublenguaje(l_1, l_2);
      if (esSublenguaje == true) {
        outfile << "L_1 es sublenguaje de L_2" << '\n';
      } else {
        outfile << "L_1 'NO' es sublenguaje de L_2" << '\n';
      }
    } break;

    case 6: {
      bool sonInguales;
      sonInguales = Lenguaje::igualdad(l_1, l_2);
      if (sonInguales == true) {
        outfile << "L_1 es igual a L_2" << '\n';
      } else {
        outfile << "L_1 es distinto a L_2" << '\n';
      }
    } break;

    case 7: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::inversa(l_1);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
      outfile << "{";
      l_resultado = Lenguaje::inversa(l_2);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
    } break;

    case 8: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::potencia(l_1, potencia_);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
      outfile << "{";
      l_resultado = Lenguaje::potencia(l_2, potencia_);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
        outfile << *it << ",";
      }
      if (!set_resultado.empty()) {
        posicionFicheroOut = outfile.tellp();
        outfile.seekp(posicionFicheroOut - 1);
      }
      outfile << "}"
              << "\n";
      set_resultado.clear();
    } break;

    case 9: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::cierre_positivo(l_1);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      if (l_resultado.size() < 10) {
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          outfile << *it << ",";
        }
        if (!set_resultado.empty()) {
          posicionFicheroOut = outfile.tellp();
          outfile.seekp(posicionFicheroOut - 1);
        }
        outfile << '}' << "\n";
      } else {
        int contador = 0;
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          if (contador == 10) {
            break;
          } else {
            outfile << *it << ",";
            contador++;
          }
        }
        outfile << "...}"
                << "\n";
      }
      set_resultado.clear();
      outfile << "{";
      l_resultado = Lenguaje::cierre_positivo(l_2);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      if (l_resultado.size() < 10) {
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          outfile << *it << ",";
        }
        if (!set_resultado.empty()) {
          posicionFicheroOut = outfile.tellp();
          outfile.seekp(posicionFicheroOut - 1);
        }
        outfile << '}' << "\n";
      } else {
        int contador = 0;
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          if (contador == 10) {
            break;
          } else {
            outfile << *it << ",";
            contador++;
          }
        }
        outfile << "...}"
                << "\n";
      }
      set_resultado.clear();
    } break;

    case 10: {
      int posicionFicheroOut;
      vector<string> l_resultado;
      outfile << "{";
      l_resultado = Lenguaje::cierre_kleene(l_1);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      if (l_resultado.size() < 10) {
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          outfile << *it << ",";
        }
        if (!set_resultado.empty()) {
          posicionFicheroOut = outfile.tellp();
          outfile.seekp(posicionFicheroOut - 1);
        }
        outfile << '}' << "\n";
      } else {
        int contador = 0;
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          if (contador == 10) {
            break;
          } else {
            outfile << *it << ",";
            contador++;
          }
        }
        outfile << "...}"
                << "\n";
      }
      set_resultado.clear();
      outfile << "{";
      l_resultado = Lenguaje::cierre_kleene(l_2);
      set_resultado = Lenguaje::cambioSet(l_resultado);
      if (l_resultado.size() < 10) {
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          outfile << *it << ",";
        }
        if (!set_resultado.empty()) {
          posicionFicheroOut = outfile.tellp();
          outfile.seekp(posicionFicheroOut - 1);
        }
        outfile << '}' << "\n";
      } else {
        int contador = 0;
        for (it = set_resultado.begin(); it != set_resultado.end(); ++it) {
          if (contador == 10) {
            break;
          } else {
            outfile << *it << ",";
            contador++;
          }
        }
        outfile << "...}"
                << "\n";
      }
      set_resultado.clear();
    } break;
  }
}

vector<string> Lenguaje::concatenacion(vector<string> l_1_,
                                       vector<string> l_2_) {
  Cadena auxiliar("test");
  vector<string> l_result;
  for (int i = 0; i < l_1_.size(); i++) {
    for (int k = 0; k < l_2_.size(); k++) {
      if ((l_2_[k] == "&") && (l_1_[i] == "&")) {
        l_result.push_back(l_1_[i]);
      } else if ((l_2_[k] == "&")) {
        l_result.push_back(l_1_[i]);
      } else if ((l_1_[i] == "&")) {
        l_result.push_back(l_2_[k]);
      } else {
        auxiliar.setChain(auxiliar.concatenacion(l_1_[i], l_2_[k]));
        l_result.push_back(auxiliar.getChain());
      }
    }
  }
  return l_result;
}

vector<string> Lenguaje::union_(vector<string> l_1, vector<string> l_2) {
  vector<string> l_resultado;
  for (int i = 0; i < l_1.size(); i++) {
    l_2.push_back(l_1[i]);
  }
  l_resultado = l_2;
  return l_resultado;
}

vector<string> Lenguaje::interseccion(vector<string> l_1, vector<string> l_2) {
  vector<string> l_resultado;
  for (int i = 0; i < l_1.size(); i++) {
    for (int k = 0; k < l_2.size(); k++) {
      if (l_1[i] == l_2[k]) {
        l_resultado.push_back(l_2[k]);
      }
    }
  }
  return l_resultado;
}

vector<string> Lenguaje::diferencia(vector<string> l_1, vector<string> l_2) {
  vector<string> l_resultado;
  for (int i = 0; i < l_1.size(); i++) {
    for (int j = 0; j < l_2.size(); j++) {
      if (l_1[i] == l_2[j]) {
        l_1.erase(l_1.begin() + i);
      }
    }
  }
  l_resultado = l_1;
  return l_resultado;
}

bool Lenguaje::sublenguaje(vector<string> l_1, vector<string> l_2) {
  int contador = 0;
  for (int i = 0; i < l_1.size(); i++) {
    for (int j = 0; j < l_2.size(); j++) {
      if (l_1[i] == l_2[j]) {
        contador++;
      }
    }
  }
  if (contador == l_1.size()) {
    return true;
  } else {
    return false;
  }
}

bool Lenguaje::igualdad(vector<string> l_1, vector<string> l_2) {
  bool condicion_1, condicion_2;
  condicion_1 = Lenguaje::sublenguaje(l_1, l_2);
  condicion_2 = Lenguaje::sublenguaje(l_2, l_1);
  if ((condicion_1) && (condicion_2)) {
    return true;
  } else {
    return false;
  }
}

vector<string> Lenguaje::inversa(vector<string> l_1) {
  vector<string> l_resultado;
  Cadena auxiliar("test");
  for (int i = 0; i < l_1.size(); i++) {
    auxiliar.setChain(auxiliar.inversa(l_1[i]));
    l_resultado.push_back(auxiliar.getChain());
  }
  return l_resultado;
}

vector<string> Lenguaje::potencia(vector<string> l_1, int exponente = 0) {
  vector<string> l_resultado;
  if (exponente == 0) {
    l_resultado.push_back("&");
    return l_resultado;
  } else if (exponente == 1) {
    l_resultado = l_1;
    return l_resultado;
  } else {
    l_resultado = l_1;
    l_resultado = Lenguaje::potencia(l_resultado, exponente - 1);
    l_resultado = Lenguaje::concatenacion(l_resultado, l_1);
    return l_resultado;
  }
}

vector<string> Lenguaje::cierre_kleene(vector<string> l_1) {
  vector<string> l_resultado, l_aux;
  for (int i = 0; i < 4; i++) {
    l_aux = Lenguaje::potencia(l_1, i);
    l_resultado = Lenguaje::union_(l_resultado, l_aux);
  }
  return l_resultado;
}

vector<string> Lenguaje::cierre_positivo(vector<string> l_1) {
  vector<string> l_resultado, l_aux;
  for (int i = 1; i < 4; i++) {
    l_aux = Lenguaje::potencia(l_1, i);
    l_resultado = Lenguaje::union_(l_resultado, l_aux);
  }
  return l_resultado;
}

set<string> Lenguaje::cambioSet(vector<string> l_1) {
  for (int i = 0; i < l_1.size(); i++) {
    set_resultado.insert(l_1[i]);
  }
  return set_resultado;
}