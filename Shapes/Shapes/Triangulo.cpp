#include "pch.h"
#include "Triangulo.h"
#include <iostream>


using namespace std;


Triangulo::Triangulo(int _altura) :Shape()
{
	altura = _altura;
}

Triangulo::~Triangulo()
{
}

void Triangulo::Draw()
{
	cout << "Esto es un Triangulo..." << endl;

	for (int i = 1; i <= altura; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << "* ";
		}
		cout << "\n";
	}
}

