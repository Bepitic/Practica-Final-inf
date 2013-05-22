/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  main.cpp                                     */
/*                                                           */
/*  PROPÓSITO:  Un programa que sea capaz de leer            */
/*              la informacion de las montanas del           */
/*              fichero ‘montanas.txt’ y introduzca          */
/*              una montana que no este repetida.            */
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
Montana New_Monta ( );
void Escribir_Monta(ofstream &, Montana);

int main(void)
{
	Montana montana, nueva_montana;
	ifstream f_i_mon;
	ofstream f_o_mon;
	bool repetida = false;
	f_i_mon.open(NOM_FICH.c_str());
    
	cout << "Hola, este programa agrega una nueva montana (si no esta repetida) al fichero montanas.txt" << endl;
    
	cout << "Introduce una nueva montana :" << endl;
    
	nueva_montana = New_Monta();
    
	if (!f_i_mon)
		cout << "Error abriendo fichero.\n";
	else
	{
		while(LeerMontana( f_i_mon, montana))
			if (montana.nombre == nueva_montana.nombre)
				repetida = true;
        
        f_i_mon.close();
    }
    
    f_o_mon.open(NOM_FICH.c_str(), ios::app);
    
    if (!f_o_mon)
        cout << "Error abriendo fichero.\n";
    else
    {
        if (repetida == false)
            Escribir_Monta(f_o_mon, nueva_montana);
        
        f_o_mon.close();
    }
    
    return 0;
}

/**********************************************************
 * Funcion New_Monta
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * void
 *
 * Valor devuelto:
 * Una Variable Montana
 ***********************************************************/

Montana New_Monta ( )
{
 	Montana m;
 	int num_paises;
 	char separa_pal = '_', separa_pais = '/';
 	string pais, lat, lon;
    
 	cout << "Introduce, nombre de la montanya: ";
 	cin >> m.nombre ;
    
 	cout << "Introduce, altura de la montanya: ";
 	cin >> m.altura ;
    
 	cout << "Introduce, indice de la montanya: ";
 	cin >> m.indice ;
    
 	cout << "Cuantos paises contiene la montanya: ";
 	cin >> num_paises;
    
 	cin.ignore();
 	
 	for (int i = 0; i < num_paises; ++i)
 	{
 		cout << "Introduce Pais " << i << " : ";
 		getline(cin, pais);
        
 		for (int i = 0; i < pais.length(); ++i)
 			if ( pais[i] == ' ' )
 				pais[i] = separa_pal;
        
        m.pais_es += pais;
        if ( (i == num_paises -1) == false )
            m.pais_es += separa_pais;
	}
    
    cout << "Introduce, latitud y longitud de la montanya ( ej : 1 1 1 N  1 1 1 E ) : ";
 	getline(cin, m.lat_lon);
    
    return m;
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

/**********************************************************
 * Funcion Escribir_Monta
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * f_mon       S        Fichero de escritura
 * m           E        Estructura de datos a Escribir
 *
 * Valor devuelto:
 * voids
 ***********************************************************/

void Escribir_Monta(ofstream &f_mon, Montana m )
{
 	f_mon << endl;
 	f_mon << m.indice << ' ';
 	f_mon << m.nombre << ' ';
 	f_mon << m.altura << ' ';
 	f_mon << m.pais_es << ' ';
 	f_mon << m.lat_lon;
    
 	return;
}