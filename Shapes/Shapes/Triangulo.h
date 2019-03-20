#pragma once
#include "Shape.h"


class Triangulo : public Shape
{
public:
	Triangulo(int);
	~Triangulo();

	void Draw();
private:
	int altura;
};

