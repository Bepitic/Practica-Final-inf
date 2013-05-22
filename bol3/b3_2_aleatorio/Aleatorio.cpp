/*************************************************************/ 
/*      AUTOR: Francisco Amoros Cubells                      */ 
/*      CURSO: Primero, Ingenieria Informatica               */ 
/*     NOMBRE:  Aleatorio.cpp                                */ 
/*                                                           */ 
/*  PROPÓSITO:  Pedir al usuario el numero de elementos que  */ 
/*              va a tener un vector y dar un vector con     */ 
/*              el tamanyo descrito antes , y los rellena    */ 
/*              con numeros aleatorios                       */ 
/*                                                           */ 
/*************************************************************/

#include <iostream>
using namespace std;

#include <stdlib.h>
#include <time.h>

typedef int Vector[100];

int LeerVector ( Vector vec);
void MostrarVector ( Vector vec, int num);
void ModificarRepetidos (Vector vec, int num);
void CompletarRepetidos (Vector vec, int num);

int main(void)
{
	Vector vec;
	int num;

    cout << "Hola, este programa pide un numero, y rellena un vector del tamanyo del numero introducido, con numeros aleatorios sin repeticion";
    
    num = LeerVector ( vec );
    
    MostrarVector (vec, num);
    ModificarRepetidos (vec, num);
    CompletarRepetidos (vec, num);
    MostrarVector (vec, num);

    return 0;
}

/*
 * La funcion LeerVector pide el numero de elementos
 * que va a tener el Vector y los introduce en una variable
 */

 int LeerVector ( Vector vec)
 {
 	int num_elementos;
 	cout << " \nDime numero de elementos : ";
 	cin >> num_elementos;

 	srand(time(NULL));

 	for (int j = 0; j < num_elementos; ++j)
 	{
 		vec[j] = rand()%num_elementos;
 	}
 	return num_elementos;
 }


/*
 * La funcion MostrarVector, muestra los valores del vector separados por
 * comas y espacios.
 */

 void MostrarVector ( Vector vec, int num)
 {
 	if ( num == 1)
 	{
 		cout << vec[0] << endl;
 	}

 	if ( num == 2)
 	{
 		cout << vec[0] << ", " << vec[1] << endl;
 	}

 	if ( num > 2 )
 	{
 		num--;
 		for (int i = 0; i < num; ++i)
 		{
 			cout << vec[i] << ", ";
 		}
 		num++;
 		cout << vec[ (num - 1) ] << endl;
 	}

 	return;
 }

/*
 * La Funcion ModificarRepetidos elimina los valores repetidos 
 * igualandolos a '-1'
 *
 */

 void ModificarRepetidos (Vector vec, int num)
 {
 	int num_ind_vec = 0;

 	while (num_ind_vec < num)
 	{
 		for (int i = 0; i < num; ++i)
 		{
 			if ( ((vec[i]) == (vec[num_ind_vec])) && (i != num_ind_vec) )
 			{
 				vec[num_ind_vec] = -1;
 			}
 		}
 		num_ind_vec++;
 	}

 	return ;
 }

/*
 * La funcion CompletarRepetidos se divide en dos partes, la primera se encarga de buscar valores
 * que no se encuentren en el vector, y la segunda parte se encarga de buscar los  valores '-1'
 * dentro de la funcion y sustituirlos por los valores antes encontrados en la primera parte de la funcion.
 *
 */

 void CompletarRepetidos (Vector vec, int num)
 {
 	int y, k, x = -1;
 	bool proceso_completado ;

 	do
 	{
        y = 0;
        k = 0;
        proceso_completado = true;
        
        for (int j = 0; j < 100; ++j)
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


        while ( y < num)
        {
            if (vec[y] == x)
            {
                vec[y] = k;
                y=num;
                proceso_completado = false;
                k++;
            }
            y++;
        }
        
    }while (proceso_completado != true);

    return;
    
}
