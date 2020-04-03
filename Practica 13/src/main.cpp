#include <cstdio>
#include <iostream>
#include <random>
#include <vector>

#include "sorted_vector_t.h"

#define LIMIT 999
#define SIZE 10

using namespace std;

int main(void) {
  default_random_engine generator;  // GENERADOR
  uniform_int_distribution<int> distribution(
      -LIMIT, LIMIT);  // Distribucion de numeros aleatorios

  CyA::sorted_vector_t v;  // Creamos el vector

  for (int i = 0; i < SIZE; i++) {
    v.push_back(
        distribution(generator));  // Añadimos valores aleatorios al vector
  }

  cout << v << endl;  // Imprimimos el vector sin ordenar

  v.merge_sort();  // Llamamos a merge sort, para que ordene

  cout << v << endl;  // Imprimimos el vector ordenado

  return 0;
}
