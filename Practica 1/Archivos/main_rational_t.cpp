#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include "rational_t.hpp"

using namespace std;


int main(int argc, char* argv[])
{

    if(argv[1] == NULL || argv[2] == NULL)
    {
        cout << "No hay suficientes argumentos, introduzca el fichero de entrada y/o de salida" << endl;
    }else
    {
        
        char *Fich_Entrada = argv[1];
        char *Fich_Salida = argv[2];

        rational_t A;
        rational_t B;

        A.Fichero_E_S(Fich_Entrada, Fich_Salida, B);

        /*

        ifstream Fich_Entrada(argv[1]);
        ofstream Fich_Salida(argv[2]);

        char d;

        int num1; int den1; int num2; int den2, cont = 1; // Numeradores y Denominadores del fichero

        rational_t a; rational_t b;             // A y B

        if(!Fich_Entrada.is_open() || !Fich_Salida.is_open())
        {
          cout << "Fallo en los archivos" << endl;
          exit(1);
        }else
        {
          while(Fich_Entrada >> num1 >> d >> den1 >> num2 >> d >> den2)
          {
              a.set_num(num1); a.set_den(den1); b.set_num(num2); b.set_den(den2);
              rational_t sum = a + b; rational_t sub = a - b; rational_t mul = a * b; rational_t div = a / b;

              { 
              cout << "Primera Fraccion: "; a.write();
              cout << "Segunda Fraccion: "; b.write(); cout << endl;

              cout << "Comparacion: " << endl;

              if(a > b){ a.writ(); cout << " es mayor que "; b.write();}
              if(a < b){ a.writ(); cout << " es menor que "; b.write();}
              if(a == b){ a.writ(); cout << " es igual que "; b.write();}

              cout << "Operaciones: " << endl;

              a.writ(); cout << " + "; b.writ(); cout << " = "; sum.writ(); cout << endl;
              a.writ(); cout << " - "; b.writ(); cout << " = "; sub.writ(); cout << endl;
              a.writ(); cout << " * "; b.writ(); cout << " = "; mul.writ(); cout << endl;
              a.writ(); cout << " / "; b.writ(); cout << " = "; div.writ(); cout << endl << endl;

              cout << endl; 
              }

              // IMPRIMIMOS EN EL FICHERO DE SALIDA

              Fich_Salida << " ***** Par de fracciones " << cont << ": *****" << endl << endl;
              cont++;
              a.writ(Fich_Salida); Fich_Salida << " "; b.writ(Fich_Salida); Fich_Salida << endl << endl;

              Fich_Salida << endl << "Comparacion: " << endl << endl;

              if(a > b){ a.writ(Fich_Salida); Fich_Salida  << " es mayor que "; b.write(Fich_Salida);}
              if(a < b){ a.writ(Fich_Salida); Fich_Salida  << " es menor que "; b.write(Fich_Salida);}
              if(a == b){ a.writ(Fich_Salida); Fich_Salida  << " es igual que "; b.write(Fich_Salida);}

              Fich_Salida  << endl << "Operaciones: " << endl << endl;

              a.writ(Fich_Salida); Fich_Salida << " + "; b.writ(Fich_Salida); Fich_Salida << " = "; sum.writ(Fich_Salida); Fich_Salida << endl;
              a.writ(Fich_Salida); Fich_Salida << " - "; b.writ(Fich_Salida); Fich_Salida << " = "; sub.writ(Fich_Salida); Fich_Salida << endl;
              a.writ(Fich_Salida); Fich_Salida << " * "; b.writ(Fich_Salida); Fich_Salida << " = "; mul.writ(Fich_Salida); Fich_Salida << endl;
              a.writ(Fich_Salida); Fich_Salida << " / "; b.writ(Fich_Salida); Fich_Salida << " = "; div.writ(Fich_Salida); Fich_Salida << endl << endl;


          }
          Fich_Entrada.close();
          Fich_Salida.close();
        }
      */
    }
    cout << "Ejecutando operaciones..." << endl;
    cout << "El archivo ha sido modificado con exito" << endl << endl;
    return 0;

}



