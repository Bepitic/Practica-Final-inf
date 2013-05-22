/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  main.cpp                                     */
/*                                                           */
/*  PROPÓSITO:  Lee los enteros de un archivo .bin .         */
/*              nos dice el valor maximo, el minimo y        */
/*              la media (sin usar vectores).                */
/*                                                           */
/*************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void LeerArchivo( string );
bool Nombrecon_BIN ( string );
void LeerArchivo( string ,float &,int &,int &);

int main( void )
{
	string nombre;
	int minimo = 0, maximo = 0;
    float media = 0;
	cout << "Hola, este programa dice el valor maximo, el minimo y la media ";
	cout << "de los elementos de un .bin ." << endl;
	cout << "Introduce el nombre del archivo a leer" << endl;
    
	cin >> nombre;
	LeerArchivo( nombre, media, minimo, maximo );
    
	cout << "La media es : " << media << endl;
	cout << "La minimo es: " << minimo << endl;
	cout << "La maximo es: " << maximo << endl;
    
	return 0;
}

/**********************************************************
 * Funcion LeerArchivo
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * name        E       Nombre del archivo .bin a abrir
 * media       S       Media de los elementos del archivo
 * minimo      S       El elemento con valor mas pequeno del archivo
 * maximo      S       El elemento con valor mas grande del archivo
 *
 * Valor devuelto:
 * void
 ***********************************************************/

void LeerArchivo( string name,float &media,int &minimo,int &maximo )
{
	ifstream f;
	int dato, sumatorio = 0, i = 1;
    
	if ( Nombrecon_BIN( name ) == false)
		name += ".bin";
    
	f.open( name.c_str(), ios::binary);
	if( !f )
		cout << "Error abriendo el fichero" << endl;
	else
	{
		f.read((char *)(& dato), sizeof(dato) );
		minimo = dato;
		maximo = dato;
		sumatorio = dato;
		while(f.read((char *)(& dato), sizeof(dato) ) )
		{
			i++;
			sumatorio += dato;
			if (dato > maximo)
				maximo = dato;
			if (dato < minimo)
				minimo = dato;
		}
		media = (sumatorio / i);
        
		f.close();
	}
	
	return;
}

/**********************************************************
 * Funcion Nombrecon_TXT
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * nombre	  E        Un string para ver si contiene bin  o no
 *
 * Valor devuelto:
 *  Un booleano con true si tiene ".bin" el string,
 * o false si no lo contiene
 ***********************************************************/

bool Nombrecon_BIN (string nombre)
{
 	bool contiene_bin = false;
 	string bin = ".bin";
 	unsigned long x;
    
 	x = nombre.find( bin );
 	if (x > 0 && x < nombre.length())
 		contiene_bin = true;
 	else
 		contiene_bin = false;
    
 	return contiene_bin;
}