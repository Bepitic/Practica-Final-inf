/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria Informatica               */
/*     NOMBRE:  b2_3_fechas_Paco_Amoros_Cubells.cpp          */
/*                                                           */
/*  PROPÓSITO:  Pide una fecha y muestra si es correcta      */
/*              o no                                         */
/*                                                           */
/*************************************************************/



#include <iostream>
using namespace std;

bool A_bisiesto(int anyo);
int PideNumero ( int max, int min);

// 'const int NUM_DIA_MAX' , es el numero maximo de dias que tiene un mes.
// 'const int NUM_MES_MAX', es el numero maximo de meses que tiene un anyo.
// 'const int NUM_MIN' , es el numero minimo de dias o meses.

const int NUM_DIA_MAX = 31;
const int NUM_MES_MAX = 12;
const int NUM_MIN = 1;

int main(void)
{
    int num_dia, num_mes, num_anyo;
    bool anyo_bis;
    
    cout << "Hola, este es un programa para saber si una determiniada fecha es correcta." << endl;
    cout << "Introduce un dia : " << endl;
    num_dia = PideNumero(NUM_DIA_MAX, NUM_MIN);
    cout << "Introduce un mes : " << endl;
    num_mes = PideNumero(NUM_MES_MAX, NUM_MIN);
    cout << "Introduce un anyo : " << endl;
    cin >> num_anyo;
    anyo_bis = A_bisiesto(num_anyo);
    
    
    // Este 'if' compara si los meses, que solo pueden tener 30 dias no tenga como el numero de dia el 31.
    // o si el anyo es bisiesto, en el mes de febrero, el dia no sea 30 o 31.
    // o si el anyo no es bisiesto, en el mes de febrero, el dia no sea 29, 30 o 31.
    
    if ( ( ( num_mes == 4 || num_mes == 6 || num_mes == 9 || num_mes == 11 ) && ( num_dia == 31 ) ) || ( num_mes == 2 && anyo_bis == true && ( num_dia == 31 || num_dia == 30 ) ) || ( num_mes == 2 && anyo_bis == false && ( num_dia == 31 || num_dia == 30 || num_dia == 29 ) ) || ( 0 > num_anyo ) )
    {
        cout << " La fecha introducida : " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
        cout << " Es incorrecta. " << endl;
    }
    
    else
    {
        cout << " La fecha introducida : " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
        cout << " Es correcta." << endl;
    }
    return 0;
}

/*
 * La funcion A_bisiesto.
 * Calcula si el anyo es bisiesto o no.
 *
 */

bool A_bisiesto(int anyo)
{
    bool an_bis;
    
    if (anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0 ))
    {
        an_bis = true;
    }
    
    else
    {
        an_bis = false;
    }
    
    return an_bis;
}

/*
 * Funcion ( PideNumero ) pide un numero entre
 * los limites establecidos y lo saca como retorno.
 */

int PideNumero ( int max, int min)
{
    bool limites;
    int num;
    
    do
    {
        cout << "[Entre " <<  min << " y " << max << " incluidos] :"<< endl;
        cin >> num ;
        if (max>= num && min <=num)
        {
            limites = true;
        }
        else
        {
            limites = false;
            cout << " --> ERROR: Fuera del rango [ " << max << ","<< min << " ] " << endl;
        }
    }
    while (limites != true);
    
    return num;
}
