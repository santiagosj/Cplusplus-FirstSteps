#ifndef TRIANGULO_H

#define TRIANGULO_H

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

#endif // !TRIANGULO_H