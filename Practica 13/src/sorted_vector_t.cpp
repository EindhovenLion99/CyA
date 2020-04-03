#include "sorted_vector_t.h"

#include <algorithm>  // min y max
#include <climits>
#include <iomanip>

namespace CyA {

void sorted_vector_t::merge_sort(void) {
  merge_sort(0, size() - 1);  // Llama a la función merge_sort pasandole 0 y el
                              // size - 1.
}

void sorted_vector_t::write(ostream& os) const {
  const int sz = size();

  os << "< ";
  for (int i = 0; i < sz; i++) os << setw(5) << at(i);
  os << "> ";
}

void sorted_vector_t::merge_sort(int l, int r) {
  if (l < r) {  // Si l = 0 es menor que el final del vector

    int c = (l + r) / 2;  // Se crea un entero c = 0 + 9 / 2 ..que guarda en c
                          // la distancia media del vector.

    int X = c - l + 1;
    int Y = r - c;
    cout << "X = " << X << endl;
    cout << "Y = " << Y << endl;

    // Llama a la misma función en la que esta de forma recursiva.

    // Va dividiendo la primera parte del vector en partes más pequeñas

    merge_sort(l, c);

    // Va dividiendo la segunda parte del vector en partes más pequeñas

    merge_sort(c + 1, r);

    merge(l, c, r);  // Por último con el vector dividido en partes más pequeñas
                     // llama a la función merge=fusionar, para fusionar el
                     // vector de manera ascendente.
  }
}

// FUSIÓN CON CENTINELA

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v) {
  v.clear();  // Limpia el vector, lo deja vacío.
  for (int i = l; i <= r; i++) {
    v.push_back(at(i));
  }
  v.push_back(INT_MIN);  // Cambio int min para la modificacion  *******************************************
}

void sorted_vector_t::merge(int l, int c, int d) {
  vector<int> v1;                    // Crea un vector v1
  vector<int> v2;                    // Crea un vector v2
  create_vector_sentinel(l, c, v1);  // La primera parte del vector original es
                                     // v1 y se guarda como un vector normal
  create_vector_sentinel(c + 1, d,
                         v2);  // La segunda parte del vector original es v2 y
                               // se guarda como un vector normal a parte de v1
  merge(v1, v2, l);
}

void sorted_vector_t::merge(const vector<int>& v1, const vector<int>& v2,
                            int l) {
  const int sz =
      v1.size() + v2.size() - 2;  // Calcula size de los dos vectores juntos.
  int inx1 = 0;                   // auxiliar
  int inx2 = 0;                   // auxiliar
  for (int i = 0; i < sz; i++)
    if (v1[inx1] > v2[inx2]) {  // Cambio el comparador de menor a mayor *********************************
      at(l + i) = v1[inx1];
      inx1++;

    } else {
      at(l + i) = v2[inx2];
      inx2++;
    }
}
}  // namespace CyA

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v) {
  v.write(os);
  return os;
}
