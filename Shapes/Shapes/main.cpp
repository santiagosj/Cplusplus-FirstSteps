#include "pch.h"
#include <iostream>
#include "Shape.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include <list>

using namespace std;

//lista de figuras
list<Shape*> figuras;

//iterador de lista
list<Shape*>::iterator itFig;

int _width, _height;

int fig;

void mostrarFiguras();

int main() 
{
	
	

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

			Shape *rectangulo = new Rectangulo(_width, _height);

			figuras.push_back(rectangulo);
		}
		else if (fig == 2) {

			cout << "Ingrese la altura del triangulo: " << endl;

			cin >> _height;

			Shape *triangulo = new Triangulo(_height);

			figuras.push_back(triangulo);
		}

		cout << "Desea seguir creando figuras?" << endl;

		cout << "Ingrese 1 para seguir creando figuras o 0 para terminar el programa: " << endl;

		cin >> run;

	}

	mostrarFiguras();

	cout << "Cantidad de figuras creadaas: " << figuras.size(); cout << endl;

}


void mostrarFiguras()
{
	for(itFig = figuras.begin(); itFig != figuras.end(); itFig++) {

		(*itFig)->Draw(); cout << endl;

	}
}
