#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo

int ejemplo1(const int n) {
  int suma = 0;
  for (int i = 1; i <= n; i++)  // Θ(n)
    suma++;                     // Θ(1)
  return suma;
}

int ejemplo2(const int n) {
  int suma = 0;
  for (int i = 1; i <= n; i++)    // Θ(n)
    for (int j = 1; j <= n; j++)  // Θ(n)
      suma++;                     // Θ(1)
  return suma;
}

int ejemplo3(const int n) {
  int suma = 0;
  for (int i = 1; i <= n; i++)    // Θ(n)
    for (int j = 1; j <= i; j++)  // Θ(i)
      suma++;                     // Θ(1)
  return suma;
}

int ejemplo4(const int n) {
  int suma = 0;
  for (int i = 1; i <= n; i *= 3)  // Θ(log n)
    for (int j = 1; j <= n; j++)   // Θ(n)
      suma++;                      // Θ(1)
  return suma;
}

int ejemplo5(const int n) {
  int suma = 0;
  for (int a = 1; a <= n; a++)
    for (int b = 1; b <= a; b++) suma++;
}

int main() {  // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo 4: " << ejemplo4(n) << endl;
  return 0;
}