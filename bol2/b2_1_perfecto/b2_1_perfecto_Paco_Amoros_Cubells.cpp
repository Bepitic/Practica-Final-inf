/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  b2_1_perfecto_Paco_Amoros_Cubells.cpp        */
/*                                                           */
/*  PROPÓSITO:  Da como resultado si un numero es perfecto   */
/*              abundante o defectivo.                       */
/*                                                           */
/*************************************************************/




#include <iostream>
using namespace std;

int SumaDiv ( int numero );

int main(void)
{
    /*
     * Variable num es el numero que el usuario introduces y ,
     * la variable va_per es el sumatorio del numero de divisores
     * de num, sin sumar el propio.
     */
    int num, va_per;
    
    cout << " Este programa nos dice si un numero entero introducido por teclado es perfecto, abundante o defectivo.  " << endl;
    do
    {
        cout << " Dame numero (introduce 0 para salir): " << endl;
        cin >> num ;
        va_per = SumaDiv(num);
        if(num == va_per)
        {
            cout << "El numero " << num << " es perfecto. " << endl;
        }
        else if (num < va_per)
        {
            cout << "El numero " << num << " es abundante. " << endl;
        }
        else if (num > va_per)
        {
            cout << "El numero " << num << " es defectivo. " << endl;
        }
    }
    while ( num != 0);
    
    return 0;
}



/*
 *
 * Calcula el sumatorio del numero de
 * divisores de un sin sumar el propio.
 *
 */

int SumaDiv (int numero)
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
