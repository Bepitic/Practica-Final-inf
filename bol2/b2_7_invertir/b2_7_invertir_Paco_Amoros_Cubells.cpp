/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  b2_7_invertir_Paco_Amoros_Cubells.cpp        */
/*                                                           */
/*  PROPÓSITO:  Este programa invierte un numero introducido */
/*              por teclado mediante una funcion recursiva   */
/*                                                           */
/*************************************************************/

#include <iostream>

using namespace std;

int Multiplicador ( int mult );
int Invierte ( int x);

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
 * La funcion Multiplicador cambia la primera cifra
 * (la mas significativa), del numero entrante por 1
 * y hace el resto de cifras 0
 *
 */



int Multiplicador ( int num )
{
    int mult = 1;
    
    while (num > 10)
    {
        num /= 10;
        mult *= 10;
    }
    
    return mult;
}



/*
 * La funcion Invierte,
 * invierte de manera recursiva el numero entrante
 *
 */

int Invierte (int num )
{
    if (num < 10)
    {
        num %= 10;
    }
    else
    {
        num =  ((num % 10) * Multiplicador(num) ) + Invierte(num / 10);
    }
    
    return num;
}
