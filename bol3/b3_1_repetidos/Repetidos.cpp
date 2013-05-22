/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  Repetidos.cpp                                */
/*                                                           */
/*  PROPÓSITO:  El programa Repetidos lee un vector y ,      */
/*              lo muestra sin los parametros repetidos      */
/*                                                           */
/*************************************************************/

#include <iostream>

using namespace std;

typedef int Vector[50];

int LeerVector ( Vector vec);
void MostrarVector ( Vector vec, int num);
int EliminarRepetidos (Vector vec, int num, Vector vec2);

int main (void)
{
    Vector v, w;
    int num, num2;

    cout << "Dame el vector: ";
    num = LeerVector (v);
    
    cout << "El vector introducido es: ";
    MostrarVector (v, num);
        
    num2 = EliminarRepetidos (v, num, w);
    
    cout << "El vector sin elementos repetidos es: ";
    MostrarVector (w, num2);
    
    // system ("PAUSE");
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

    for (int j = 0; j < num_elementos; ++j)
    {
        cout << "Dame numero para el valor : " << j << " -->";
        cin >> vec[j];
    }
    return num_elementos;
}

/*
 * La funcion MostrarVector, muestra los valores del vector separados por
 * comas y espacios.
 *
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
    
    return ;
}

/*
 * La funcion EliminarRepetidos esta dividido en tres bloques:
 * 
 * El primer bloque busca un numero que no aparezca en la funcion y lo iguala
 *  a ( k )
 *  
 * El segundo bloque sustituye todos los elementos repetidos por ( k )
 *
 * El tercer bloque iguala todos los valores del vector, ( vec ) en el ( vec2 )
 * sin contar con los valores de vec que sean iguales a ( k )
 */

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






// int num_ind_vec = 0;

//     while (num_ind_vec < num)
//     {
//         for (int i = 0; i < num; ++i)
//         {
//             if ( ((vec[i]) == (vec[num_ind_vec])) && (i != num_ind_vec) )
//             {
//                 vec[num_ind_vec] = -1;
//             }
//         }
//         num_ind_vec++;
//     }
//     





    // do
    // {
    //     y = 0;
    //     k = 0;

    //     for (int j = 0; j < 100; ++j)
    //     {
    //         for (int i = 0; i < num; ++i)
    //         {
    //             if (vec[i] == k)
    //             {
    //                 k++;
    //             }
    //         }
    //     }
    // 