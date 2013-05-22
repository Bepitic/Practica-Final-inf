/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria industrial                */
/*     NOMBRE:  b2_5_decbinoct_Paco_Amoros_Cubells.cpp       */
/*                                                           */
/*  PROPÓSITO:  Hace el cambio de decimal a binario          */
/*              y de decimal a Octal                         */
/*                                                           */
/*************************************************************/

#include <iostream>

using namespace std;

long long Dec_Bin_Oct (int x, int);

int main(void)
{
	int num_dec, x;
	cout << "Hola, este programa, pide un numero en base decimal y te permite pasarlo a binario o a octal. " << endl;
	cout << "Por favor, introduce un numero en base decimal : ";
	cin >> num_dec;
	cout << "A que quieres que pase el numero ( con base decimal ), \n 1 - Binario  \n 2 - Octal \n";
    cin >> x;
	switch (x)
	{
		case 1 :
            cout << " El numero (" << num_dec << ") en Binario es : \n" << Dec_Bin_Oct ( num_dec, 2 );
            break;
            
		case 2:
            cout << " El numero (" << num_dec << ") en Octal es : \n" << Dec_Bin_Oct ( num_dec, 8 );
            break;
            
		default:
            break;
	}
    
    return 0;
}

/*
 * La funcion Dec_Bin_Oct pasa el
 * numero entrante de decimal a binario o a octal.
 *
 */

long long Dec_Bin_Oct (int x, int div)
{
    long long num_bin = 0 ;
    
	if (x != 0)
	{
        num_bin = Dec_Bin_Oct ( x / div, div );
        num_bin *= 10;
        num_bin = num_bin + (x % div);        
	}
    
    return (num_bin);
}