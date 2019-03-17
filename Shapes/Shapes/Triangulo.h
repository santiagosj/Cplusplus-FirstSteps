#pragma once
#include "Shape.h"


class Triangulo : public Shape
{
public:
	Triangulo();
	~Triangulo();

	void Draw(int _altura);
private:
	int altura;
};

