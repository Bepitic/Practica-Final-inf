/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE: b2_8_invertir2_Paco_Amoros_Cubells.cpp        */
/*                                                           */
/*  PROPÓSITO: Invierte numeros en una funcion aparte,       */
/*             sin usar la recursividad.                     */
/*                                                           */
/*************************************************************/



#include <iostream>
using namespace std;
int Invierte(int num);

int main (void)
{
    int x;
    cout << "Dame un numero entero: ";
    cin >> x;
    x = Invierte (x);
    cout << "El numero invertido es: " << x;
    return 0;
}



/*
 * La funcion Invierte, en este ejercicio invierte
 * un numero sin usar la recursividad
 *
 */




int Invierte(int num)
{
    int cifra = 0, num_invertido = 0;
    while( num != 0 )
    {
        cifra = num % 10;
        num_invertido = num_invertido * 10 + cifra;
        num = num / 10;
    }
    
    return num_invertido;
}