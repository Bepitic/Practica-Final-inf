/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  main.cpp                                     */
/*                                                           */
/*  PROPÓSITO:  Que el usuario introduzca dos alturas y      */
/*              retorne el porcentaje de alturas que         */
/*              existen entre esas dos variables             */
/*              las alturas las saca del fichero alturas.bin */
/*************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string NOM_FICH_ALTURAS_BIN = "alturas.bin";

struct Montana
{
	int indice;
	string nombre;
	unsigned int altura;
	string pais_es;
	string lat_lon;
};

bool LeerMontana( ifstream &, Montana &);

int main(void)
{
	int altura1, altura2, altura_reserv;
	float porcent_tot = 0, numero_de_alturas = 0, entre_alturas = 0;
	Montana montana;
	ifstream f_mon;
	ofstream alt_bin;
	ofstream alt_txt;
    
	cout << "Hola este programa pide al usuario que introduzca dos alturas y saca el porcentaje";
	cout << "de alturas contenidas , comparandolas con el alturas.bin" << endl;
    
	f_mon.open(NOM_FICH_ALTURAS_BIN.c_str(), ios::binary );
    
	cout << "Por vavor introduce, una altura: ";
	cin >> altura1;
	cout << "Por vavor introduce, otra altura: ";
	cin >> altura2;
    
	if (altura2 > altura1)
	{
		altura_reserv = altura1;
		altura1 = altura2;
		altura2 = altura_reserv;
	}
    
	if (!f_mon || !alt_bin || !alt_txt)
		cout << "Error abriendo fichero.\n";
	else
	{
		while(LeerMontana( f_mon, montana))
		{
			numero_de_alturas++;
			if ( altura1 >= montana.altura && montana.altura >= altura2 )
				entre_alturas++;
		}
		porcent_tot = ((entre_alturas * 100) / numero_de_alturas);
		cout << "El porcentaje de alturas es : " << porcent_tot << "% " << endl;
        
		f_mon.close();
		alt_bin.close();
		alt_txt.close();
	}
    
	return 0;
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

bool LeerMontana(ifstream &f_mon, Montana &mont )
{
	f_mon.read((char *)(& mont.altura), sizeof(mont.altura) );
    
	return !(f_mon.eof());
}