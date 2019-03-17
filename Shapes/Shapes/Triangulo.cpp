#include "pch.h"
#include "Triangulo.h"
#include <iostream>


using namespace std;


Triangulo::Triangulo() :Shape()
{
}

Triangulo::~Triangulo()
{
}

void Triangulo::Draw(int _altura)
{
	cout << "Esto es un Triangulo..." << endl;

	for (int i = 1; i <= _altura; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << "* ";
		}
		cout << "\n";
	}
}

