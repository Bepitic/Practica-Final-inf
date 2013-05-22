/*************************************************************/ 
/*      AUTOR: Francisco Amoros Cubells                      */ 
/*      CURSO: Primero, Ingenieria Informatica               */ 
/*     NOMBRE:  Rutas.cpp                                    */ 
/*                                                           */ 
/*  PROPÓSITO:   */ 
/*                                                           */ 
/*************************************************************/



#include <iostream>

struct Lat_Lon
{
	float a;
	float b;
	float c;
	char x;
};
struct Fecha
{
	int dia;
	int mes;
	int anyo;
};
struct Tiempo
{
	int horas;
	int minutos;
	int segundos;
};

struct Baliza
{
	Lat_Lon latitud;
	Lat_Lon longitud;
	float velocidad;
	Tiempo hora;	
};

const int MAX = 48;
typedef Baliza Balizas[MAX];

struct Camion
{
	Balizas emision;
	Fecha fechas;

};
const int MAX1 = 100;
typedef Camion Camiones[MAX1];

Camiones Nuevo_Camion(Camion);


int main(void)
{
	


	return 0;
}


Camiones Nuevo_Camion(Camion c)
{
	int numero_emisiones;
	cout << "Introduce, fecha del camion ( ej: dia mes anyo ) : " ;
	cin >> c.fechas;

	cout << "Cuantas veces ha emitido la baliza del camion :";
	cin >> numero_emisiones;

	for (int i = 0; i < numero_emisiones; ++i)
	{
		cout << "Introduce latitud  ( ej : 2 3 5.2 O ) : ";
		cin >> c.emision.latitud;

		cout << "Introduce longitud ( ej : 2 3 5.2 N ) : ";
		cin >> c.emision.longitud;

		cout << "Introduce velocidad:";
		cin >> c.emision.velocidad;

		cout << "Introduce hora ( ej : hora minutos segundos ) : ";
		cin >> c.emision.hora;
	}


}
