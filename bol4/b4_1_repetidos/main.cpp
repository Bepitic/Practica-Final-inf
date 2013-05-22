/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  main.cpp                                     */
/*                                                           */
/*  PROPÓSITO:  Realizar un programa que utilizando			 */
/*              funciones lea de un fichero de texto		 */
/*				los elementos de un vector de a lo sumo 	 */
/*				50 enteros, lo muestre, elimine de el los 	 */
/*				elementos repetidos y guarde en un fichero	 */
/*				binario los elementos del vector sin ninguna */
/*				repeticion.  								 */
/*                                                           */
/*************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX = 50;

typedef int Vector[MAX];

int LeerVector(string, Vector);
int EliminarRepetidos ( Vector, int, Vector);
void MostrarVector (Vector, int);
void GuardarVector (Vector, int, string);
bool Nombrecon_TXT (string);
bool Nombrecon_BIN (string);

int main(void)
{
	Vector v, w;
	int num, num2;
	string nombre;
    
	cout << "Dime el nombre del fichero original: ";
	cin >> nombre;
    
	num = LeerVector (nombre, v);
    
	cout << "El vector introducido es: ";
	MostrarVector (v, num);
    
	num2 = EliminarRepetidos (v, num, w);
    
	cout << "El vector sin elementos repetidos es: ";
	MostrarVector (w, num2);
    
	cout << "Dime el nombre del fichero donde guardar el vector: ";
	cin >> nombre;
    
	GuardarVector (w, num2, nombre);
    
    //    system ("PAUSE");
	return 0;
}

/*
 * La Funcion LeerVector, lee de un fichero de texto, cuyo nombre ha sido guardado en un string
 * un grupo de enteros que son guardados en un vector, y tiene como salida el numero
 * de elementos que tiene el vector.
 *
 * Entradas: string (Nombre del Fichero), Vector( el vector a rellenar con los datos del fichero)
 *
 * Salidas: int (el numero de elementos del fichero)
 *
 */

int LeerVector(string nombre, Vector v)
{
 	unsigned int num = 0;
 	ifstream file;
 	if ( Nombrecon_TXT (nombre) == false)
 		nombre += ".txt";
    
 	file.open(nombre.c_str());
    
 	if (!file)
 		cout << " No se ha podido abrir el fichero. "  << endl;
    
 	else
 	{
 		while( file >> v[num] )
 		{
 			num++;
 		}
 		file.close();
 	}
    
 	return num;
}

/**********************************************************
 * Funcion MostrarVector
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * v		      E       vector del cual se mostraran los valores
 * num         E       numero de elementos del vector (v)
 *
 * Valor devuelto:
 * void
 ***********************************************************/

void MostrarVector (Vector v, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << " " << v[i] ;
	}
	cout << endl;
	return;
}

/**********************************************************
 * Funcion GurdarVector
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * v           E      Vector a guardar
 * num         E      Numero de elementos del vector
 * nombre      E      String con el nombre del archivo a guardar
 *
 * Valor devuelto:
 * void
 ***********************************************************/

void GuardarVector (Vector v, int num, string nombre)
{
 	ofstream f;
 	if (Nombrecon_BIN(nombre) == false)
 		nombre += ".bin";
 	f.open( nombre.c_str(), ios::binary);
 	if(!f)
 		cout << "Error abriendo el fichero" << endl;
 	else
 	{
 		for(int i = 0; i < num; i++)
 			f.write((char *)(& v[i]), sizeof(v[i]) );
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
 * nombre	  E        Un string para ver si contiene txt  o no
 *
 * Valor devuelto:
 *  Un booleano con true si tiene ".txt" el string,
 * o false si no lo contiene
 ***********************************************************/

bool Nombrecon_TXT (string nombre)
{
 	bool contiene_txt = false;
 	string txt = ".txt";
 	unsigned long x;
    
 	x = nombre.find( txt );
 	if (x > 0 && x < nombre.length())
 		contiene_txt = true;
 	else
 		contiene_txt = false;
    
 	return contiene_txt;
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

/**********************************************************
 * Funcion EliminarRepetidos
 *
 * Parametros:
 * Nombre	 E/S 	   Descripcion
 * ------	 ---	 ---------------
 * vec         E       vector para eliminar elementos repetidos
 * num 	      E       numero de elementos de vec
 * vec2        S       copia de vec sin elementos repetidos
 *
 * Valor devuelto:
 * Devuelve el numero de elementos del vec2.
 ***********************************************************/

int EliminarRepetidos (Vector vec, int num, Vector vec2)
{
    
	int k = 0;
	int num_ind_vec = 0;
	int num_ind_vec2 = 0;
    
	for (int j = 0; j < num; ++j)
	{
		for (int i = 0; i < num; ++i)
		{
			if (vec[i] == k)
			{
				k++;
			}
		}
	}
    
    /*****************************************************************************/
    
	while (num_ind_vec < num)
	{
		for (int i = 0; i < num; ++i)
		{
			if ( ((vec[i]) == (vec[num_ind_vec])) && (i != num_ind_vec) )
			{
				vec[num_ind_vec] = k;
			}
		}
		num_ind_vec++;
	}
    
    /*****************************************************************************/
    
	for (int i = 0; i < num; ++i)
	{
		if (vec[i] != k)
		{
			vec2[num_ind_vec2] = vec[i];
			num_ind_vec2++;
		}
	}
    
	return  num_ind_vec2;
}