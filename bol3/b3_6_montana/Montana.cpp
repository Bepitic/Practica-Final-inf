//
//  main.cpp
//  b3_6_montana
//
//  Created by Paco Amoros on 30/11/12.
//  Copyright (c) 2012 Paco Amoros. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;



struct Lat_Lon
{
	float a;
	float b;
	float c;
	char x;
};

struct Dia_Mes_Anyo
{
	int dia;
	int mes;
	int anyo;

};

struct Mont
{
	string nombremont;
	int altura;
	int indice;
	string pais_es;
	Lat_Lon latitud;
	Lat_Lon longitud;
	Dia_Mes_Anyo fecha;
};

Mont New_Monta (  );
void Leer_Monta ( Mont );

int main(void)
{
	Mont mo;
	
	mo = New_Monta ();
	Leer_Monta ( mo );
	
	return 0;
}

Mont New_Monta ( )
{
	Mont m;
	int num_paises;
	char separa_pal = '_', separa_pais = '/';
	string pais;

	cout << "Introduce, nombre de la montanya: ";
	cin >> m.nombremont ;
	
	cout << "Introduce, altura de la montanya: ";
	cin >> m.altura ;
	
	cout << "Introduce, indice de la montanya: ";
	cin >> m.indice ;
	
	cout << "Cuantos paises contiene la montanya: ";
	cin >> num_paises;

	for (int i = 0; i < num_paises; ++i)
	{
		cout << "Introduce Pais " << i << " : ";
		cin >> pais;

		for (int i = 0; i < pais.length(); ++i)
		{
			if ( pais[i] == ' ' )
			{
				pais[i] = separa_pal;
			}
		}

		m.pais_es += pais;
		m.pais_es += separa_pais;

	}
	
	cout << "Introduce, longitud de la montanya : ";
	cin >> m.longitud.a >> m.longitud.b >> m.longitud.c >> m.longitud.x;
	
	cout << "Introduce, latitud de la montanya : ";
	cin >> m.latitud.a >> m.latitud.b >> m.latitud.c >> m.latitud.x  ;
	
	cout << "Introduce, fecha de la montanya: ";
	cin >> m.fecha.dia >> m.fecha.mes >> m.fecha.anyo;

	return m;
}

void Leer_Monta ( Mont m )
{
	cout << " Nombre Montanya: " << m.nombremont << endl;
 	cout << " Altura: " << m.altura << endl;
 	cout << " Indice: " << m.indice << endl;
 	cout << " Pais o paises: " << m.pais_es << endl;
 	cout << " Longitud: " << m.longitud.a << " " << m.longitud.b << " " << m.longitud.c << " " << m.longitud.x << endl;
 	cout << " Latitud: " << m.latitud.a << " " << m.latitud.b << " " << m.latitud.c << " " << m.latitud.x << endl;
 	cout << " Fecha: " << m.fecha.dia << " " << m.fecha.mes << " " << m.fecha.anyo << endl;

	return;
}




