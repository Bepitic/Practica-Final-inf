/*************************************************************/
/*      AUTOR: Francisco Amoros Cubells                      */
/*      CURSO: Primero, Ingenieria industrial                */
/*     NOMBRE:  b2_4_dias_Paco_Amoros_Cubells.cpp            */
/*                                                           */
/*  PROPÓSITO:  Que hace el programa                         */
/*                                                           */
/*************************************************************/



#include <iostream>
using namespace std;

bool A_bisiesto(int anyo);
int PideNumero ( int max, int min);

const int num_dia_max = 31;
const int num_mes_max = 12;
const int num_min = 1;

int main(void)
{
    int num_dia, num_mes, num_anyo, num_dia_sem;
    int num_anyo_copia;
    int num_mes_copia;
    int num_anyo_sum = 1583;
    bool anyo_bis;
    
    num_dia_sem = 0;
    cout << "Hola, este es un programa para saber en que dia de la semana cae una determinada fecha correcta" << endl;
    cout << "Introduce una fecha correcta." << endl;
    cout << "Introduce un dia : " << endl;
    num_dia = PideNumero(num_dia_max, num_min);
    cout << "Introduce un mes : " << endl;
    num_mes = PideNumero(num_mes_max, num_min);
    cout << "Introduce un anyo : " << endl;
    cin >> num_anyo;
    anyo_bis = A_bisiesto(num_anyo);
    num_anyo_copia = num_anyo;
    num_mes_copia = 1;
    while ( num_anyo_sum !=  num_anyo_copia  )
    {
        if ( A_bisiesto(num_anyo_sum) == true )
        {
            num_dia_sem += 2;
            //            aqui antes 2
        }
        
        else
        {
            num_dia_sem++;
        }
        
        num_anyo_sum++;
    }
    while (num_mes_copia != num_mes)
    {
        if (num_mes_copia == 4 || num_mes_copia == 6 || num_mes_copia == 9 || num_mes_copia == 11 )
        {
            num_dia_sem += 30;
        }
        if ( num_mes_copia == 1 || num_mes_copia == 3 || num_mes_copia == 5 || num_mes_copia == 7 || num_mes_copia == 8 || num_mes_copia == 10 || num_mes_copia == 12 )
        {
            num_dia_sem += 31;
        }
        if (num_mes_copia == 2 && ( A_bisiesto(num_anyo) == true ) )
        {
            num_dia_sem += 29;
        }
        if (num_mes_copia == 2 && ( A_bisiesto(num_anyo) == false ) )
        {
            num_dia_sem += 28;
        }
        num_mes_copia++;
    }
    num_dia_sem += num_dia;
    while (num_dia_sem > 7)
    {
        num_dia_sem -= 7;
    }
    switch (num_dia_sem)
    {
        case 1:
            cout << " Sabado " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
            break;
            
        case 2:
            cout << " Domingo " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
            break;
            
        case 3:
            cout << " Lunes " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
            break;
            
        case 4:
            cout << " Martes " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
            break;
            
        case 5:
            cout << " Miercoles " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
            break;
            
        case 6:
            cout << " Jueves " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
            break;
            
        case 7:
            cout << " Viernes " << num_dia << " / " << num_mes << " / " << num_anyo << endl;
            break;
            
        default:
            break;
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
