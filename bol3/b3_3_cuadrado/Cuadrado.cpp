/*************************************************************/ 
/*      AUTOR: Francisco Amoros Cubells                      */ 
/*      CURSO: Primero, Ingenieria Informatica               */ 
/*     NOMBRE:  Cuadrado.cpp                                 */ 
/*                                                           */ 
/*  PROPÓSITO: Comprobar Si una matriz es un cuadrado magico */ 
/*                                                           */ 
/*************************************************************/

#include <iostream>
using namespace std;

const int MAX = 10;
typedef bool Conjunto[ MAX * MAX + 1];
typedef int Cuadrado[MAX][MAX];


bool ComprobarCuadrado (Cuadrado, int);
int SumarFila (Cuadrado , int, int );
int SumarColumna (Cuadrado , int, int );
int SumarDiagonal1 (Cuadrado , int );
int SumarDiagonal2 (Cuadrado , int );

int main(void)
{
	int tam;
	Cuadrado cuad;
	bool es_magico;

	cout << "Hola, este programa te pide que introduzcas una matriz y comprueba si es un cuadrado mágico o no." << endl;
	cout << "Introduzca el tamanyo de la matriz : ";
	cin >> tam;

	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j < tam; ++j)
		{
			cout << "Introduce el valor de la matriz en el indice " << i << ", " << j << " : ";
			cin >> cuad[i][j];
		}
	}

	es_magico = ComprobarCuadrado ( cuad, tam );

	if (es_magico == true)
		cout << "El Cuadrado magico Introducido es correcto";
	else
		cout << "El Cuadrado magico Introducido no es correcto";



	return 0;
}

bool ComprobarCuadrado (Cuadrado cuadr, int tamanyo)
{
	Conjunto c;
	int sum_f, sum_c, sum_d, sum_d2;
	bool hay_repetidos = true, es_m = false;

	for (int i = 0; i < ( MAX * MAX + 1); ++i)
	{
		c[i] = false;
	}

	for (int i = 1; i < (tamanyo * tamanyo +1); ++i)
	{
		for (int j = 0; j < tamanyo; ++j)
		{
			for (int k = 0; k < tamanyo; ++k)
			{
				if (i == cuadr[j][k])
				{
					c[i] = true;
				}
			}
		}
	}

	for (int i = 1; i < (tamanyo * tamanyo +1); ++i)
	{
		if (c[i] == false)
		{
			hay_repetidos = false;
		}
	}

	if (hay_repetidos == true)
	{
		for (int i = 0; i < tamanyo; ++i)
		{
			sum_f = SumarFila (cuadr, i, tamanyo);
			sum_c = SumarColumna (cuadr, i, tamanyo);
			sum_d = SumarDiagonal1 (cuadr, tamanyo);
			sum_d2 = SumarDiagonal2 (cuadr, tamanyo);

			if (sum_f && sum_c && sum_d && sum_d2 )
				es_m = true;

			else
				es_m = false;

		}
    }
		return es_m;
}

	int SumarFila (Cuadrado c , int x , int tamanyo )
	{
		int sumatori = 0;

		for (int i = 0; i < tamanyo; ++i)
		{
			sumatori += c[i][x];
		}

		return sumatori;
	}

	int SumarColumna (Cuadrado c , int x , int tamanyo )
	{
		int sumatori = 0;

		for (int i = 0; i < tamanyo; ++i)
		{
			sumatori += c[x][i];
		}

		return sumatori;
	}

	int SumarDiagonal1 (Cuadrado c , int tam )
	{
		int sumatori = 0;

		for (int i = 0; i < tam; ++i)
		{
			sumatori += c[i][i];
		}

		return sumatori;
	}

	int SumarDiagonal2 (Cuadrado c , int tam )
	{
		int sumatori = 0;
		int x = tam;
		for (int i = 0; i < tam; ++i)
		{
			x--;
			sumatori += c[i][x];
		}

		return sumatori;
	}
