//
// para calcular los dos puntos mas alejados entre si tenemos que sacar el modulo del vector que tienen los dos puntos 
//  (x,y,z)
// A(1,1,1)
// B(2,3,4)
// 
//  modulo del vector raiz  √ ->( (xB-xA)*(xB-xA)+(yB-yA)*(yB-yA)+(zB-zA)*(zB-zA)  )
//  

#include <iostream>
#include <math.h>
using namespace std;

const int MAX = 20;

struct Punto
{
	float x;
	float y;
	float z;
};
typedef Punto VPuntos[MAX];


Punto IntroducirPunto ();
void MostrarPunto( Punto );
void PuntoMasAlejado(const VPuntos p, int num);


int main(void)
{
	int num_puntos;
	VPuntos puntos;

	cout << " Este programa, muestra los puntos introducidos y calcula cuales son \n los dos puntos mas alejados entre si.";
	cout << "\n Cuantos puntos quieres Introducir? \n";
	cin >> num_puntos;

	for (int i = 0; i < num_puntos; ++i)
	{
		cout << "Introduce el punto " << i << endl;
		puntos[i] = IntroducirPunto();
	}

	for (int i = 0; i < num_puntos; ++i)
	{
		cout << "En el punto " << i << " : ";
		MostrarPunto( puntos[i] );
		cout << endl;
	}
	PuntoMasAlejado( puntos, num_puntos );







	return 0;
}



Punto IntroducirPunto ()
{
	Punto p;

	cout << "Dame el valor para x: ";
	cin >> p.x;
	cout << "Dame el valor para y: ";
	cin >> p.y;
	cout << "Dame el valor para z: ";
	cin >> p.z;

	return p;
}


void MostrarPunto( Punto p )
{
	cout << " (" << " " << p.x << ", " << p.y << ", " << p.z << " )";
	return;
}



void PuntoMasAlejado(const VPuntos p, int num)
{
	float mayor = 0, res;
	int p_a = 0, p_b = 0;

	for (int j = 0; j < num; ++j)
	{
		for (int i = 0; i < num; ++i)
		{
			if (i != j && i < j)
			{
				res = sqrt( ( p[i].x - p[j].x )*( p[i].x - p[j].x )+( p[i].y - p[j].y )*( p[i].y - p[j].y )+( p[i].z - p[j].z )*( p[i].z - p[j].z ) );

				if (res > mayor)
				{
					mayor = res;
					p_a = i;
					p_b	= j;	
				}
			}
		}
	}

    //  modulo del vector raiz  √ ->( (xB-xA)*(xB-xA)+(yB-yA)*(yB-yA)+(zB-zA)*(zB-zA)  )

	cout << " Los puntos más alejados entre si son el punto " << p_a << " y el punto " << p_b << " . " << endl;

}