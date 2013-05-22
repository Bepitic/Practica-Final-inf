/*************************************************************/ 
/*      AUTOR: Francisco Amoros Cubells						 */ 
/*      CURSO: Primero, Ingenieria Informatica               */ 
/*     NOMBRE:  Palindroma.cpp								 */ 
/*                                                           */ 
/*  PROPÓSITO:  Comprueba si una frase es palindroma o no.	 */ 
/*                                                           */ 
/*************************************************************/



#include <iostream>
#include <string>
using namespace std;

bool EsPalindroma (string);

int main (void)
{
	string s;
	cout << "Dame frase a comprobar: ";
	getline (cin, s);
	if (EsPalindroma (s) )
		cout << "La frase es palindroma.\n";
	else
		cout << "La frase NO es palindroma.\n";
	return 0;
}

bool EsPalindroma (string frase)
{
	int j;
	char c;
	bool es_palindroma;
	string frase2, frase1;
    
	for (int i = 0; i < frase.length(); ++i)
	{
		c = frase[i];
		if ( c == char(160) || c == char(181) )
		{
			frase[i] = 'a';
		}
		if ( c == char(130) || c == char(144) )
		{
			frase[i] = 'e';
		}
		if ( c == char(161) || c == char(214) )
		{
			frase[i] = 'i';
		}
		if ( c == char(162) || c == char(224) )
		{
			frase[i] = 'o';
		}
		if ( c == char(163) || c == char(233) )
		{
			frase[i] = 'u';
		}
		if ( c == char(164) || c == char(165) )
		{
			frase[i] = 'n';
		}
	}
    
	for (int i = 0; i < frase.length(); ++i)
	{
        frase[i] = tolower(frase[i]);
	}
    
	for (int i = 0; i < frase.length(); ++i)
	{
        c = frase[i];
        if ( c == ',' || c == '.' || c == ' ' )
        {
        }
        else
        {
        	frase1 += c;
        }
	}
    
    j = frase1.length();
    j--;
	for (j ;  j >= 0; --j)
	{
		frase2 += frase1[j]; 
	}
    
	if (frase1 == frase2)
    {
        es_palindroma = true;
    }
    else
    {
        es_palindroma = false;
    }

	return es_palindroma;
}
