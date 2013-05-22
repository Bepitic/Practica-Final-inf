/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  b2_2_perfecto2_Paco_Amoros_Cubells.cpp       */
/*                                                           */
/*  PROPÓSITO:  Calcula la suma de los 100 primeros,         */
/*              numeros defectivos.                          */
/*                                                           */
/*************************************************************/



#include <iostream>
using namespace std;

int NumeroPerfecto (int numero);

int main(int argc, const char * argv[])
{
    
    int num_dividir, dividendos, sum_num_divid, cont_num;
    
    num_dividir = 0;
    cont_num = 0;
    sum_num_divid = 0;
    while (cont_num < 100)
    {
        ++num_dividir;
        dividendos = NumeroPerfecto( num_dividir );
        
        if (num_dividir < dividendos)
        {
            ++cont_num;
            sum_num_divid += num_dividir;
        }
    }
    cout << " la suma de los 100 primeros numeros defectivos es: " << sum_num_divid << endl;
    
    return 0;
}



/*
 *
 * Calcula el sumatorio del numero de
 * divisores de un numero sin sumar el propio
 *
 */



int NumeroPerfecto (int numero)
{
    int a , va_perf=0;
    
    for (a = 1 ; a < numero ; ++a)
    {
        if (numero % a == 0)
        {
            va_perf += a ;
        }
    }
    
    return va_perf;
}