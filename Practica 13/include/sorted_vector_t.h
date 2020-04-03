#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace CyA {

class sorted_vector_t : public vector<int> {     // Clase Vector ordenado en el namespace cya
 public:
  sorted_vector_t(void) : vector<int>() {}       // Constructor por defecto

  sorted_vector_t(const vector<int>& v) : vector<int>(v) {}   // Constructor parametrizado

  ~sorted_vector_t(void) {}                      // Destructor

  void merge_sort(void);                         // Funcion merge sort (FUNCION PRINCIPAL DE ORDENACION)

  void write(ostream& os) const;                 // Funcion write

 private:
  void create_vector_sentinel(int l, int r, vector<int>& v);          // Crea el vector sentinela
  void merge(const vector<int>& v1, const vector<int>& v2, int l);    // Funcion merge
  void merge_sort_iterative(int r);                                   // Funcion merge iterativa

  void merge_sort(int l, int r);
  void merge(int l, int c, int d);
};

}  // namespace CyA

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v);