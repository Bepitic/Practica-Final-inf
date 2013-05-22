//
//  main.cpp
//  b3_6_montana
//

//  También se mostrará toda la información de las montañas escaladas en el mismo año.
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

const int MAX = 20;
typedef Mont Montanya[MAX];

Mont New_Monta (  );
void Leer_Monta ( Mont );
int PrimeraEscalada ( Montanya , int );
void MontDelMismoAnyo (Montanya, int );

int main(void)
{
	int numero_mont, primera;
	Montanya mo;
    
	Mont m;
    
	cout << "Cuantas montanyas desea introducir: ";
	cin >> numero_mont;
    
	for (int i = 0; i < numero_mont; ++i)
	{
		m = New_Monta ( );
		mo[i] = m;
	}
    
	primera = PrimeraEscalada ( mo , numero_mont );
	cout << "La primera montanya escalada es : \n \n";
	Leer_Monta(mo[primera]);
    
    
    
	cout << "\n\n\nLas montanyas del mismo anyo son :";
    
	MontDelMismoAnyo(mo , numero_mont);
    
	
	
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
	 	getline(cin, pais);
        
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
	
    cout << "Introduce, longitud de la montanya ( ej : 2 3 5.2 O ) : ";
    cin >> m.longitud.a >> m.longitud.b >> m.longitud.c >> m.longitud.x;
	
    cout << "Introduce, latitud de la montanya ( ej : 2 3 5.2 N ) : ";
    cin >> m.latitud.a >> m.latitud.b >> m.latitud.c >> m.latitud.x;
	
	cout << "Introduce, fecha de la montanya: ( ej: dia mes anyo ) ";
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

int PrimeraEscalada ( Montanya mont, int num )
{
	int x = 0;
	for (int j = 0; j < num; ++j)
	{
		for (int i = 0; i < num; ++i)
		{
			if ( mont[i].fecha.anyo < mont[x].fecha.anyo )
			{
				x = i;
			}
			if ( mont[i].fecha.anyo == mont[x].fecha.anyo )
			{
				if ( mont[i].fecha.mes < mont[x].fecha.mes )
				{
					x = i;
				}
				
				if ( mont[i].fecha.mes == mont[x].fecha.mes )
				{
					if ( mont[i].fecha.dia < mont[x].fecha.dia )
					{
						x = i;
					}
				}
			}
		}
	}
	return x;
}

void MontDelMismoAnyo (Montanya mont, int num )
{
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			if ( mont[i].fecha.anyo == mont[j].fecha.anyo && i != j )
			{
                cout << endl;
				Leer_Monta (mont[i]);
			}
		}
	}
    
	return;
}