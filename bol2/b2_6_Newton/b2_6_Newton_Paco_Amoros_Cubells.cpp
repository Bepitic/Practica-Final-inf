/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  b2_6_Newton_Paco_Amoros_Cubells.cpp          */
/*                                                           */
/*  PROPÓSITO:  Calcular mediante el metodo de newton        */
/*              un polinomio                                 */
/*                                                           */
/*************************************************************/

#include <iostream>

using namespace std;


float Valor_polinomio( float, float, float, float, float );
float Derivada_Funcion( float, float, float, float, float );
float CalcularCero( float, float, float, float, float );



int main(void)
{
	float cero, a0, a1, a2, a3, error;
	cout << " Hola, este programa, calcula el cero de un polinomio, mediante el metodo, \n de Newton." << endl;
	cout << " Por favor introduce el coeficiente del polinomio en x^3 :";
	cin >> a3;
	cout << " Ahora introduce el coeficiente en x^2: ";
	cin >> a2;
	cout << " Ahora introduce el coeficiente en x: ";
	cin >> a1;
	cout << " Ahora introduce el termino independiente: ";
	cin >> a0;
	cout << " y ahora dame, el error: ";
	cin >> error;
	cero = CalcularCero( a0, a1, a2, a3, error );
	cout << "El resultado es : " << cero << endl;
	
    return 0;
}

/*
 * La Funcion CalcularCero determina la aproximacion de Newton utilizando
 * las funciones 'Valor_polinomio' y 'Derivada_Funcion'.
 *
 */

float CalcularCero( float a0, float a1, float a2, float a3, float error )
{
    float num_punto1, num_punto2;
    
    num_punto1 = Valor_polinomio(a0, a1, a2, a3, error);
    while( num_punto1 != num_punto2 )
    {
    	num_punto2 = Derivada_Funcion( a0, a1, a2, a3, num_punto1 );
    	num_punto1 = Derivada_Funcion( a0, a1, a2, a3, num_punto2 );
    }
    
    return num_punto1;
}



/*
 * La funcion Valor_Polinomio calcula el valor
 * del polinomio en un cierto punto
 *
 */



float Valor_polinomio( float a0, float a1, float a2, float a3, float error )
{
	float num_punto1;
    
	num_punto1 = 3 * a3 * error + 2 * a2 + a1 * error;
    
    return num_punto1;
}



/*
 * La funcion Derivada_Funcion Calcula la derivada del polinomio
 * en un cierto punto
 *
 */



float Derivada_Funcion( float a0, float a1, float a2, float a3, float num_punto1 )
{
	float num_punto2;
    
	num_punto2 = num_punto1 - ( ( a3 * ( num_punto1 * num_punto1 * num_punto1 ) + ( a2 * (num_punto1 * num_punto1) ) + (a1 * num_punto1 ) + a0 ) / ( 3 * a3 * ( num_punto1 * num_punto1  ) + 2 * a2 * num_punto1 + a1 ) );
	
    return num_punto2;
}