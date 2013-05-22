/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  main.cpp                                     */
/*                                                           */
/*  PROPÓSITO:  Una modificacion del programa b4_3_montanas  */
/*              que almacena las alturas en un fichero .bin  */
/*              y en un fichero.txt                          */
/*************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string NOM_FICH = "montanas.txt";
const string NOM_FICH_ALTURAS_BIN = "alturas.bin";
const string NOM_FICH_ALTURAS_TXT = "alturas.txt";

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
	int numero_de_alturas = 0;
	Montana montana;
	ifstream f_mon;
	ofstream alt_bin;
	ofstream alt_txt;
    
	cout << "Hola este programa lee el archivo (montanas.txt), cuenta todas las alturas";
	cout << "y las guarda en alturas.txt y alturas.bin " << endl;
    
	f_mon.open(NOM_FICH.c_str());
	alt_txt.open(NOM_FICH_ALTURAS_TXT.c_str());
	alt_bin.open(NOM_FICH_ALTURAS_BIN.c_str(), ios::binary);
    
	if (!f_mon || !alt_bin || !alt_txt)
		cout << "Error abriendo fichero.\n";
	else
	{
		while(LeerMontana( f_mon, montana))
		{
			numero_de_alturas++;
			alt_bin.write((char *)(& montana.altura), sizeof(montana.altura) );
			alt_txt << montana.altura << endl;
		}
        
		cout << "El numero total de alturas del fichero es :" << numero_de_alturas << endl;
        
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
	f_mon >> mont.indice;
	f_mon >> mont.nombre;
	f_mon >> mont.altura;
	f_mon >> mont.pais_es;
	getline(f_mon, mont.lat_lon);
    
	return !(f_mon.eof());
}