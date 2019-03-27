#include "pch.h"
#include <iostream>
#include "Shape.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include <list>

using namespace std;
	
int main() 
{

	list<Shape*> figuras;

	list<Shape*>::iterator itFig;
	
	Shape *figura = new Shape();

	int _width, _height;

	int fig;

	int run = 1;

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

			figura = new Rectangulo(_width, _height);

			figuras.push_back(figura);
		}
		else if (fig == 2) {

			cout << "Ingrese la altura del triangulo: " << endl;

			cin >> _height;

			figura = new Triangulo(_height);

			figuras.push_back(figura);
		}

		cout << "Desea seguir creando figuras? 1/SI  0/NO"  << endl;

		cin >> run;

	}

	for (itFig = figuras.begin(); itFig != figuras.end(); ++itFig) {

		(*itFig)->Draw(); cout << endl;

	}

	cout << "Cantidad de figuras creadaas: " << figuras.size(); cout << endl;

}

