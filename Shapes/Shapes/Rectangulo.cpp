#include "pch.h"
#include "Rectangulo.h"
#include <iostream>

using namespace std;

Rectangulo::Rectangulo():Shape()
{
}

Rectangulo::~Rectangulo()
{
}


void Rectangulo::Draw(int _width, int _height)
{
    
	cout << "esto es un Rectangulo..." << endl;

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			cout << " * ";
		}
		cout << endl;

	}

}