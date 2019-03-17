#include "pch.h"
#include <iostream>
#include "Shape.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include <list>

using namespace std;

/*
No estoy del todo convencido de la practicidad del codigo logrado hasta el día de la fecha 17/03/2019 por las siguientes razones:

1-Como simplificar en un solo proceso, las listas e iteradores de calse, en una sola lista y un solo iterador de formas??

2-El codigo en sí no cumple con la rutina de imprimir todas las figuras creadas por el usuario. Imprime la cantidad de figuras creadas..

e imprime las figuras pero con las medidas tomadas por la ultima creada.
*/


//lista de Rectangulos
list<Rectangulo*> rectangulos;

//iterador de lista
list<Rectangulo*>::iterator itRect;

//lista de Triangulos
list<Triangulo*> triangulos;

//iterador de lista
list<Triangulo*>::iterator itTri;

int _width, _height;

void mostrarRectangulos();

void mostrarTriangulos();

int main() 
{
	
	int fig;

	int run;

	cout << "Ingrese 1 para crear figuras o 0 para terminar el programa: " << endl;

	cin >> run;

	while (run > 0)
	{

			cout << "Ingrese 1 para crear un Rectangulo y 2 para crer un Triangulo" << endl;

		cin >> fig;

		if (fig == 1)
		{
			
			cout << "Ingrese el ancho: " << endl;

			cin >> _width;

			cout << "Ingrese el Largo: " << endl;

			cin >> _height;

			rectangulos.push_back(new Rectangulo);

		}
		else if (fig == 2) {

			cout << "Ingrese la altura del triangulo: " << endl;

			cin >> _height;

			triangulos.push_back(new Triangulo);

		}

		cout << "Desea seguir creando figuras?" << endl;

		cout << "Ingrese 1 para seguir creando figuras o 0 para terminar el programa: " << endl;

		cin >> run;

	}

	mostrarRectangulos();

	cout << "Cantidad de Rectangulos creados: " << rectangulos.size(); cout << endl;

	mostrarTriangulos();

	cout << "Cantidad de Triangulos creados: " << triangulos.size(); cout << endl;
}



void mostrarRectangulos()
{
	for (itRect = rectangulos.begin();itRect!= rectangulos.end(); itRect++)
	{
		  
		(*itRect)->Draw(_width, _height); cout << endl;

	}
	cout << '\n';
}

void mostrarTriangulos()
{
	for (itTri = triangulos.begin(); itTri != triangulos.end(); itTri++)
	{

		(*itTri)->Draw(_height); cout << endl;

	}
	cout << '\n';
}
