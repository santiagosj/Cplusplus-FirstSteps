#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Shape.h"

class Rectangulo: public Shape
{
public:
	//constructor
	Rectangulo(int, int);

   ~Rectangulo();

   //protoripo
   
   void Draw();

private:
	int width;
	int height;
};

#endif // !RECTANGULO_H