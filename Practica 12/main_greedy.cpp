/*

El objetivo principal de esta práctica consiste en desarrollar un ejemplo de
Algoritmo Voraz (Greedy) como es el cambio de monedas. Para ello, se detalla a
continuación las clases STL necesarias, los requisitos funcionales mínimos y
opcionales, ejemplo de prueba, y los criterios de evaluación.

*/

// STL
#include <vector>

#include <bits/stdc++.h>
#include <math.h>
#include <iostream>

using namespace std;

void CambioMonedas(float aux) {
  int x = round(aux * 100);
  int auxi2 = x;

  // Inicializamos el conjunto de monedas, desde 1 centimo a 500 euros

  int Conjunto_Monedas[] = {1,   2,    5,    10,   20,    50,    100,  200,
                            500, 1000, 2000, 5000, 10000, 20000, 50000};
  int n = sizeof(Conjunto_Monedas) /
          sizeof(Conjunto_Monedas[0]);  // Longitud del vector Conjunto

  // Inicializamos el vector donde almacenaremos las cantidades adecuadas

  vector<float> Resultado;
  int cont = 0;

  for (int i = n - 1; i >= 0; i--) {  // Metemos las monedas en el vector
    while (x >= Conjunto_Monedas[i]) {
      Resultado.push_back(Conjunto_Monedas[i]);
      x = x - Conjunto_Monedas[i];
      cont++;
    }
  }

  int auxi = 0;
  int cont2 = 1;
  for (unsigned int i = 0; i < Resultado.size();
       i++) {  // Comprobamos que existe la solucion
    auxi += Resultado[i];
  }

  // Imprimimos por pantalla

  if (auxi != auxi2) {
    cout << "No hay solucion" << endl;
  } else {
    cout << "Minimo " << cont << " monedas: " << endl;
    for (unsigned int i = Resultado.size(); i > 0; i--) {
      if (Resultado[i] == Resultado[i - 1]) {
        while (Resultado[i] ==
               Resultado[i - 1]) {  // Si se repite en el vector la misma moneda
          cont2++;
          i--;
        }
        cout << cont2 << "x " << Resultado[i - 1] / 100 << "€ ";
        cont2 = 1;
      } else {
        cout << Resultado[i - 1] / 100 << "€ ";
      }
    }
  }
}

int main() {
  cout << "Practica 12 CyA: Algoritmo greedy. Numero minimo de monedas" << endl;
  cout << endl;

  float Cantidad;

  cout << "Introduzca la cantidad: ";
  cin >> Cantidad;

  CambioMonedas(Cantidad);  // Llamamos a la funcion

  cout << endl;
}