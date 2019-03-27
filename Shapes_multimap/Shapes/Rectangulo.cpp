#include "pch.h"
#include "Rectangulo.h"
#include <iostream>

using namespace std;

Rectangulo::Rectangulo(int _width, int _height):Shape()
{
	width = _width;
	height = _height;
}

Rectangulo::~Rectangulo()
{
}


void Rectangulo::Draw()
{
	cout << "esto es un Rectangulo..." << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << " * ";
		}
		cout << endl;

	}

}