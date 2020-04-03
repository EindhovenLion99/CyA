#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include "complex_t.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  if(argv[1] == NULL || argv[2] == NULL)
  {
     cout << "No hay suficientes argumentos" << endl;
  }else
  {
     ifstream Fich_Entrada(argv[1]);
     ofstream Fich_Salida(argv[2]);

     int real, imag, real1, imag1;
     char oper, oper1;
     char i, i2;

     complex_t a; complex_t b;

     if(!Fich_Entrada.is_open() || !Fich_Salida.is_open())
     {
        cout << "Fallo en los archivos" << endl;
        exit(1);
     }else
     {
        while(Fich_Entrada >> real >> oper >> imag >> i >> real1 >> oper1 >> imag1 >> i)
        {
           a.set_real(real); a.set_oper(oper); a.set_imag(imag);
           b.set_real(real1); b.set_oper(oper1); b.set_imag(imag1);

           complex_t sum = a.add(b);

           Fich_Salida << "Suma de Complejos" << endl << endl;
           a.write(Fich_Salida); Fich_Salida << " + "; b.write(Fich_Salida);
           Fich_Salida  << " = ";
           sum.write(Fich_Salida);
           Fich_Salida << endl;
        }
        Fich_Entrada.close();
        Fich_Salida.close();
     }
   }
}
