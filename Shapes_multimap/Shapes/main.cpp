#include "pch.h"
#include <iostream>
#include <map>
#include "Shape.h"
#include "Rectangulo.h"
#include "Triangulo.h"


using namespace std;


int main() 
{
	multimap<Shape*, int> figMap;

	multimap<Shape*, int>::iterator itMap;

	int run = 1;

	int _width = 10, _height = 5;

	Shape *figura = new Shape;

	while (run > 0)
	{
		int fig;

		cout << "Ingresa 1 para crear un rectangulo o 2 para crear un triangulo." << endl;

		cin >> fig;

		switch (fig) {

		case 1:

			figura = new Rectangulo(_width, _height);

			figMap.insert(pair<Shape*, int>(figura, 1 ));

			break;
		case 2:

			figura = new Triangulo(_height);

			figMap.insert(pair<Shape*, int>(figura, 2));

			break;
		}


		cout << "Desea seguir creando figuras? si/1 no/0" << endl;

		cin >> run;

	}

	for (itMap = figMap.begin(); itMap != figMap.end(); ++itMap) {

		itMap->first->Draw();

	}
	
	delete figura;

}
