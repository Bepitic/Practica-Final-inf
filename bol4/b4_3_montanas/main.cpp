/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  main.cpp                                     */
/*                                                           */
/*  PROPÓSITO:  Un programa que sea capaz de leer            */
/*              la informacion de las montanas del           */
/*              fichero ‘montanas.txt’ y muestre             */
/*              la informacion por pantalla.                 */
/*************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string NOM_FICH = "montanas.txt";

struct Montana
{
	int indice;
	string nombre;
	unsigned int altura;
	string pais_es;
	string lat_lon;
};

bool LeerMontana( ifstream &, Montana &);
void MostrarMontana( Montana );

int main(void)
{
	Montana montana;
	ifstream f_mon;
	f_mon.open( NOM_FICH.c_str() );
    
	if (!f_mon)
		cout << "Error abriendo fichero.\n";
	else
	{
		while(LeerMontana( f_mon, montana ))
			MostrarMontana( montana );
        
		f_mon.close();
	}
    
	return 0;
}

/**********************************************************
 * Funcion MostrarMontana
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * mont		  E 	   Variable a mostrar
 *
 * Valor devuelto:
 * void
 ***********************************************************/

void MostrarMontana( Montana mont )
{
    
	cout << " |--------------------------------------| " << endl;
	cout << " Nombre Montanya: " << mont.nombre << endl;
 	cout << " Altura: " << mont.altura << endl;
 	cout << " Indice: " << mont.indice << endl;
 	cout << " Pais o paises: " << mont.pais_es << endl;
 	cout << " Latitud y Longitud: " << mont.lat_lon << endl;
	cout << " |--------------------------------------| " << endl;
	cout << endl;
    
	return;
}

/**********************************************************
 * Funcion LeerMontana
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * f_mon       S       fichero para sacar informacion
 * mont  	  S       variable donde guardar la informacion
 *
 * Valor devuelto:
 * bool para saber si el fichero ha acabado o no
 ***********************************************************/

bool LeerMontana( ifstream &f_mon, Montana &mont )
{
	f_mon >> mont.indice;
	f_mon >> mont.nombre;
	f_mon >> mont.altura;
	f_mon >> mont.pais_es;
	getline( f_mon, mont.lat_lon );
    
	return !( f_mon.eof() );
}